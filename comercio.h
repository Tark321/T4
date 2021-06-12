#ifndef __COMERCIO__H
#define __COMERCIO__H

#include "ponto.h"
#include "quadra.h"

typedef void* Comercio;

Comercio criaComercio(Quadra q, char cnpj[], char cpf[], char face[], char codt[], char nome[], double num);

char* getComercioCnpj(Comercio comercio);

char* getComercioCpf(Comercio comercio);

char* getComercioCep(Comercio comercio);

char* getComercioFace(Comercio comercio);

char* getComercioCodt(Comercio comercio);

char* getComercioNome(Comercio comercio);

Ponto getComercioPonto(Comercio comercio);

double getComercioNum(Comercio comercio);

void swapComercio(Comercio c1, Comercio c2);

#endif