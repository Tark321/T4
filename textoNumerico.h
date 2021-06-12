#ifndef __TEXTONUMERICO_H
#define __TEXTONUMERICO_H

//Define "TextoNumerico" como um void pointer
typedef void* TextoNumerico;

/*
*Cria uma struct textoNumerico
*Precisa dos parametros necessarios para a criacao de um textoNumerico
*Retorna um void pointer para a struct textoNumerico
*/
TextoNumerico criaTextoNumerico(double x, double y, char corb[], char corp[], double txt);

/*
*Obtem o indice de um textoNumerico
*Precisa de um void pointer textoNumerico
*Retorna um double com o texto(txt) de um textoNumerico
*/
double getTextoNumericoTexto(TextoNumerico texto);

/*
*Obtem o x de um texto
*Precisa de um void pointer texto
*Retorna um double com o x do texto
*/
double getTextoNumericoX(TextoNumerico texto);

/*
*Obtem o y de um texto
*Precisa de um void pointer texto
*Retorna um double com o y do texto
*/
double getTextoNumericoY(TextoNumerico texto);

/*
*Obtem a cor de borda de um textoNumerico
*Precisa de um void pointer textoNumerico
*Retorna uma string com a cor de borda(Corb) de um textoNumerico
*/
char* getTextoNumericoCorb(TextoNumerico texto);

/*
*Obtem a cor de preenchimento de um textoNumerico
*Precisa de um void pointer textoNumerico
*Retorna uma string com a cor de preenchimento(Corp) de um textoNumerico
*/
char* getTextoNumericoCorp(TextoNumerico texto);

/*
*Armazena um double no txt de um textoNumerico
*Precisa de um void pointer textoNumerico e um double 
*Não retorna nada
*/
void setTextoNumericoTexto(TextoNumerico texto, double txt);

/*
*Armazena um double no x de um textoNumerico
*Precisa de um void pointer textoNumerico e um double 
*Não retorna nada
*/
void setTextoNumericoX(TextoNumerico texto, double x);

/*
*Armazena um double no y de um textoNumerico
*Precisa de um void pointer textoNumerico e um double
*Não retorna nada
*/
void setTextoNumericoY(TextoNumerico texto, double y);

/*
*Armazena uma string na cor de borda de um textoNumerico
*Precisa de um void pointer textoNumerico e uma string
*Não retorna nada
*/
void setTextoNumericoCorb(TextoNumerico texto, char corb[]);

/*
*Armazena uma string na cor de preenchimento de um textoNumerico
*Precisa de um void pointer textoNumerico e uma string
*Não retorna nada
*/
void setTextoNumericoCorp(TextoNumerico texto, char corp[]);

#endif