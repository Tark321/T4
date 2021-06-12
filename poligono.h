#ifndef __POLIGONO_H
#define __POLIGONO_H

//Define "Poligono" como um void pointer
typedef void* Poligono;

/*
*Cria uma struct poligono
*Precisa dos parametros necessarios para a criação de um poligono
*Retorna um void pointer para a struct poligono
*/
Poligono criaPoligono(char cor[], int tamanho);

/*
*Obtem o eixo x do poligono
*Precisa de um void pointer casos como parametro
*Retorna o eixo x (x) do poligono
*/
double getPoligonoX(Poligono poli, int index);

/*
*Obtem o eixo y do poligono
*Precisa de um void pointer casos como parametro
*Retorna o eixo y (y) do poligono
*/
double getPoligonoY(Poligono poli, int index);

/*
*Obtem o a cor para o poligono
*Precisa de um void pointer casos como parametro
*Retorna a cor (cor) do poligono
*/
char* getPoligonoCor(Poligono poli);

/*
*Obtem o tramanho para o poligono
*Precisa de um void pointer casos como parametro
*Retorna o tamanho (tamanho) do poligono
*/
int getPoligonoTamanho(Poligono poli);

/*
*Armazena um valor que é passado como parametro no eixo x também passado por parametro
*Precisa de um void pointer Poligono e de um valor para o eixo x
*Não retorna nada
*/
void setPoligonoX(Poligono poli, double x, int index);

/*
*Armazena um valor que é passado como parametro no eixo y também passado por parametro
*Precisa de um void pointer Poligono e de um valor para o eixo y
*Não retorna nada
*/
void setPoligonoY(Poligono poli, double y, int index);

#endif