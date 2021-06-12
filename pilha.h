#ifndef __PILHA_H
#define __PILHA_H

typedef void *Pinfo;
typedef void *Pilha;

Pilha criaPilha();

int isEmpty(Pilha pilha);

int tamanhoP(Pilha pilha);

Pinfo getTopP(Pilha pilha);

void empilhar(Pilha pilha, Pinfo info);

Pinfo desempilha(Pilha pilha);

Pilha removePilha(Pilha pilha);

#endif