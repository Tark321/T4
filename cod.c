#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cod.h"

typedef struct cod
{
    char codt[20];
    char descricao[300];
}StructCodT;

CodT criaCod(char codt[], char descricao[])
{
    StructCodT* c = (StructCodT*) malloc(sizeof(StructCodT));
    strcpy(c->codt, codt);
    strcpy(c->descricao, descricao);

    return c;
}

char* getCodt(CodT cod)
{
    StructCodT* c = (StructCodT*)cod;
    return c->codt;
}

char* getDescricao(CodT cod)
{
    StructCodT* c = (StructCodT*)cod;
    return c->descricao;
}

void setCodt(CodT cod, char codt[])
{
    StructCodT* c = (StructCodT*)cod;
    strcpy(c->codt, codt);
}

void setDescricao(CodT cod, char descricao[])
{
    StructCodT* c = (StructCodT*)cod;
    strcpy(c->descricao, descricao);
}

void desalocsCodt(CodT cod)
{
    StructCodT* c = (StructCodT*)cod;
    free(c);
}