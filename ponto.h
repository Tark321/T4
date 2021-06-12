#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef void *Ponto;

Ponto criaPonto(double x, double y);

double getPontoX(Ponto ponto);

double getPontoY(Ponto ponto);

void setPontoX(Ponto ponto, double x);

void setPontoY(Ponto ponto, double y);

void swapPonto(Ponto p1, Ponto p2);

#endif