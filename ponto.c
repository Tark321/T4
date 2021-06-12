#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"


typedef struct p
{
    double x;
    double y;

}pointStruct;

Ponto criaPonto(double x, double y)
{
    pointStruct *ponto = (pointStruct*) malloc(sizeof(pointStruct));
    ponto->x = x;
    ponto->y = y;

    return ponto;
}

double getPontoX(Ponto ponto)
{
    pointStruct *p = (pointStruct*) ponto;
    return p->x;
}

double getPontoY(Ponto ponto)
{
    pointStruct *p = (pointStruct*) ponto;
    return p->y;
}

void setPontoX(Ponto ponto, double x)
{
    pointStruct *p = (pointStruct*) ponto;
    p->x = x;
}

void setPontoY(Ponto ponto, double y)
{
    pointStruct *p = (pointStruct*) ponto;\
    p->y = y;
}

void swapPonto(Ponto p1, Ponto p2)
{
    pointStruct *a = (pointStruct*) p1;
    pointStruct *b = (pointStruct*) p2;
    pointStruct temp = *a;
    *a = *b;
    *b = temp;
}