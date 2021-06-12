#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dadosPessoais.h"

typedef struct dados
{
    char cpf[10];
    Address a;
    
}StructDados;

DadosPessoais cadastraDados(char cpf[], Address a)
{
    StructDados* d = (StructDados*) malloc(sizeof(StructDados));
    strcpy(d->cpf, cpf);
    d->a = a;

    return d;
}

char* getDadoCpf(DadosPessoais dados)
{
    StructDados* d = (StructDados*) dados;
    return d->cpf;
}

Address getDadoAddress(DadosPessoais dados)
{
    StructDados* d = (StructDados*) dados;
    return d->a;
}
