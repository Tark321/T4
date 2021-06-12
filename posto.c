#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posto.h"

typedef struct c{
    Ponto ponto;
    double x;
    double y;
    double distancia; 

}PostoStruct;

Posto criaPosto(double x, double y, double distancia)
{
    PostoStruct* posto = (PostoStruct*) malloc(sizeof(PostoStruct));
    posto->ponto = criaPonto(x, y);
    posto->x = x;
    posto->y = y;
    posto->distancia = distancia;

    return posto;
}

void copiarNo(Posto posto1, Posto posto2)
{
    PostoStruct* p1 = (PostoStruct*) posto1;
    PostoStruct* p2 = (PostoStruct*) posto2;

    *p1 = *p2;
}

Ponto getPostoPonto(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->ponto;
}

double getPostoX(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->x;
}

double getPostoY(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->y;
}

double getPostoDistancia(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->distancia;
}

void setPostoPonto(Posto posto, Ponto p)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->ponto = p;
}

void setPostoX(Posto posto, double x)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->x = x;
}

void setPostoY(Posto posto, double y)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->y = y;
}

void setPostoDistancia(Posto posto, double distancia)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->distancia = distancia;
}