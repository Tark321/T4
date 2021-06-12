#ifndef __SVG_H
#define __SVG_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "qry.h"
#include "posto.h"
#include "densidade.h"
#include "textoNumerico.h"
#include "linha.h"
#include "poligono.h"
#include "quadtree.h"


/*
    *Inicia o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void iniciaSvg(FILE* arqSvg);

void finalSvg(FILE* arqSvg);

/*
    *Desenha um circulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o circulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaCirculo(Circulo circulo, FILE* arqSvg);

/*
    *Desenha um retangulo tracejado no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetanguloTracejado(Retangulo retangulo, FILE* arqSvg);

/*
    *Desenha um retangulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetangulo(Retangulo retangulo, FILE* arqSvg);

/*
    *Escreve um texto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTexto(Texto texto, FILE* arqSvg);

/*
    *Escreve um texto do tipo numerico no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTextoNumerico(TextoNumerico textoNum, FILE* arqSvg);

/*
    *Desenha uma quadra no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a quadra, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaQuadra(Quadra quadra, FILE* arqSvg);

/*
    *Desenha um hidrante no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o hidrante, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaHidrante(Hidrante hidrante, FILE* arqSvg);

/*
    *Desenha um semaforo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o semaforo, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaSemaforo(Semaforo semaforo, FILE* arqSvg);

/*
    *Desenha uma torre no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a torre, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRadioBase(Radiobase radiobase, FILE* arqSvg);

/*
    *Desenha um posto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a criacao do posto, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaPosto(Posto posto, FILE* arqSvg);

/*
    *Desenha uma linha no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinha(Linha linha, FILE* arqSvg);

/*
    *Desenha uma linha tracejada no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha tracejada, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinhaTracejada(Linha linha, FILE* arqSvg);

/*
    *Finaliza o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/

void desenhaCirculoTransparente(Circulo circulo, FILE* arqSvg);

void finalizaSvg(FILE* arqSvg);

/*
    *Imprime os elementos guardados na lista no arquivo svg feito para o qry
    *Precisa das listas e do arquivo a ser editado
    *Retorna nada.
    * 
*/

void desenhaGeoSvg(FILE* arqSvg, QuadTree treeObjeto[], Lista l);

void gerarSvgQry(QuadTree treeObjeto[], FILE* saidaSvg, Lista listasQry[]);


#endif
