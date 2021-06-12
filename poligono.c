#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poligono.h"

typedef struct p
{
    double* x;
    double* y;
    char cor[22];
    int tamanho;

}PoligonoStruct;

Poligono criaPoligono(char cor[], int tamanho)
{
    PoligonoStruct* poli = (PoligonoStruct*) malloc(sizeof(PoligonoStruct));

    poli->x = (double*)malloc(sizeof(double)*tamanho);
    poli->y = (double*)malloc(sizeof(double)*tamanho);
    strcpy(poli->cor, cor);
    poli->tamanho = tamanho;

    return poli;
}

double getPoligonoX(Poligono poli, int index)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    return p->x[index];
}

double getPoligonoY(Poligono poli, int index)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    return p->y[index];
}

char* getPoligonoCor(Poligono poli)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    return p->cor;
}

int getPoligonoTamanho(Poligono poli)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    return p->tamanho;
}

void setPoligonoX(Poligono poli, double x, int index)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    p->x[index] = x;
}

void setPoligonoY(Poligono poli, double y, int index)
{
    PoligonoStruct* p = (PoligonoStruct*) poli;
    p->y[index] = y;
}

