#ifndef __QUADRA_H
#define __QUADRA_H

#include "ponto.h"

//Define "Quadra" como um void pointern 
typedef void* Quadra;

/*
*Cria uma struct quadra
*Precisa dos parametros necessarios para a criação de uma quadra
*Retorna um void pointer para a struct quadra
*/
Quadra criaQuadra(char cep[], double x, double y, double w, double h, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o cep de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o indice (i) do circulo
*/
char* getQuadraCep(Quadra quadra);

/*
*Obtem o x de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o eixo x de uma quadra
*/
double getQuadraX(Quadra quadra);

/*
*Obtem o y de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o eixo y de uma quadra
*/
double getQuadraY(Quadra quadra);

/*
*Obtem a largura de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a largura(W) de uma quadra
*/
double getQuadraW(Quadra quadra);

/*
*Obtem a altura de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a altura(H) de uma quadra
*/
double getQuadraH(Quadra quadra);

/*
*Obtem a espessura de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a espessura(Sw) de uma quadra
*/
char* getQuadraSw(Quadra quadra);

/*
*Obtem a cor de borda de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a cor de borda(Cfill) de uma quadra
*/
char* getQuadraCfill(Quadra quadra);

/*
*Obtem a cor de preenchimento de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a cor de preenchimento(Cstrk) de uma quadra
*/
char* getQuadraCstrk(Quadra quadra);

Ponto getQuadraPonto(Quadra quadra);

double getQuadraDensidade(Quadra quadra);

/*
*Armazena uma string cep em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCep(Quadra quadra, char cep[]);

/*
*Armazena um valor de x em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraX(Quadra quadra, double x);

/*
*Armazena um valor de y em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraY(Quadra quadra, double y);

/*
*Armazena um valor de w em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraW(Quadra quadra, double w);

/*
*Armazena um valor h em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraH(Quadra quadra, double h);

/*
*Armazena uma string de espessura em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraSw(Quadra quadra, char sw[]);

/*
*Armazena uma string com a cor de borda em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCfill(Quadra quadra, char cfill[]);

/*
*Armazena uma string com a cor de preenchimento em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCstrk(Quadra quadra, char cstrk[]);

void setQuadraPonto(Quadra quadra, Ponto p);

void setQuadraDensidade(Quadra quadra, double densidade);

void swapQuadra(Quadra q1, Quadra q2);

void desalocaQuadraPonto(Quadra quad);

#endif