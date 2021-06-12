#ifndef __FILA_H
#define __FILA_H

typedef void *Fila;
typedef void *filaInfo;

Fila criaFila();

int filaIsEmpty(Fila fila);

filaInfo getInicioFila(Fila fila);

void insereFila(Fila fila, filaInfo info);

filaInfo retiraFila(Fila fila);

Fila removeFila(Fila fila);

#endif