#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

typedef struct pessoa
{
    char cpf[10];
    char nome[30];
    char sexo[5];
    char sobrenome[30];
    char nascimento[11];
}StructPessoa;

Pessoa cadastraPessoa(char cpf[], char nome[], char sobrenome[], char nascimento[], char sexo[])
{
    StructPessoa* p = (StructPessoa*) malloc(sizeof(StructPessoa));
    strcpy(p->cpf, cpf);
    strcpy(p->nome, nome);
    strcpy(p->sobrenome, sobrenome);
    strcpy(p->nascimento, nascimento);
    strcpy(p->sexo, sexo);

    return p;
}

char* getPessoaCpf(Pessoa pessoa)
{
    StructPessoa* p = (StructPessoa*) pessoa;
    return p->cpf;
}

char* getPessoaNome(Pessoa pessoa)
{
    StructPessoa* p = (StructPessoa*) pessoa;
    return p->nome;
}

char* getPessoaSobre(Pessoa pessoa)
{
    StructPessoa* p = (StructPessoa*) pessoa;
    return p->sobrenome;
}

char* getPessoaNasc(Pessoa pessoa)
{
    StructPessoa* p = (StructPessoa*) pessoa;
    return p->nascimento;
}

char* getPessoaSexo(Pessoa pessoa)
{
    StructPessoa* p = (StructPessoa*) pessoa;
    return p->sexo;
}
