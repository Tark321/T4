#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"

typedef struct address
{
    Ponto ponto;
    char cpf[10];
    char cep[20];
    char face[2];
    char complemento[30];
    double num;
    
}StructAddress;

Address criaAddress(Quadra q, char cpf[], char face[], double num, char complemento[])
{
    StructAddress* a = (StructAddress*) malloc(sizeof(StructAddress));

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

    strcpy(a->cpf, cpf);
    strcpy(a->cep, getQuadraCep(q));
    strcpy(a->complemento, complemento);
    strcpy(a->face, face);
    a->ponto = criaPonto(x, y);
    a->num = num;

    return a;
}

char* getAddressCep(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->cep;
}

char* getAddressCpf(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->cpf;
}

char* getAddressFace(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->face;
}

char* getAddressComplemento(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->complemento;
}

Ponto getAddressPonto(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->ponto;
}

double getAddressNum(Address address)
{
    StructAddress* a = (StructAddress*) address;
    return a->num;
}

void setAddressCep(Address address, char cep[])
{
    StructAddress* a = (StructAddress*) address;
    strcpy(a->cep, cep);
}

void setAddressCpf(Address address, char cpf[])
{
    StructAddress* a = (StructAddress*) address;
    strcpy(a->cpf, cpf);
}

void setAddressFace(Address address, char face[])
{
    StructAddress* a = (StructAddress*) address;
    strcpy(a->face, face);
}

void setAddressComplemento(Address address, char complemento[])
{
    StructAddress* a = (StructAddress*) address;
    strcpy(a->complemento, complemento);
}

void setAddressPonto(Address address, Ponto ponto)
{
    StructAddress* a = (StructAddress*) address;
    a->ponto = ponto;
}

void setAddressNum(Address address, double num)
{
    StructAddress* a = (StructAddress*) address;
    a->num = num;
}

void swapAddress(Address a1, Address a2)
{
    StructAddress* a = (StructAddress*) a1;
    StructAddress* b = (StructAddress*) a2;
    StructAddress temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaAddress(Address address)
{
    StructAddress* a = (StructAddress*) address;
    free(a->ponto);
    free(a);
}