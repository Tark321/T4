#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct no{
    filaInfo info;
    struct no *prox;
}StructNo;

typedef struct Fila
{
    StructNo *firstQueue;
    StructNo *lastQueue;

}StructFila;

Fila criaFila()
{
    StructFila* f = (StructFila*) malloc(sizeof(StructFila));
    f->firstQueue = NULL;
    f->lastQueue = NULL;

    return f;
}

int filaIsEmpty(Fila fila)
{
   StructFila *f = (StructFila*) fila;
   return f->firstQueue == NULL;
}

filaInfo getInicioFila(Fila fila)
{
    StructFila *f = (StructFila*)fila;
    return f->firstQueue;
}

void insereFila(Fila fila, filaInfo info)
{
    StructFila *f = (StructFila*) fila;
    StructNo *no = (StructNo*) malloc(sizeof(StructNo));
    no->info = info;
    no->prox = NULL;

    if(f->firstQueue == NULL)
    {
        f->firstQueue = no;
        f->lastQueue = no;
    }
    else
    {
        f->lastQueue->prox = no;
    }

    f->lastQueue = no;
    
}

filaInfo retiraFila(Fila fila)
{
    StructFila *f = (StructFila*)fila;
    StructNo *aux = f->firstQueue;
    filaInfo info = aux->info;
    f->firstQueue = aux->prox;

    if(f->lastQueue == aux)
    {
        f->lastQueue = NULL;
    }

    free(aux);
    return info;
}

Fila removeFila(Fila fila)
{
    while(filaIsEmpty(fila) == 0)
    {
        retiraFila(fila);
    }

  free(fila);

    return NULL;

}