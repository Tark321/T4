#ifndef __SEMAFARO_H
#define __SEMAFARO_H

#include "ponto.h"

//Define "Semaforo" como um void pointer
typedef void* Semaforo;

/*
*Cria uma struct semaforo
*Precisa dos parametros necessarios para criacao de um semaforo
*Retorna um void pointer para a struct semaforo
*/
Semaforo criaSemaforo(char id[], double x, double y, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o id de um semaforo
*Precisa de um void pointer semaforo
*Retorna a string id do semaforo
*/
char* getSemaforoId(Semaforo semaforo);

/*
*Obtem o x de um semaforo
*Precisa de um void pointer semaforo
*Retorna um double com o x do semaforo
*/
double getSemaforoX(Semaforo semaforo);

/*
*Obtem o y de um semaforo
*Precisa de um void pointer semaforo
*Retorna um double com o y do semaforo
*/
double getSemaforoY(Semaforo semaforo);

/*
*Obtem a espessura do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a espessura(Sw) do semaforo
*/
char* getSemaforoSw(Semaforo semaforo);

/*
*Obtem a cor de borda do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a cor de borda(Cfill) do semaforo
*/
char* getSemaforoCfill(Semaforo semaforo);

/*
*Obtem a cor de preenchimento do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a cor de preenchimento(Cstrk) do semaforo
*/
char* getSemaforoCstrk(Semaforo semaforo);

Ponto getSemaforoPonto(Semaforo semaforo);

/*
*Armazena uma string no id do semaforo 
*Precisa de um void pointer semaforo e uma string
*Não retorna nada
*/
void setSemaforoId(Semaforo semaforo, char id[]);

/*
*Armazena um valor double no x do semaforo
*Precisa de um void pointer semaforo e um double
*Não retorna nada
*/
void setSemaforoX(Semaforo semaforo, double x);

/*
*Armazena um valor double no y do semaforo
*Precisa de um void pointer semaforo e um double
*Não retorna nada
*/
void setSemaforoY(Semaforo semaforo, double y);

/*
*Armazena uma string na espessura do semaforo
*Precisa de um void pointer semaforo e uma string com a espessura(Sw)
*Não retorna nada
*/
void setSemaforoSw(Semaforo semaforo, char sw[]);

/*
*Armazena uma string na cor de borda do semaforo
*Precisa de um void pointer semaforo e uma string com a cor de borda(Cfill)
*Não retorna nada
*/
void setSemaforoCfill(Semaforo semaforo, char cfill[]);

/*
*Armazena uma string na cor de preenchimento do semaforo
*Precisa de um void pointer semaforo e uma string com a cor de preenchimento(Cstrk)
*Não retorna nada
*/
void setSemaforoCstrk(Semaforo semaforo, char cstrk[]);

void setSemaforoPonto(Semaforo semaforo, Ponto p);

void swapSemaforo(Semaforo s1, Semaforo s2);

void desalocaSemaPonto(Semaforo sem);

#endif