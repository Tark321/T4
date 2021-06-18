#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include "lista.h"
#include "ponto.h"

/*
     Implementa uma Point Quadtree. Uma quadtree vazia � criada pela opera��o criaQt().
     Ap�s a cria��o, dados associados a coordenadas bidimensionais podem ser inseridos
     por meio da opera��o insereQt()

     S�o implementadas v�rias fun��es de busca espacial que retornam uma lista contendo
     as chaves, pontos ou n�s da �rvore que estejam dentro de um dado c�rculo ou ret�ngulo.

     A �rvore pode ser percorrida em largura ou em profundidade (percorreLarguraQt() e percorreProfundidadeQt()).
     Para cada n� visitado � invocada um procedimento que processa a informa��o contida no n� visitado.
 */

typedef void *QuadTree;
typedef void *QtInfo;
typedef void *QtNo;
typedef char *InfoKey;
typedef void *ExtraInfo;

typedef InfoKey funcGetChave(QtInfo);
typedef void funcVisita(QtInfo,ExtraInfo);

QuadTree criaQt(funcGetChave f);
/**
    Cria e retorna uma quadtree vazia. "f" � uma fun��o
    que retorna a chave de ordena��o do dado armazenado.
 */

Ponto getPontoQt(QuadTree qt, QtNo pNo);

Lista chavesDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2);
/**
    Cria uma lista contendo as chaves de ordena��o de todas as informa��es
    cujas coordenas associadas (no momento da inser��o) est�o dentro do
    ret�ngulo determinado pelo v�rtices opostos (x1,y1) e (x2,y2).
    Mem�ria � alocada para cada chave armazenada na lista, portanto,
    � seguro (e recomend�vel) desaloca-la quando a respectiva chave
    n�o for mais necess�ria.
    Caso n�o exista nenhuma informa��o interna � regi�o especificada,
    retorna uma lista vazia.
    � recomend�vel que a lista retornada seja desalocada ap�s ser usada.
 */

Lista chavesDentroCirculoQt(QuadTree qt, double x, double y, double r);
/**
    Similar � fun��o chavesDentroRetanguloQt(). Retorna a chave cuja
    coordenada � interna � circunfer�ncia de raio r e centro em (x,y).
 */

Lista pontosDentroRetanguloQt(QuadTree qt,double x1, double y1,double x2, double y2);
/**
    Similar � fun��o chavesDentroRetanguloQt().Por�m, retorna a coordenada geogr�fica (Ponto)
    associada � informa��o. Mem�ria tamb�m � alocada para cada ponto retornado na lista.
 */

Lista pontosDentroCirculoQt(QuadTree qt,double x, double y, double r);
/**
    Similar � fun��o pontosDentroRetanguloQt(). Retorna pontos internos
    � circunfer�ncia de raio r e centro em (x,y).
 */

Lista nosDentroRetanguloQt(QuadTree qt,double x1, double y1,double x2, double y2);
/**
    Similar � fun��o pontosDentroRetanguloQt(). Retorna apontadores para
    n�s da �rvore contendo informa��es cuja coordenada est� dentro da
    regi�o de busca.

    A mem�ria relativa aos apontadores da lista n�o deve ser desalocada.
 */

Lista nosDentroCirculoQt(QuadTree qt,double x, double y, double r);
/**
    Similar � fun��o nosDentroRetanguloQt(). Retorna n�s internos
    � circunfer�ncia de raio r e centro em (x,y).
 */

void percorreProfundidadeQt(QuadTree qt,funcVisita f,ExtraInfo ei);
/**
    Percorre a �rvore em profundidade. Em cada n� visitado invoca
    a fun��o f. Seja pInfo o valor retornado pela opera��o getInfoQt()
    aplicada ao n� visitado; a invoca��o de f � da forma:

         f(pInfo,ei)
 */

void percorreLarguraQt(QuadTree qt,funcVisita f, ExtraInfo ei);
/**
    Semelhante a percorreProfundidadeQt. Percorre a �rvore em largura.
 */

QtNo insereQt(QuadTree qt,Ponto p, QtInfo pInfo);
/**
    Insere na �rvore a informa��o "pInfo", associada � coordenada referente ao ponto "p".
    Retorna refer�ncia ao n� da �rvore onde a pInfo foi armazenada.
 */

QtInfo removeNoQt(QuadTree qt,QtNo pNo);
/**
    Remove da �rvore o n� referenciiado por "pNo".
    "pNo" deve referenciar um n� v�lido dentro da �rvore.
    Retorna a informa��o contida na n� removido.
 */

QtNo getNoQt(QuadTree qt, double x, double y);
/**
    Retorna uma refer�ncia ao n� da �rvore associado � coordenada (x,y).
    Retorna NULL, caso n�o exista tal n�.
 */

QtInfo getInfoQt(QuadTree qt, QtNo pNo);
/**
    Retorna a informa��o armazenada na �rvore no n� referenciiado por pNo.
    "pNo" deve referenciar um n� v�lido dentro da �rvore.
 */

void desalocaQt(QuadTree qt);
/**
    Libera mem�ria alocada pela implementa��o da �rvore. Desaloca apenas mem�ria alocada por criaQt()) e os
    n�s da �rvore criados por insereQt(). N�o desaloca as listas retornadas nas consultas
    espaciais (_*_DentroRetanguloQt() e _*_DentroCirculoQt().

    A fun��o do tipo funcGetChave, par�metro em criaQt(), poderia alocar dinamicamente mem�ria e retornar
    um apontador para ela. Neste caso, esta mem�ria n�o ser� desalocada.
 */

QtNo getNoById(QuadTree qt, char* chave);

QtInfo getInfoByIdQt(QuadTree qt, char* chave);

void desenharQt(QuadTree qt, FILE* svg);

#endif // QUADTREE_H_INCLUDED
