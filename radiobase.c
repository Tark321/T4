#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radiobase.h"

typedef struct rb{

    char id[20];
    double x;
    double y;
    Ponto ponto;
    char sw[20];
    char cfill[20];
    char cstrk[20];

}RadiobaseStruct;

Radiobase criaRadiobase(char id[], double x, double y, char sw[], char cfill[], char cstrk[])
{
    RadiobaseStruct* radiobase = (RadiobaseStruct*) malloc(sizeof(RadiobaseStruct));

    strcpy(radiobase->id, id);
    radiobase->ponto = criaPonto(x, y);
    radiobase->x = x;
    radiobase->y = y;
    strcpy(radiobase->sw, sw);
    strcpy(radiobase->cfill, cfill);
    strcpy(radiobase->cstrk, cstrk);
    
    return radiobase;
}

char* getRadiobaseId(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->id;
}

double getRadiobaseX(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->x;
}

double getRadiobaseY(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->y;
}

char* getRadiobaseSw(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->sw;
}

char* getRadiobaseCfill(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->cfill;
}

char* getRadiobaseCstrk(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->cstrk;
}

Ponto getRadiobasePonto(Radiobase radiobase)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    return radiob->ponto;
}

void setRadiobaseId(Radiobase radiobase, char id[])
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    strcpy(radiob->id, id);
}

void setRadiobaseX(Radiobase radiobase, double x)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    radiob->x = x;
}

void setRadiobaseY(Radiobase radiobase, double y)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    radiob->y = y;
}

void setRadiobaseSw(Radiobase radiobase, char sw[])
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    strcpy(radiob->sw, sw);
}

void setRadiobaseCfill(Radiobase radiobase, char cfill[])
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    strcpy(radiob->cfill, cfill);
}

void setRadiobaseCstrk(Radiobase radiobase, char cstrk[])
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    strcpy(radiob->cstrk, cstrk);
}

void setRadiobasePonto(Radiobase radiobase, Ponto p)
{
    RadiobaseStruct* radiob = (RadiobaseStruct*) radiobase;
    radiob->ponto = p;
}

void swapRB(Radiobase rb1, Radiobase rb2)
{
    RadiobaseStruct* a = (RadiobaseStruct*) rb1;
    RadiobaseStruct* b = (RadiobaseStruct*) rb2;
    RadiobaseStruct temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaRBPonto(Radiobase rb)
{
    RadiobaseStruct *rB = (RadiobaseStruct*) rb;

    free(rB->ponto);
    free(rB);
}
