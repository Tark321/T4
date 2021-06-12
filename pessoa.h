#ifndef __PESSOA__H
#define __PESSOA__H

typedef void* Pessoa;

Pessoa cadastraPessoa(char cpf[], char nome[], char sobrenome[], char nascimento[], char sexo[]);

char* getPessoaCpf(Pessoa pessoa);

char* getPessoaNome(Pessoa pessoa);

char* getPessoaSobre(Pessoa pessoa);

char* getPessoaNasc(Pessoa pessoa);

char* getPessoaSexo(Pessoa pessoa);
#endif