#ifndef __DADOSPESSOAIS__H
#define __DADOSPESSOAIS__H

#include "address.h"

typedef void* DadosPessoais;

DadosPessoais cadastraDados(char cpf[], Address a);

char* getDadoCpf(DadosPessoais dados);

Address getDadoAddress(DadosPessoais dados);

#endif