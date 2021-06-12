#ifndef __DENSIDADE_H
#define __DENSIDADE_H

//Define "Densidade" como um void pointer
typedef void* Densidade;

/*
*Cria uma struct densidade
*Precisa dos parametros necessarios para a criação de um elemento densidade
*Retorna um void pointer para a struct densidade
*/
Densidade criaDensidade(double x, double y, double w, double h, double d);

/*
*Obtem o eixo x da densidade
*Precisa de um void pointer casos como parametro
*Retorna o eixo x (x) da densidade
*/
double getDensidadeX(Densidade densidade);

/*
*Obtem o eixo y da densidade
*Precisa de um void pointer casos como parametro
*Retorna o eixo y (y) da densidade
*/
double getDensidadeY(Densidade densidade);

/*
*Obtem a medida w para a densidade
*Precisa de um void pointer casos como parametro
*Retorna a medida w (w) para a densidade
*/
double getDensidadeW(Densidade densidade);

/*
*Obtem a medida h para a densidade
*Precisa de um void pointer casos como parametro
*Retorna a medida h (h) para a densidade
*/
double getDensidadeH(Densidade densidade);

/*
*Obtem a densidade
*Precisa de um void pointer casos como parametro
*Retorna a densidade
*/
double getDensidadeD(Densidade densidade);

/*
*Armazena um valor que é passado como parametro no eixo x também passado por parametro
*Precisa de um void pointer densidade e de um valor para o eixo x
*Não retorna nada
*/
void setDensidadeX(Densidade densidade, double x);

/*
*Armazena um valor que é passado como parametro no eixo y também passado por parametro
*Precisa de um void pointer densidade e de um valor para o eixo y
*Não retorna nada
*/
void setDensidadeY(Densidade densidade, double y);

/*
*Armazena um valor que é passado como parametro na medida w também passado por parametro
*Precisa de um void pointer densidade e de um valor para a medida w
*Não retorna nada
*/
void setDensidadeW(Densidade densidade, double w);

/*
*Armazena um valor que é passado como parametro na medida h também passado por parametro
*Precisa de um void pointer densidade e de um valor para a medida h
*Não retorna nada
*/
void setDensidadeH(Densidade densidade, double h);

/*
*Armazena um valor que é passado como parametro na densidade também passado por parametro
*Precisa de um void pointer Densidade e de um valor para a densidade
*Não retorna nada
*/
void setDensidadeD(Densidade densidade, double d);


#endif