#ifndef __RETANGULO_H
#define __RETANGULO_H

#include "ponto.h"

//Define "Retangulo" como um void pointer
typedef void* Retangulo;

/*
*Cria uma struct retangulo
*Precisa dos parametros necessarios para a criacao de um retangulo
*Retorna um void pointer para a struct retangulo
*/
Retangulo criaRetangulo(char i[], double w, double h, double x, double y, char expessura[], char corb[], char corp[]);

/*
*Obtem o indice(i) de um retangulo
*Precisa de um void pointer retangulo 
*Retorna um int com o indice(i) do retangulo
*/
char* getRetanguloI(Retangulo retangulo);

/*
*Obtem a largura de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com a largura(w) do retangulo
*/
double getRetanguloW(Retangulo retangulo);

/*
*Obtem a altura de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com a altura(h) do retangulo
*/
double getRetanguloH(Retangulo retangulo);

/*
*Obtem o x de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com o x de um retangulo
*/
double getRetanguloX(Retangulo retangulo);

/*
*Obtem o y de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com o y do retangulo 
*/
double getRetanguloY(Retangulo retangulo);

/*
 *Obtem a expessura da borda de um retangulo
 *Precisa de um void pointer retangulo
 *retorna um char com a expessura da borda do retangulo
 */
char* getRetanguloSw(Retangulo retangulo);

/*
*Obtem a cor de borda de retangulo
*Precisa de um void pointer retangulo
*Retorna uma string com a cor de borda(Corb) do retangulo
*/
char* getRetanguloCorb(Retangulo retangulo);

/*
*Obtem a cor de preenchimento de um retangulo
*Precisa de um void pointer retangulo
*Retorna uma string com a cor de preenchimento(Corp) do retangulo
*/
char* getRetanguloCorp(Retangulo retangulo);

Ponto getRetanguloPonto(Retangulo retangulo);

/*
*Armazena um int no indice(i) de um retangulo
*Precisa de um void pointer retangulo e um int
*Não retorna nada
*/
void setRetanguloI(Retangulo retangulo, char i[]);

/*
*Armazena um double na largura(w) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloW(Retangulo retangulo, double w);

/*
*Armazena um double na altura(h) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloH(Retangulo retangulo, double h);

/*
*Armazena um double no x de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloX(Retangulo retangulo, double x);

/*
*Armazena um double no y de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloY(Retangulo retangulo, double y);

/*Armazena uma string na expessura da borda de um retangulo
 *Precisa de um void pointer retangulo e de um char com a expessura
 *Não retorna nada
 */
void setRetanguloSw(Retangulo retangulo, char sw[]);

/*
*Armazena uma string na cor de borda(Corb) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloCorb(Retangulo retangulo, char corb[]);

/*
*Armazena uma string na cor de preenchimento(Corp) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloCorp(Retangulo retangulo, char corp[]);

void setRetanguloPonto(Retangulo retangulo, Ponto p);

void swapRetangulo(Retangulo r1, Retangulo r2);

void desalocaRetangPonto(Retangulo retang);

#endif