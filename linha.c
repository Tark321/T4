#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linha.h"

typedef struct l{

    double x1;
    double y1;
    double x2;
    double y2; 
    char cor[20];

}LinhaStruct;

Linha criaLinha(double x1, double y1, double x2, double y2, char cor[20])
{
    LinhaStruct* linha = (LinhaStruct*) malloc(sizeof(LinhaStruct));

    linha->x1 = x1;
    linha->x2 = x2;
    linha->y1 = y1;
    linha->y2 = y2;
    strcpy(linha->cor, cor);

    return linha;
}

double getLinhaX1(Linha linha)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->x1;
}

double getLinhaX2(Linha linha)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->x2;
}

double getLinhaY1(Linha linha)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->y1;
}

double getLinhaY2(Linha linha)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->y2;
}

char* getLinhaCor(Linha linha)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    return lin->cor;
}

void setLinhaX1(Linha linha, double x1)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->x1 = x1;
}

void setLinhaX2(Linha linha, double x2)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->x2 = x2;
}

void setLinhaY1(Linha linha, double y1)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->y1 = y1;
}

void setLinhaY2(Linha linha, double y2)
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    lin->y2 = y2;
}

void setLinhaCor(Linha linha, char cor[])
{
    LinhaStruct* lin = (LinhaStruct*) linha;
    strcpy(lin->cor, cor);
}