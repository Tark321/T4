#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"


typedef struct h{

    char id[20];
    double x;
    double y;
    Ponto ponto;
    char sw[20];
    char cfill[20];
    char cstrk[20];

}SemaforoStruct;

Semaforo criaSemaforo(char id[], double x, double y, char sw[], char cfill[], char cstrk[])
{
    SemaforoStruct* semaforo = (SemaforoStruct*) malloc(sizeof(SemaforoStruct));

    strcpy(semaforo->id, id);
    semaforo->ponto = criaPonto(x, y);
    semaforo->x = x;
    semaforo->y = y;
    strcpy(semaforo->sw, sw);
    strcpy(semaforo->cfill, cfill);
    strcpy(semaforo->cstrk, cstrk);
    
    return semaforo;
}

char* getSemaforoId(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->id;
}

double getSemaforoX(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->x;
}

double getSemaforoY(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->y;
}

char* getSemaforoSw(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->sw;
}

char* getSemaforoCfill(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->cfill;
}

char* getSemaforoCstrk(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->cstrk;
}

Ponto getSemaforoPonto(Semaforo semaforo)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    return semaf->ponto;
}

void setSemaforoId(Semaforo semaforo, char id[])
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    strcpy(semaf->id, id);
}

void setSemaforoX(Semaforo semaforo, double x)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    semaf->x = x;
}

void setSemaforoY(Semaforo semaforo, double y)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    semaf->y = y;
}

void setSemaforoSw(Semaforo semaforo, char sw[])
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    strcpy(semaf->sw, sw);
}

void setSemaforoCfill(Semaforo semaforo, char cfill[])
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    strcpy(semaf->cfill, cfill);
}

void setSemaforoCstrk(Semaforo semaforo, char cstrk[])
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    strcpy(semaf->cstrk, cstrk);
}

void setSemaforoPonto(Semaforo semaforo, Ponto p)
{
    SemaforoStruct* semaf = (SemaforoStruct*) semaforo;
    semaf->ponto = p;
}

void swapSemaforo(Semaforo s1, Semaforo s2)
{
    SemaforoStruct* a = (SemaforoStruct*) s1;
    SemaforoStruct* b = (SemaforoStruct*) s2;
    SemaforoStruct temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaSemaPonto(Semaforo sem)
{
    SemaforoStruct *s = (SemaforoStruct*) sem;

    free(s->ponto);
    free(s);
}
