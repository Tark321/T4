#ifndef __LINHA_H
#define __LINHA_H

//Define "Linha" como um void pointer
typedef void* Linha;

/*
*Cria uma struct linha
*Precisa dos parametros necessarios para a criação de um elemento linha
*Retorna um void pointer para a struct linha
*/
Linha criaLinha(double x1, double y1, double x2, double y2, char cor[20]);

/*
*Obtem o eixo x1 da linha
*Precisa de um void pointer casos como parametro
*Retorna o eixo x1 (x1) da linha
*/
double getLinhaX1(Linha linha);

/*
*Obtem o eixo x2 da linha
*Precisa de um void pointer casos como parametro
*Retorna o eixo x2 (x2) da linha
*/
double getLinhaX2(Linha linha);

/*
*Obtem o eixo y1 da linha
*Precisa de um void pointer casos como parametro
*Retorna o eixo y1 (y1) da linha
*/
double getLinhaY1(Linha linha);

/*
*Obtem o eixo y2 da linha
*Precisa de um void pointer casos como parametro
*Retorna o eixo y2 (y2) da linha
*/
double getLinhaY2(Linha linha);

/*
*Obtem o a cor para a linha
*Precisa de um void pointer casos como parametro
*Retorna a cor (cor) da linha
*/
char* getLinhaCor(Linha linha);

/*
*Armazena um valor que é passado como parametro no eixo x1 também passado por parametro
*Precisa de um void pointer Linha e de um valor para o eixo x1
*Não retorna nada
*/
void setLinhaX1(Linha linha, double x1);

/*
*Armazena um valor que é passado como parametro no eixo x2 também passado por parametro
*Precisa de um void pointer Linha e de um valor para o eixo x2
*Não retorna nada
*/
void setLinhaX2(Linha linha, double x2);

/*
*Armazena um valor que é passado como parametro no eixo y1 também passado por parametro
*Precisa de um void pointer Linha e de um valor para o eixo y1
*Não retorna nada
*/
void setLinhaY1(Linha linha, double y1);

/*
*Armazena um valor que é passado como parametro no eixo y2 também passado por parametro
*Precisa de um void pointer Linha e de um valor para o eixo y2
*Não retorna nada
*/
void setLinhaY2(Linha linha, double y2);

/*
*Armazena um valor que é passado como parametro cor que também e passada por parametro
*Precisa de um void pointer Linha e de um valor para a cor
*Não retorna nada
*/
void setLinhaCor(Linha linha, char cor[]);


#endif