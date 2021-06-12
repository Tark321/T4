#ifndef __COD_H
#define __COD_H

typedef void* CodT;

CodT criaCod(char codt[], char descricao[]);

char* getCodt(CodT cod);

char* getDescricao(CodT cod);

void setCodt(CodT cod, char codt[]);

void setDescricao(CodT cod, char descricao[]);

void desalocsCodt(CodT cod);

#endif