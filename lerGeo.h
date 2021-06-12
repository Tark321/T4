#ifndef __LERGEO_H
#define __LERGEO_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "posto.h"
#include "densidade.h"
#include "quadtree.h"
#include "pilha.h"
#include "auxiliar.h"


/*
*Le o arquivo geo
*precisa do nome do arquivo e a lista para salvar as informacoes
*não retorna nada
*/
void lerGeo(char arqGeo[], char nomeSvgGeo[], QuadTree treeObjeto[],Lista listaObjeto[], HashTable hash[]);

#endif