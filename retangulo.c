#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct r{

    char i[20];
    double w;
    double h;
    double x;
    double y;
    Ponto ponto;
    char expessura[20];
    char corb[20];
    char corp[20];

}RetanguloStruct;

Retangulo criaRetangulo(char i[], double w, double h, double x, double y, char expessura[], char corb[], char corp[])
{
    RetanguloStruct* retangulo = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));

    strcpy(retangulo->i, i);
    retangulo->ponto = criaPonto(x, y);
    retangulo->x = x;
    retangulo->y = y;
    retangulo->w = w;
    retangulo->h = h;
    strcpy(retangulo->expessura, expessura);
    strcpy(retangulo->corb, corb);
    strcpy(retangulo->corp, corp);

    return retangulo;
}

char* getRetanguloI(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->i;
}

double getRetanguloW(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->w;
}

double getRetanguloH(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->h;
}

double getRetanguloX(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->x;
}

double getRetanguloY(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->y;
}

char* getRetanguloSw(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->expessura;
}

char* getRetanguloCorb(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->corb;
}

char* getRetanguloCorp(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->corp;
}

Ponto getRetanguloPonto(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->ponto;
}

void setRetanguloI(Retangulo retangulo, char i[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->i, i);
}

void setRetanguloW(Retangulo retangulo, double w)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->w = w;
}

void setRetanguloH(Retangulo retangulo, double h)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->h = h;
}

void setRetanguloX(Retangulo retangulo, double x)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->x = x;
}

void setRetanguloY(Retangulo retangulo, double y)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->y = y;
}

void setRetanguloSw(Retangulo retangulo, char sw[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->expessura, sw);
}

void setRetanguloCorb(Retangulo retangulo, char corb[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->corb, corb);
}

void setRetanguloCorp(Retangulo retangulo, char corp[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->corp, corp);
}

void setRetanguloPonto(Retangulo retangulo, Ponto p)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->ponto = p;
}

void swapRetangulo(Retangulo r1, Retangulo r2)
{
    RetanguloStruct* a = (RetanguloStruct*) r1;
    RetanguloStruct* b = (RetanguloStruct*) r2;
    RetanguloStruct temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaRetangPonto(Retangulo retang)
{
    RetanguloStruct *r = (RetanguloStruct*) retang;

    free(r->ponto);
    free(r);
}