#ifndef __LERQRY_H
#define __LERQRY_H

#include "hashTable.h"
#include "quadtree.h"
#include "svg.h"
#include "qry.h"


/*
*Le o arquivo Qry e realiza suas funçcoes
*precisa do nome do arquivo qry e a lista
*não retorna nada
*/
void lerQry (char saidaQry[], QuadTree treeObjeto[], HashTable hashT[], char arqQry[], Lista listasQry[], Lista listaObjeto[]);

#endif