#ifndef __QRY_H
#define __QRY_H

#include "quadtree.h"
#include "lista.h"
#include "retangulo.h"
#include "circulo.h"
#include "auxiliar.h"
#include "linha.h"
#include "texto.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radiobase.h"
#include "quadra.h"
#include "auxiliar.h"
#include "ponto.h"
#include "densidade.h"
#include "address.h"
#include "pessoa.h"
#include "textoNumerico.h"
#include "posto.h"
#include "hashTable.h"

void o(char j[], char k[], FILE* saida, QuadTree treeObjeto[], Lista listasQry[]);

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[]);

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[]);

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[]);

void i(QuadTree treeObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[]);

void pnt (QuadTree treeObjeto[], char j[], char corb[], char corp[], FILE* saida);

void delf(QuadTree treeObjeto[], char j[], FILE* saida);

void dq(QuadTree treeObjeto[], FILE* saida, char id[], double r, int ident, Lista listasQry[]);

void del (QuadTree treeObjeto[], char id[], FILE* saida, Lista listasQry[]);

void cbq(QuadTree treeObjeto[], double x, double y, double r, char corb[], FILE* saida);

void crd (QuadTree treeObjeto[], char id[], FILE* saida);

void car(QuadTree treeObjeto[], double x, double y, double w, double h, FILE* saida, Lista listasQry[]);

void cv(QuadTree treeObjeto[], double n, char cep[], char face[], double num, Lista listasQry[]);

void soc(QuadTree treeObjeto[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[]);

void ci(FILE* saida, QuadTree treeObjeto[], double x, double y, double r, Lista listasQry[], FILE* saidaSvg);

void m(FILE* saida, QuadTree treeObjeto[], char cep[]);

#endif
