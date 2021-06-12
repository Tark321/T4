#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textoNumerico.h"

typedef struct t{

    double x;
    double y;
    char corb[20];
    char corp[20];
    double txt;

}TextoNumericoStruct;

TextoNumerico criaTextoNumerico(double x, double y, char corb[], char corp[], double txt)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) malloc(sizeof(TextoNumericoStruct));

    text->x = x;
    text->y = y;
    strcpy(text->corb, corb);
    strcpy(text->corp, corp);
    text->txt = txt;

    return text;
}

double getTextoNumericoTexto(TextoNumerico texto)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    return text->txt;
}

double getTextoNumericoX(TextoNumerico texto)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    return text->x;
}

double getTextoNumericoY(TextoNumerico texto)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    return text->y;
}

char* getTextoNumericoCorb(TextoNumerico texto)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    return text->corb;
}

char* getTextoNumericoCorp(TextoNumerico texto)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    return text->corp;
}

void setTextoNumericoTexto(TextoNumerico texto, double txt)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    text->txt = txt;
}

void setTextoNumericoX(TextoNumerico texto, double x)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    text->x = x;
}

void setTextoNumericoY(TextoNumerico texto, double y)
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    text->y = y;
}

void setTextoNumericoCorb(TextoNumerico texto, char corb[])
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    strcpy(text->corb, corb);
}

void setTextoNumericoCorp(TextoNumerico texto, char corp[])
{
    TextoNumericoStruct* text = (TextoNumericoStruct*) texto;
    strcpy(text->corp, corp);
}
