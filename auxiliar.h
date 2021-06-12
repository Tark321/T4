#ifndef __AUXILIAR_H
#define __AUXILIAR_H

#include "lista.h"
#include "casos.h"
#include "ponto.h"
#include "pilha.h"
#include "quadtree.h"

/*
    *Calcula a distancia entre duas figuras
    *Precisamos das coordenadas dessas figuras
    *Retorna a distancia entre elas

*/
double distancia(double x1, double y1, double x2, double y2);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero maior
    
*/
float max(float n1, float n2);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero menor
    
*/
float min(float n1, float n2);

/*
    *Faz contas para saber se ha um ponto interno no circulo
    *Precisamos dos eixos x, y de ambos Ponto e Circulo e do raio do circulo
    *Retorna a distancia
*/
int pontoInternoCirc(double xPonto, double yPonto, double xCirc, double yCirc, double r);

int pontoInternoRet(double xPonto, double yPonto, double xRet, double yRet, double w, double h);

int retInternoCirc(double xRet, double yRet, double w, double h, double x, double y, double r);

int retInternoRet(double x1, double x2, double y1, double y2, double w1, double w2, double h1, double h2);

/*
    *Faz as contas necessarias para obter a area da regiao
    *Precisamos de um void pointer para lista
    *Retorna a area
*/
double obterArea(Lista l);

/*
    *Faz contas para saber o centroide em uma determinada regiao
    *Precisamos de um void pointer para lista e da area
    *Retorna a funcao criaPosto com dados obtidos 
*/
Ponto centroide(Lista l, double area);

/*
    *Faz utilizacao de recursividade e implementa quicksort
    *Precisamos de um void pointer para lista e de dois nos primeiro e ultimo
    *Nao retorna nada
*/
void quickSortList(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

void shellSort(double *vet, int size);

/*
    *Faz contas para saber a particao de dois pontos
    *Precisamos de um void pointer para lista e dois pontos primeiro e ultimo
    *Retorna i do tipo No
*/
No partition(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

/*
    *Faz contas para saber a orientacao 
    *Precisamos de tres elementos para calculo da area
    *Retorna 1 para area > 1, -1 para area <1 e 0 caso nao satisfaca nenhum dos dois
*/
int orientacao(Ponto a, Ponto b, Ponto c);

/*
    *Faz contas para saber a comparacao entre tres pontos
    *Precisamos de tres elementos
    *Retorna a funcao de distancia caso aux == 0 ou aux == 1
*/
int comparar(Ponto p0, Ponto a, Ponto b);

Ponto defaultGetPonto(Ponto info);

/*
    *Faz contas para a envoltoria convexa
    *Precisamos de um void pointer para lista
    *Retorna o resultado da envoltoria convexa
*/
Lista envoltoria(Lista list,  Ponto (*getPonto)(Info), void (*swap)(Info, Info));

void balancearQt(QuadTree qt, Lista ListaObjeto, Ponto (*getPonto)(void*), void (*swap)(void*, void*));

#endif