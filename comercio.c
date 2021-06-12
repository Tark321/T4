#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comercio.h"

typedef struct comercio
{
    Ponto ponto;
    char cnpj[20];
    char cpf[10];
    char cep[20];
    char face[2];
    char codt[20];
    char nome[30];
    double num;
}StructComercio;

Comercio criaComercio(Quadra q, char cnpj[], char cpf[], char face[], char codt[], char nome[], double num)
{
    StructComercio* c = (StructComercio*) malloc(sizeof(StructComercio));
    double x = getPontoX(getQuadraPonto(q));
    double y = getPontoY(getQuadraPonto(q));
    double h = getQuadraH(q);
    double w = getQuadraW(q);

    if(strcmp(face, "n") == 0)
    {
        x = x + num;
        y = y + h;
    }
    else if(strcmp(face, "s") == 0)
    {
        x = x + num;
    }
    else if(strcmp(face, "l") == 0)
    {
        y = y + num;
    }
    else if(strcmp(face, "o") == 0)
    {
        x = x + w;
        y = y + num;
    }

    strcpy(c->cnpj, cnpj);
    strcpy(c->cpf, cpf);
    strcpy(c->cep, getQuadraCep(q));
    strcpy(c->codt, codt);
    strcpy(c->nome, nome);
    strcpy(c->face, face);
    c->ponto = criaPonto(x, y);
    c->num = num;

    return c;

}

char* getComercioCnpj(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->cnpj;
}

char* getComercioCpf(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->cpf;
}

char* getComercioCep(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->cep;
}
char* getComercioFace(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->face;
}
char* getComercioCodt(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->codt;
}
char* getComercioNome(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->nome;
}
Ponto getComercioPonto(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->ponto;
}

double getComercioNum(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    return c->num;
}

void swapComercio(Comercio c1, Comercio c2)
{
    StructComercio* a = (StructComercio*) c1;
    StructComercio* b = (StructComercio*) c2;
    StructComercio temp = *a; 
    *a = *b;
    *b = temp;
}

void desalocaComercio(Comercio comercio)
{
    StructComercio* c = (StructComercio*) comercio;
    free(c->ponto);
    free(c);
}
