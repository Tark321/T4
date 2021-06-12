#ifndef __CASOS_H
#define __CASOS_H

#include "ponto.h"

//Define "Casos" como um void pointer
typedef void* Casos;

/*
*Cria uma struct casos
*Precisa dos parametros necessarios para a criação de um caso
*Retorna um void pointer para a struct casos
*/
Casos criaCasos(int n, double x, double y, char face[], double num, char cep[]);

/*
*Obtem o numero de casos
*Precisa de um void pointer casos como parametro
*Retorna o numero de casos dado
*/
int getCasosN(Casos casos);

/*
*Obtem o eixo x
*Precisa de um void pointer casos como parametro
*Retorna o eixo x (x)
*/
double getCasosX(Casos casos);

/*
*Obtem o eixo y
*Precisa de um void pointer casos como parametro
*Retorna o eixo y (y)
*/
double getCasosY(Casos casos);

/*
*Obtem o numero dentro da quadra
*Precisa de um void pointer casos como parametro
*Retorna o numero (num)
*/
double getCasosNum(Casos casos);

/*
*Obtem o CEP de identificacao de um quadra
*Precisa de um void pointer casos como parametro
*Retorna o CEP (cep)
*/
char* getCasosCEP(Casos casos);

/*
*Obtem a direcao da quadra se e N, S, L ou O
*Precisa de um void pointer casos como parametro
*Retorna a direcao (face)
*/
char* getCasosFace(Casos casos);

Ponto getCasosPonto(Casos casos);

/*
*Obtem uma troca de valores nos ponteiros
*Precisa de um void pointer casos como parametro
*Retorno sem nada, apenas feita a troca de valores
*/
void swap(Casos *p1, Casos *p2);

#endif