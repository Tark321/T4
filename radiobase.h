#ifndef __RADIOBASE_H
#define __RADIOBASE_H

#include "ponto.h"

//Define "Radiobase" como um void pointer 
typedef void* Radiobase;

/*
*Cria uma struct radiobase
*Precisa dos parametros necessarios para a criação de uma radiobase
*Retorna um void pointer para a struct radiobase
*/
Radiobase criaRadiobase(char id[], double x, double y, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o Id de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o Id de uma radiobase
*/
char* getRadiobaseId(Radiobase radiobase);

/*
*Obtem o x de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o x de uma radiobase
*/
double getRadiobaseX(Radiobase radiobase);

/*
*Obtem o y de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o y de uma radiobase
*/
double getRadiobaseY(Radiobase radiobase);

/*
*Obtem a espessura de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a espessura(Sw) de uma radiobase
*/
char* getRadiobaseSw(Radiobase radiobase);

/*
*Obtem a cor de borda de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a cor de borda(Cfill) de uma radiobase
*/
char* getRadiobaseCfill(Radiobase radiobase);

/*
*Obtem a cor de preenchimento de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a cor de preenchimento(Cstrk) de uma radiobase
*/
char* getRadiobaseCstrk(Radiobase radiobase);

Ponto getRadiobasePonto(Radiobase radiobase);

/*
*Armazena um char Id em uma radiobase
*Precisa de um void pointer radiobase e uma string 
*Não retorna nada
*/
void setRadiobaseId(Radiobase radiobase, char id[]);

/*
*Armazena um valor x em uma radiobase
*Precisa de um void pointer radiobase e um double
*Não retorna nada
*/
void setRadiobaseX(Radiobase radiobase, double x);

/*
*Armazena um valor y em uma radiobase
*Precisa de um void pointer radiobase e um double
*Não retorna nada
*/
void setRadiobaseY(Radiobase radiobase, double y);

/*
*Armazena uma string com a espessura em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseSw(Radiobase radiobase, char sw[]);

/*
*Armazena uma string com a cor de borda em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseCfill(Radiobase radiobase, char cfill[]);

/*
*Armazena uma string com a cor de preenchimento em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseCstrk(Radiobase radiobase, char cstrk[]);

void setRadiobasePonto(Radiobase radiobase, Ponto p);

void swapRB(Radiobase rb1, Radiobase rb2);

void desalocaRBPonto(Radiobase rb);

#endif