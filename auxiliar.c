#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "auxiliar.h"

double distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

float max(float n1, float n2)
{
    if(n1 > n2)
    {
        return n1;
    }
    return n2;
}

float min(float n1, float n2)
{
    if(n1 > n2)
    {
        return n2;
    }
    return n1;
}

int pontoInternoCirc(double xPonto, double yPonto, double xCirc, double yCirc, double r)
{
    return distancia(xPonto, yPonto, xCirc, yCirc) <= r;
}

int pontoInternoRet(double xPonto, double yPonto, double xRet, double yRet, double w, double h)
{
    double dx = xPonto - xRet;
    double dy = yPonto - yRet;
    return dx >= 0 && dx <= w && dy >= 0 && dy <= h;
}

int retInternoCirc(double xRet, double yRet, double w, double h, double x, double y, double r)
{
    if(distancia(xRet, yRet, x, y) <= r && distancia(xRet + w, yRet + h, x, y) <= r)
    {
        if(distancia(xRet + w, yRet, x, y) <= r && distancia(xRet, yRet + h, x, y) <= r)
        {
            return 1;
        }
    }

    return 0;
}

int retInternoRet(double x1, double x2, double y1, double y2, double w1, double w2, double h1, double h2)
{
    return x1 >= x2 && y1 >= y2 && x1 + w1 <= x2 + w2 && y1 + h1 <= y2 + h2;
}

double obterArea(Lista l)
{
    double a = 0;
    Info i, j;
    No node;

    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node))
    {
        i = getInfo(node);
        j = getInfo(getNext(node));
        a += getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    }

    i = getInfo(node);
    j = getInfo(getFirst(l));
    a += getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);

    return a/2;
}

Ponto centroide(Lista l, double area)
{
    double x = 0, y = 0;
    Info i, j;
    No node;

    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node))
    {
        i = getInfo(node);
        j = getInfo(getNext(node));
        x += (getCasosX(i) + getCasosX(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
        y += (getCasosY(i) + getCasosY(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    }

    i = getInfo(node);
    j = getInfo(getFirst(l));

    x += (getCasosX(i) + getCasosX(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);
    y += (getCasosY(i) + getCasosY(j)) * getCasosX(i) * getCasosY(j) - getCasosY(i) * getCasosX(j);

    return criaPonto(x/(6 * area), y/(6 * area));
}

No partition(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    No i = getPrevious(primeiro);

    for(No j = primeiro; j != ultimo; j = getNext(j))
    {
        if(comparar(getPonto(getInfo(getFirst(l))), getPonto(getInfo(j)), getPonto(getInfo(ultimo))))
        {
            i = (i == NULL) ? primeiro : getNext(i); 
            swap(getInfo(i), getInfo(j));
        }
    }
    i = (i == NULL) ? primeiro : getNext(i); 
    swap(getInfo(i), getInfo(ultimo));
    return i; 
}

void quickSortList(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    if(ultimo != NULL && primeiro != ultimo && getNext(ultimo) != primeiro)
    { 
        No p = partition(l, primeiro, ultimo, getPonto, swap);
        quickSortList(l, primeiro, getPrevious(p), getPonto, swap);
        quickSortList(l, getNext(p), ultimo, getPonto, swap);
    }
}

int orientacao(Ponto a, Ponto b, Ponto c)
{
    double area = (getPontoX(b) - getPontoX(a)) * (getPontoY(c) - getPontoY(a)) - (getPontoY(b) - getPontoY(a)) * (getPontoX(c) - getPontoX(a));

    if(area < 0)
    {
        return -1;
    }
    if(area > 0)
    {
        return 1;
    }
    
    return 0;
}

int comparar(Ponto p0, Ponto a, Ponto b)
{
    int aux = orientacao(p0,a,b);

    if(aux == 0)
    {
        return distancia(getPontoX(p0),getPontoY(p0),getPontoX(b),getPontoY(b)) < distancia(getPontoX(p0),getPontoY(p0),getPontoX(a),getPontoY(a));
    }

    return aux == 1;
}

Ponto defaultGetPonto(Ponto info)
{
    return info;
}

Lista envoltoria(Lista list,  Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    if(getPonto == NULL)
    {
        getPonto = defaultGetPonto;
    }

    if(getTamanhoLista(list) < 3)
    {
        return NULL;
    }

    No primeiro = getFirst(list);
    No i;
    Info aux = getInfo(primeiro);
    Ponto p1;
    Ponto p2;

    for(i = getNext(primeiro); i != NULL; i = getNext(i))
    {
        p2 = getPonto(getInfo(i));
        p1 = getPonto(aux);

        if(getPontoY(p2) < getPontoY(p1) || (getPontoY(p2) == getPontoY(p1) && getPontoX(p2) < getPontoX(p1)))
        {
            aux = getInfo(i);
        }
    }

    swap(getInfo(primeiro), aux);

    quickSortList(list, getNext(primeiro), getLast(list), getPonto, swap);

    Lista auxL = create();
    insert(auxL, getInfo(primeiro));

    for(i = getNext(getNext(primeiro)); i != NULL; i = getNext(i))
    {
        p1 = getPonto(getInfo(i));
        p2 = getPonto(getInfo(getPrevious(i)));

        if(orientacao(getPonto(getInfo(primeiro)), p2, p1) != 0)
        {
            insert(auxL, getInfo(getPrevious(i)));
        }
    }

    insert(auxL, getInfo(getLast(list)));
    int j = getTamanhoLista(auxL);

    if (j < 3)
    {
        removeList(auxL, NULL);
        return NULL;
    }

    Lista envConv = create();

    for(i = getFirst(auxL), j = 0; j < 3; j++, i = getNext(i))
    {
        insert(envConv, getPonto(getInfo(i)));
    }

    while(i != NULL)
    {
        while (getTamanhoLista(envConv) > 1 && orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getPonto(getInfo(i))) != 1)
        {
            removerNo(envConv, getLast(envConv), 0);
        }
        insert(envConv, getPonto(getInfo(i)));
        i = getNext(i);
    }

    removeList(auxL, NULL);
    return envConv;    
}

void shellSort(double *vet, int size)
{
    int i;
    int j;
    int h = 1;
    double value;

    while(h < size) 
    {
        h = 3*h+1;
    }
    while (h > 0) 
    {
        for(i = h; i < size; i++) 
        {
            value = vet[i];
            j = i;

            while (j > h-1 && value <= vet[j - h]) 
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h/3;
    }
}

void balancearQt(QuadTree qt, Lista ListaObjeto, Ponto (*getPonto)(void*), void (*swap)(void*, void*))
{   
    No i;
    No j;
    Ponto p;
    Lista envCov;
    Pilha pilha = criaPilha();

    if(getPonto ==  NULL)
    {
        getPonto = defaultGetPonto;
    }

    while(getTamanhoLista(ListaObjeto) > 3)
    {
        envCov = envoltoria(ListaObjeto, getPonto, swap);

        if(envCov != NULL)
        {
            for(i = getFirst(envCov); i != NULL; i = getNext(i))
            {
                for(j = getFirst(ListaObjeto); j != NULL; j = getNext(j))
                {
                    if(getPonto(getInfo(j)) == getInfo(i))
                    {
                        empilhar(pilha, getInfo(j));
                        removerNo(ListaObjeto, j, semfree);
                        break;
                    }
                }
            }
            removeList(envCov, 0);
        }     
    }

    for(i = getFirst(ListaObjeto); i != NULL; i = getNext(i))
    {
        empilhar(pilha, getInfo(i));
    }
    
    while(!isEmpty(pilha))
    {
        j = desempilha(pilha);

        if(j != NULL)
        {
            p = getPonto(j);
            insereQt(qt, p, j);
        }
    }

    free(pilha);
    
}