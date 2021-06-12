#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"

typedef struct h{

    char id[20];
    double x;
    double y;
    Ponto ponto;
    char sw[20];
    char cfill[20];
    char cstrk[20];

}HidranteStruct;

Hidrante criaHidrante(char id[], double x, double y, char sw[], char cfill[], char cstrk[])
{
    HidranteStruct* hidrante = (HidranteStruct*) malloc(sizeof(HidranteStruct));

    strcpy(hidrante->id, id);
    hidrante->ponto = criaPonto(x, y);
    hidrante->x = x;
    hidrante->y = y;
    strcpy(hidrante->sw, sw);
    strcpy(hidrante->cfill, cfill);
    strcpy(hidrante->cstrk, cstrk);
    
    return hidrante;
}

char* getHidranteId(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->id;
}

double getHidranteX(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->x;
}

double getHidranteY(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->y;
}

char* getHidranteSw(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->sw;
}

char* getHidranteCfill(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->cfill;
}

char* getHidranteCstrk(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->cstrk;
}

Ponto getHidrantePonto(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->ponto;
}

void setHidranteId(Hidrante hidrante, char id[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->id, id);
}

void setHidranteX(Hidrante hidrante, double x)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->x = x;
}

void setHidranteY(Hidrante hidrante, double y)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->y = y;
}

void setHidranteSw(Hidrante hidrante, char sw[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->sw, sw);
}

void setHidranteCfill(Hidrante hidrante, char cfill[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->cfill, cfill);
}

void setHidranteCstrk(Hidrante hidrante, char cstrk[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->cstrk, cstrk);
}

void setHidrantePonto(Hidrante hidrante, Ponto p)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->ponto = p;
}

void swapHidrante(Hidrante h1, Hidrante h2)
{
    HidranteStruct* a = (HidranteStruct*) h1;
    HidranteStruct* b = (HidranteStruct*) h2;
    HidranteStruct temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaHidraPonto(Hidrante hid)
{
    HidranteStruct *h = (HidranteStruct*) hid;

    free(h->ponto);
    free(h);
}
