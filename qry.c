#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include "qry.h"


void o(char j[], char k[], FILE* saida, QuadTree treeObjeto[], Lista listasQry[])
{
    QtNo aux1;
    QtNo aux2;

    aux1 = getNoById(treeObjeto[0], j);
    aux2 = getNoById(treeObjeto[0], k);
    if( aux1 != NULL && aux2 != NULL)
    {
        Info c1 = getInfoQt(treeObjeto[0], aux1);
        Info c2 = getInfoQt(treeObjeto[0], aux2);
        circuloInt(c1, c2, saida, listasQry);
    }

    aux2 = getNoById(treeObjeto[1], k);
    if(aux1 != NULL && aux2 != NULL)
    {
        Info ret = getInfoQt(treeObjeto[0], aux1);
        Info circ = getInfoQt(treeObjeto[1], aux2);
        retanguloxCirculo(circ, ret, saida, listasQry);           
    }

    aux1 = getNoById(treeObjeto[1], j);
    aux2 = getNoById(treeObjeto[0], k);
    if(aux1 != NULL && aux2 != NULL)
    {
        Info ret = getInfoQt(treeObjeto[1], aux1);
        Info circ = getInfoQt(treeObjeto[0], aux2);
        retanguloxCirculo(circ, ret, saida, listasQry);              
    }

    aux2 = getNoById(treeObjeto[1], k);
    if(aux1 != NULL && aux2 != NULL)
    {
        Info r1 = getInfoQt(treeObjeto[1], aux1);
        Info r2 = getInfoQt(treeObjeto[1], aux2);
        retanguloInt(r1, r2, saida, listasQry);
    }
}

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[])
{
    float x,w,y,h;
    x = min(getRetanguloX(r1),getRetanguloX(r2));
    w = max(getRetanguloX(r1) + getRetanguloW(r1),getRetanguloX(r2) + getRetanguloW(r2)) - x;
    y = min(getRetanguloY(r1),getRetanguloY(r2));
    h = max(getRetanguloY(r1) + getRetanguloH(r1),getRetanguloY(r2) + getRetanguloH(r2)) - y;

    if (w <= getRetanguloW(r1) + getRetanguloW(r2) && h <= getRetanguloH(r1) + getRetanguloH(r2))
    {
        fprintf(saida,"%s: retangulo %s: retangulo SIM\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%s: retangulo %s: retangulo NAO\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);
    }
}

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[])
{
    float dist,x,y,w,h;

    dist = distancia(getCirculoX(c1), getCirculoY(c1), getCirculoX(c2), getCirculoY(c2));
    x = min(getCirculoX(c1) - getCirculoR(c1), getCirculoX(c2) - getCirculoR(c2));
    w = max(getCirculoX(c1) + getCirculoR(c1), getCirculoX(c2) + getCirculoR(c2)) - x;
    y = min(getCirculoY(c1) - getCirculoR(c1), getCirculoY(c2) - getCirculoR(c2));
    h = max(getCirculoY(c1) + getCirculoR(c1), getCirculoY(c2) + getCirculoR(c2)) - y;

    if(dist <= getCirculoR(c2) + getCirculoR(c1))
    {
        fprintf(saida,"%s: circulo %s: circulo SIM\n", getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);

    }
    else
    {
        fprintf(saida,"%s: circulo %s: circulo NAO\n",getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[])
{
    float deltaX, deltaY, x, y, w, h;

    if(getCirculoX(circ) > getRetanguloX(ret))
    {
        deltaX = pow(getRetanguloX(ret) + getRetanguloW(ret) - getCirculoX(ret),2);
    }
    else
    {
        deltaX = pow(getRetanguloX(ret) - getCirculoX(circ),2);
    }
    if(getCirculoY(circ) > getRetanguloY(ret))
    {
        deltaY = pow(getRetanguloY(ret) + getRetanguloH(ret) - getCirculoY(circ),2);
    }
    else
    {
        deltaY = pow(getRetanguloY(ret) - getCirculoY(circ),2);
    }

    x = min(getRetanguloX(ret),getCirculoX(circ) - getCirculoR(circ));
    w = max(getRetanguloX(ret) + getRetanguloW(ret),getCirculoX(circ) + getCirculoR(circ)) - x;
    y = min(getRetanguloY(ret),getCirculoY(circ) - getCirculoR(circ));
    h = max(getRetanguloY(ret) + getRetanguloH(ret),getCirculoY(circ) + getCirculoR(circ)) - y;

    if(sqrt(deltaX + deltaY) <= getCirculoR(circ))
    {
        fprintf(saida,"%s: circulo %s: retangulo SIM\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%s: circulo %s: retangulo NAO\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void i(QuadTree treeObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[])
{
    Info info = getNoById(treeObjeto[0], j);

    if(info != NULL)
    {
        Info c = getInfoByIdQt(treeObjeto[0], j);

        if(getCirculoR(c) >= distancia(x, y, getCirculoX(c), getCirculoY(c)))
        {
            fprintf(saida,"circulo interno\n");
            Circulo circ = criaCirculo("0", 5, x, y, "1", "blue", "blue");
            insert(listasQry[3], circ);
            Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"circulo nao interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "magenta", "magenta");
            insert(listasQry[3], circ);

            Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "magenta");
            insert(listasQry[2], lin);
        }
    }

    info = getNoById(treeObjeto[1], j);
    if(info != NULL)
    {
        Info r = getInfoByIdQt(treeObjeto[1], j);
        float difx = x - getRetanguloX(r);
        float dify = y - getRetanguloY(r);

        if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
        {
            fprintf(saida,"retangulo interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "blue", "blue");
            insert(listasQry[3], circ);
            Linha lin = criaLinha(x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"retangulo nao interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "magenta", "magenta");
            insert(listasQry[3], circ);
            Linha lin = criaLinha(x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "magenta");
            insert(listasQry[2], lin);
        }

    }
    
}

void pnt (QuadTree treeObjeto[], char j[], char corb[], char corp[], FILE* saida)
{
    if(getInfoQt(treeObjeto[0], getNoById(treeObjeto[0], j)) != NULL)
    {
        Info c = getInfoByIdQt(treeObjeto[0], j);
        fprintf(saida,"%lf %lf\n", getCirculoX(c), getCirculoY(c));
        setCirculoCorb(c, corb);
        setCirculoCorp(c, corp);
    }
    else if(getInfoQt(treeObjeto[1], getNoById(treeObjeto[1], j)) != NULL)
    {
        Info r = getInfoByIdQt(treeObjeto[1], j);

        fprintf(saida,"%lf %lf\n", getRetanguloX(r), getRetanguloY(r));
        setRetanguloCorb(r, corb);
        setRetanguloCorp(r, corp);
    }
    else if(getInfoQt(treeObjeto[2], getNoById(treeObjeto[2], j)) != NULL)
    {
        Info t = getInfoByIdQt(treeObjeto[2], j);

        fprintf(saida,"%lf %lf\n", getTextoX(t), getTextoY(t));
        setTextoCorb(t, corb);
        setTextoCorp(t, corp);
    }
}

void delf(QuadTree treeObjeto[], char j[], FILE* saida)
{
    if(getNoById(treeObjeto[0], j) != NULL)
    {
        QtNo cc = getNoById(treeObjeto[0], j);
        Info c = removeNoQt(treeObjeto[0], cc);
        fprintf(saida,"%s %lf %lf %lf %s %s \n", getCirculoI(c), getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c));
        desalocaCirculoPonto(c);
    }
    else if(getNoById(treeObjeto[1], j) != NULL)
    {
        QtNo rr = getNoById(treeObjeto[1], j);
        Info r = removeNoQt(treeObjeto[1], rr);
        fprintf(saida,"%s %lf %lf %lf %lf %s %s \n", getCirculoI(r), getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r));
        desalocaRetangPonto(r);
    }
    else if(getNoById(treeObjeto[2], j) != NULL)
    {
        QtNo tt = getNoById(treeObjeto[2], j);
        Info t = removeNoQt(treeObjeto[2], tt);
        fprintf(saida,"%s %lf %lf %s %s %s\n",getTextoI(t), getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t));
        desalocaTextoPonto(t);
    }
}

void dq(QuadTree treeObjeto[], FILE* saida, char id[], double r, int ident, Lista listasQry[], FILE* svg)
{
    Ponto p;
    Info info;
    double x;
    double y;
    double w;
    double h;
    QtNo aux;
    No node;
    int achou = 0;

    switch(id[0])
    {
        case 'h':
            info = getInfoByIdQt(treeObjeto[4], id);
            p = getHidrantePonto(info);
            x = getHidranteX(info);
            y = getHidranteY(info);
            fprintf(saida, "HIDRANTE\n");
            achou = 1;
            break;

        case 's':
            info = getInfoByIdQt(treeObjeto[5], id);
            p = getSemaforoPonto(info);
            x = getSemaforoX(info);
            y = getSemaforoY(info);
            fprintf(saida, "SEMAFARO\n");
            achou = 1;
            break;

        case 'r':
            info = getInfoByIdQt(treeObjeto[6], id);
            p = getRadiobasePonto(info);
            x = getRadiobaseX(info);
            y = getRadiobaseY(info);
            fprintf(saida, "RADIO BASE\n");
            achou = 1;
            break;
    }

   if(achou != 1)
    {
        fprintf(saida, "\nOBJETO NAO ENCONTRADO\n");
        return;
    }

    Lista lista = nosDentroCirculoQt(treeObjeto[3], x, y, r);
    node = getFirst(lista);

    while(node != NULL)
    {printf("entrou no while\n");
        info = getInfoQt(treeObjeto[3], getInfo(node));
        p = getQuadraPonto(info);
        w = getQuadraW(info);
        h = getQuadraH(info);

        if(retInternoCirc(getPontoX(p), getPontoY(p), w, h, x, y, r))
        {
            if(ident)
            {
                fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" wifth=\"%lf\" heigth=\"%lf\" fill=\"beige\" stroke=\"olive\" stroke-width=\"%s\" rx=\"20\"/>", 
                getPontoX(p), getPontoY(p), w, h, getQuadraSw(info));
            }

            fprintf(saida, "QUADRA %s EXCLUIDA COM SUCESSO\n", getQuadraCep(info));
            aux = getInfo(node);
            info = removeNoQt(treeObjeto[3], aux);
            desalocaQuadraPonto(info);

        }

        node = getNext(node);
    }

    Circulo c1 = criaCirculo("0", r, x, y, "1", "black", "none");
    insert(listasQry[3], c1);
    Circulo c2 = criaCirculo("0", 5, x, y, "2", "blue", "none");
    insert(listasQry[3], c2);
    Circulo c3 = criaCirculo("0", 7, x, y, "2", "yellow", "none");
    insert(listasQry[3], c3);

    removeList(lista, NULL);

}

void del (QuadTree treeObjeto[], char id[], FILE* saida, Lista listasQry[])
{
    if(getNoById(treeObjeto[3], id) != NULL)
    {
        QtNo node = getNoById(treeObjeto[3], id);
        Info q = removeNoQt(treeObjeto[3], node);
        fprintf(saida,"%s %lf %lf %lf %lf\n", getQuadraCep(q), getQuadraX(q), getQuadraY(q), getQuadraW(q), getQuadraH(q));

        Linha lin = criaLinha(getQuadraX(q)+getQuadraW(q)/2, (getQuadraY(q)+getQuadraH(q)/2), getQuadraX(q)+getQuadraW(q)/2, 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getQuadraX(q)+getQuadraW(q)/2, 0, "black", "black", getQuadraCep(q));
        insert(listasQry[4], text);

        desalocaQuadraPonto(q);
    }
    else if(getNoById(treeObjeto[4], id) != NULL)
    {
        QtNo node = getNoById(treeObjeto[4], id);
        Info h = removeNoQt(treeObjeto[4], node);
        fprintf(saida,"%s %lf %lf \n", getHidranteId(h), getHidranteX(h), getHidranteY(h));

        Linha lin = criaLinha(getHidranteX(h), getHidranteY(h), getHidranteX(h), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getHidranteX(h), 0, "black", "black", getHidranteId(h));
        insert(listasQry[4], text);

        desalocaHidraPonto(h);
    }
    else if(getNoById(treeObjeto[5], id) != NULL)
    {
        QtNo node = getNoById(treeObjeto[5], id);
        Info s = removeNoQt(treeObjeto[5], node);
        fprintf(saida,"%s %lf %lf \n", getSemaforoId(s), getSemaforoX(s), getSemaforoY(s));

        Linha lin = criaLinha(getSemaforoX(s), getSemaforoY(s), getSemaforoX(s), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getSemaforoX(s), 0, "black", "black", getSemaforoId(s));
        insert(listasQry[4], text);

        desalocaSemaPonto(s);
    }
    else if(getNoById(treeObjeto[6], id) != NULL)
    {
        QtNo node = getNoById(treeObjeto[6], id);
        Info rb = removeNoQt(treeObjeto[6], node);
        fprintf(saida,"%s %lf %lf \n", getRadiobaseId(rb), getRadiobaseX(rb), getRadiobaseY(rb));

        Linha lin = criaLinha(getRadiobaseX(rb), getRadiobaseY(rb), getRadiobaseX(rb), 0, "black");
        insert(listasQry[2], lin);

        Texto text = criaTexto("0", getRadiobaseX(rb), 0, "black", "black", getRadiobaseId(rb));
        insert(listasQry[4], text);

        desalocaRBPonto(rb);
    }

}

void cbq(QuadTree treeObjeto[], double x, double y, double r, char corb[], FILE* saida)
{
    Lista lista = nosDentroCirculoQt(treeObjeto[3], x, y, r);
    No node = getFirst(lista);
    Info info;
    Ponto p;
    double w;
    double h;

    while(node != NULL)
    {
        info = getInfoQt(treeObjeto[3], getInfo(node));
        p = getQuadraPonto(info);
        w = getQuadraW(info);
        h = getQuadraH(info);

        if(retInternoCirc(getPontoX(p), getPontoY(p), w, h, x, y, r))
        {
            setQuadraCstrk(info, corb);
            fprintf(saida, "%s\n", getQuadraCep(info));
        }

        node = getNext(node);
    }

    removeList(lista, NULL);
}

void crd (QuadTree treeObjeto[], char id[], FILE* saida)
{
    if(getNoById(treeObjeto[3], id) != NULL)
    {
        Info q = getInfoByIdQt(treeObjeto[3], id);
        fprintf(saida,"%lf %lf QUADRA\n", getQuadraX(q), getQuadraY(q));
    }
    if(getNoById(treeObjeto[4], id) != NULL)
    {
       
        Info h = getInfoByIdQt(treeObjeto[4], id);
        fprintf(saida,"%lf %lf HIDRANTE\n", getHidranteX(h), getHidranteY(h));
    }
    if(getNoById(treeObjeto[5], id) != NULL)
    {
        Info s = getInfoByIdQt(treeObjeto[5], id);
        fprintf(saida,"%lf %lf SEMAFORO\n", getSemaforoX(s), getSemaforoY(s));
    }
    if(getNoById(treeObjeto[6], id) != NULL)
    {
        Info rb = getInfoByIdQt(treeObjeto[6], id);
        fprintf(saida,"%lf %lf RADIO BASE\n", getRadiobaseX(rb), getRadiobaseY(rb));
    }
}

void car(QuadTree treeObjeto[], double x, double y, double w, double h, FILE* saida, Lista listasQry[])
{
    Lista lista = nosDentroRetanguloQt(treeObjeto[3], x, y, x+w, y+h);
    No node = getFirst(lista);
    double areaTotal=0;
    float auxW;
    float auxH;

    while(node != NULL)
    {
        Info q1 = getInfoQt(treeObjeto[3], getInfo(node));

        auxW = max(getQuadraX(q1) + getQuadraW(q1), x + w) - x;
        auxH = max(getQuadraW(q1) + getQuadraH(q1), y + h) - y;

        if(auxW <= getQuadraW(q1) + w && auxH <= getQuadraH(q1) + h)
        {
            areaTotal += (getQuadraH(q1)*getQuadraW(q1));
            fprintf(saida, "%s %lf\n", getQuadraCep(q1),(getQuadraH(q1)*getQuadraW(q1)));
        }

        node = getNext(node);
    }

    TextoNumerico textNum = criaTextoNumerico(x, 0, "black", "black", areaTotal);
    insert(listasQry[0], textNum);

    Retangulo ret = criaRetangulo("0", w, h, x ,y , "2.5", "black", "none");
    insert(listasQry[1], ret);

    Linha lin = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], lin);  

    fprintf(saida, "Area Total: %lf\n", areaTotal);

}

void cv(QuadTree treeObjeto[], double n, char cep[], char face[], double num, Lista listasQry[])
{
    double x, y;
    if(getNoById(treeObjeto[3], cep) != NULL)
    {
        Info q = getInfoByIdQt(treeObjeto[3], cep);

        if(strcmp(face, "N") == 0)
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q) + getQuadraH(q);
        }
        else if(strcmp(face, "S") == 0)
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q);
        }
        else if(strcmp(face, "L") == 0)
        {
            x = getQuadraX(q);
            y = getQuadraY(q) + num;
        }
        else if(strcmp(face, "O") == 0)
        {
            x = getQuadraX(q) + getQuadraW(q);
            y = getQuadraY(q) + num;
        }

    }

    Casos caso = criaCasos(n, x, y, face, num, cep);
    insereQt(treeObjeto[11], getCasosPonto(caso), caso);

    Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "orange", "orange");
    insert(listasQry[1], ret);

    TextoNumerico textNum = criaTextoNumerico(x, y, "white", "white", n);
    insert(listasQry[0], textNum);

}

void soc(QuadTree treeObjeto[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[])
{
    double x, y;
    int size = 0;
    No aux;
    No node;
    Info po;
    Info inf;

    if(getNoById(treeObjeto[3], cep) == NULL)
    {
        printf("QUADRA NAO ENCONTRADA");
        return;
    }
    else if(getNoById(treeObjeto[3], cep) != NULL)
    {
        Info q = getInfoByIdQt(treeObjeto[3], cep);

        if(strcmp(face, "N"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q) + getQuadraH(q);
        }
        else if(strcmp(face, "S"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q);
        }
        else if(strcmp(face, "L"))
        {
            x = getQuadraX(q);
            y = getQuadraY(q) + num;
        }
        else if(strcmp(face, "O"))
        {
            x = getQuadraX(q) + getQuadraW(q);
            y = getQuadraY(q) + num;
        }
    }

    Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "white", "blue");
    insert(listasQry[1], ret);

    Lista lista = create();
    percorreLarguraQt(treeObjeto[7], insert, lista);

    double vet[tamanhoDaLista(lista)];

    for(node = getFirst(lista); node != NULL; node = getNext(node))
    {
        po = getInfo(node);

        double dist = distancia(x, y, getPostoX(po), getPostoY(po));
        setPostoDistancia(po, dist);
        vet[size] = dist;
        size++;
    }

    size = tamanhoDaLista(lista);
    shellSort(vet, size);

    for(int cont=0; cont < k; cont++)
    {
        for(aux = getFirst(lista); aux != NULL; aux = getNext(aux))
        {   
            inf = getInfo(aux);
            if(getPostoDistancia(inf)==vet[cont])
            {
                Linha lin = criaLinha(x, y, getPostoX(inf), getPostoY(inf), "black");
                insert(listasQry[7], lin);

                fprintf(saida,"%lf %lf\n", getPostoX(inf), getPostoY(inf));
            }
        }
    }
}

void ci(FILE* saida, QuadTree treeObjeto[], double x, double y, double r, Lista listasQry[], FILE* saidaSvg)
{
    No node;
    Info fig;
    int n = 0;
    double d;
    double inc;
    double area;
    char cor[22];
    Ponto ponto;

    Info circ = criaCirculo("0", r, x, y, "5px", "green", "none");
    insert(listasQry[3], circ);

    Lista aux = nosDentroCirculoQt(treeObjeto[11], x, y, r);
    Lista casos = NULL;

    if(getFirst(aux) == NULL)
    {
        removeList(aux, NULL);
        printf("NAO HA CASOS NA REGIAO\n");
        return;
    }

    node = getNoById(treeObjeto[3], getCasosCEP(getInfoQt(treeObjeto[10], getInfo(getFirst(aux)))));

    if( node == NULL)
    {
        removeList(aux, NULL);
        printf("DENSIDADE DA REGIAO NAO INFORMADA\n");
        return;
    }

    d = getDensidadeD(getInfoQt(treeObjeto[3], node));
    Lista lista = create();


    for(node = getFirst(aux); node != NULL; node = getNext(node))
    {
        fig = getInfoQt(treeObjeto[10], getInfo(node));
        ponto = getCasosPonto(fig);
        insert(lista, ponto);
        fprintf(saida,"X : %lf Y : %lf\n", getPontoX(fig), getPontoY(fig));
        n += getCasosN(fig);

    }

    removeList(aux, NULL);


    if(tamanhoDaLista(lista) <= 2)
    {
        casos = NULL;
        printf("NAO HA A POSSIBILIDADE DE SE FORMAR UM POLIGONO COM MENOS DE 3 PONTOS\n");
    }
    else
    {
        casos = envoltoria(lista, NULL, swapPonto);
    }
    
    if(casos == NULL)
    {
        casos = lista;
    }
    else
    {
        removeList(lista, NULL);
    }

    area = obterArea(casos);

    fprintf(saida,"Numero de casos : %d\nArea : %lf\n",n,area);

    if(area != 0)
    {
        inc = 10 * n/(d * area);

        if(inc < 0.1)
        {
            strcpy(cor, "00FFFF");
            fprintf(saida,"Categoria : A - Livre de Covid\n");
        }
        else if(inc < 5)
        {
            strcpy(cor, "008080");
            fprintf(saida,"Categoria : B - Baixa incidencia\n");
        }
        else if(inc < 10)
        {
            strcpy(cor, "FFFF00");
            fprintf(saida,"Categoria : C - Media incidencia\n");
        }
        else if(inc < 20)
        {
            strcpy(cor, "FF0000");
            fprintf(saida,"Categoria : D - Alta incidencia\n");
        }
        else
        {
            strcpy(cor, "800080");
            fprintf(saida,"Categoria : E - Catastrofico\n");
            aux  = pontosDentroCirculoQt(treeObjeto[10], x, y, r);

            if(getFirst(aux) == NULL)
            {
                ponto = centroide(casos, area);
                fprintf(saida,"Necessário novo posto em (%lf,%lf)\n",getPostoX(ponto),getPostoY(ponto));
            }
            removeList(aux, NULL);
        }
    }
    else
    {
        fprintf(saida,"Não é possivel obter a categoria da região, apenas um caso dentro do circulo\n");
        removeList(casos, NULL);
        return;
    }

    fprintf(saidaSvg, "\t<polygon id=\"%d\" fill=\"%s\" fill-opacity=\"0.2\" stroke=\"red\" stroke-width=\"5px\" points=\"", tamanhoDaLista(casos), cor);

    for(node = getFirst(casos); node != NULL; node = getNext(node))
    {
        fig = getInfo(node);
        fprintf(saidaSvg, " %lf %lf", getPontoX(fig), getPontoY(fig));
    }

    fprintf(saidaSvg, "\"/>\n");
    removeList(casos, NULL);
}

void m(FILE* saida, QuadTree treeObjeto[], char cep[])
{
    Quadra q = getInfoByIdQt(treeObjeto[3], cep);

    if(q == NULL)
    {
        fprintf(saida, "\nQuadra inexistente\n");
        return;
    }

    double x = getPontoX(getQuadraPonto(q));
    double y = getPontoY(getQuadraPonto(q));
    Lista lista = nosDentroRetanguloQt(treeObjeto[10], x, y, x + getQuadraW(q), y + getQuadraH(q));

    for(No no = getFirst(lista); no != NULL; no = getNext(no))
    {
        Address address = getInfoQt(treeObjeto[10], getInfo(no));
        Pessoa pessoa = getInfoByIdQt(treeObjeto[3], getAddressCpf(address));
        fprintf(saida,"Informações pessoais:\nCpf : %s\nNome : %s\nSobrenome : %s\nSexo : %s\nNascimento : %s\n", 
        getPessoaCpf(pessoa), getPessoaNome(pessoa), getPessoaSobre(pessoa), getPessoaSexo(pessoa), getPessoaNasc(pessoa));

        fprintf(saida, "Endereço:\nCEP : %s, face : %s, número: %lf, complemento: %s\n\n", cep, getAddressCep(address), 
        getAddressNum(address), getAddressComplemento(address));
    }

    removeList(lista, NULL);
}

void dm(FILE* saida, QuadTree treeObjeto[], Lista listaQry[], HashTable hash[], char cpf[])
{
    Info pessoa = getValue(hash[2], cpf);
    Info endereco = getValue(hash[3], cpf);

    if(pessoa == NULL || endereco == NULL)
    {
        fprintf(saida, "NAO HA INFORMACOES PARA ESTE CPF\n");
        printf("CPF INVALIDO\n");
        return;
    }

        fprintf(saida, "Nome:%s %s\nCPF: %s\nNascimento: %s\nSexo: %s\nCEP: %s Face: %s Numero: %lf Complemento: %s\n", getPessoaNome(pessoa),
        getPessoaSobre(pessoa), getPessoaCpf(pessoa), getPessoaNasc(pessoa), getPessoaSexo(pessoa), getAddressCep(endereco), getAddressFace(endereco),
        getAddressNum(endereco), getAddressComplemento(endereco));

        Linha linha = criaLinha(getPontoX(getAddressPonto(endereco)), getPontoY(getAddressPonto(endereco)), getPontoX(getAddressPonto(endereco)), 0, "black");
        insert(listaQry[2], linha);


    char texto [1150];
    sprintf(texto, "CPF: %s Nome: %s CEP: %s Face: %s Num: %lf", getAddressCpf(endereco), getPessoaNome(pessoa),
    getAddressCep(endereco), getAddressFace(endereco), getAddressNum(endereco));

    Texto text = criaTexto("0", getPontoX(getAddressPonto(endereco)), 0, "black", "black", texto);
    insert(listaQry[4], text);
}

void de(QuadTree treeObjeto[], FILE* saida, HashTable hash[], char cnpj[])
{
    QtNo no;
    Info info;

    no = getNoById(treeObjeto[9], cnpj);

    if(no == NULL)
    {
        fprintf(saida,"ESTABELECIMENTO COMERCIAL INEXISTENTE\n");
        printf("COMERCIO INEXISTENTE\n");
        return;
    }

    info = getInfoQt(treeObjeto[9], no);

    fprintf(saida, "Nome: %s CPF: %s\nCNPJ: %s\nFace: %s Num: %lf CODT: %s\n", getComercioNome(info),
    getComercioCpf(info), getComercioCnpj(info), getComercioFace(info), getComercioNum(info), getComercioCodt(info));

}

void mud(QuadTree treeObjeto[], Lista listaQry[], HashTable hash[], FILE* saida, char cpf[], char cep[], char face[], char complemento[], double num)
{
    Info pessoa = getValue(hash[2], cpf);
    Info endereco = getValue(hash[3], cpf);
    Ponto p;

    if(pessoa == NULL || endereco == NULL)
    {
        fprintf(saida, "MORADOR NAO ENCONTRADO\n");
        printf("MORADOR NAO ENCONTRADO\n");
        return;
    }

    fprintf(saida, "DADOS DO MORADOR\nNome: %s %s CPF: %s\nNascimento: %s Sexo: %s\n", getPessoaNome(pessoa),
    getPessoaSobre(pessoa), getPessoaCpf(pessoa), getPessoaSexo(pessoa), getPessoaSexo(pessoa));
    fprintf(saida, "ENDERECO ANTIGO\nCEP: %s\nFace: %s Num:%lf Complemento: %s", getAddressCep(endereco),
    getAddressFace(endereco), getAddressNum(endereco), getAddressComplemento(endereco));
    fprintf(saida, "ENDERECO ATUAL\nCEP: %s\nFace: %s Num: %lf Complemento: %s", cep, face, num, complemento);

    p = getAddressPonto(endereco);
    Linha linha = criaLinha(getPontoX(getAddressPonto(endereco)), getPontoY(getAddressPonto(endereco)), getPontoX(p), getPontoY(p), "red");
    insert(listaQry[2], linha);

    Circulo circulo = criaCirculo("0", 8, getPontoX(getAddressPonto(endereco)), getPontoY(getAddressPonto(endereco)),"3", "white", "red");
    insert(listaQry[3], circulo);

    Circulo circ = criaCirculo("0", 8, getPontoX(p), getPontoY(p), "3", "white", "blue");
    insert(listaQry[3], circ);

    setAddressCep(endereco, cep);
    setAddressNum(endereco, num);
    setAddressPonto(endereco, p);
    setAddressFace(endereco, face);
    setAddressComplemento(endereco, complemento);
}

void dmprbt(QuadTree treeObjeto[], char tipo, char saida[], char sfx[])
{
    int i;

    switch(tipo)
    {
        case 'q':
            i = 3;
            break;
        case 'h':
            i = 4;
            break;
        case 's':
            i = 5;
            break;
        case 't':
            i = 6;
            break;
        default:
            printf("INVALIDO\n");
            return;
    }

    printf("%d\n", i);
    char* pathSvg = malloc((6 + strlen(sfx) + strlen(saida))*sizeof(char));
    sprintf(pathSvg, "%s-%s.svg", saida, sfx);
    FILE* svg = fopen(pathSvg, "w");
    iniciaSvg(svg);
    //desenharQt(treeObjeto[i], svg);
    finalizaSvg(svg);
    free(pathSvg);
}

void epgl(QuadTree treeObjeto[], FILE* saida, Lista listaQry[], HashTable hash[], double x, double y, double w, double h, char tipo[])
{
    Lista lista = nosDentroRetanguloQt(treeObjeto[9], x, y, x+w, y+h);
    Info pessoa;
    Info comercio;
    QtInfo info;
    No node;
    Ponto p;

    if(lista == NULL)
    {
        printf("COMANDO EPGL NAO PODE SER RODADO\n");
        fprintf(saida, "ERRO NO COMANDO EPGL\n");
        return;
    }

    if(tipo != NULL)
    {
        if(strcmp(tipo, "*") == 0)
        {
            for(node = getFirst(lista); node != NULL; node = getNext(node))
            {
                comercio = getInfo(node);
                info = getInfoQt(treeObjeto[9], comercio);
                p = getComercioPonto(info);
                pessoa = getValue(hash[2], getComercioCpf(info));

                fprintf(saida, "COMERCIO\n Nome: %s CNPJ: %s\nCODT: %s CEP: %s Face: %s Numero:%lf", getComercioNome(info),
                getComercioCnpj(info), getComercioCodt(info), getComercioCep(info), getComercioFace(info), getComercioNum(info));

                if(pessoa == NULL)
                {
                    printf("COMANDO EPGL NAO PODE SER TERMINADO");
                    fprintf(saida, "PESSOA PARA ESTE ESTABELECIMENTO NAO ENCONTRADA");
                    return;
                }
                else
                {
                    fprintf(saida, "DONO COMERCIO\nNome completo: %s %s\nCPF: %s Data de Nascimento: %s Sexo: %s", getPessoaNome(pessoa),
                    getPessoaSobre(pessoa), getPessoaCpf(pessoa), getPessoaNasc(pessoa), getPessoaSexo(pessoa));

                    Circulo circulo = criaCirculo("0", 7, getPontoX(p), getPontoY(p), "3", "black", "blue");
                    insert(listaQry[3], circulo);
                }

            }
        }
        else
        {
            for(node = getFirst(lista); node != NULL; node = getNext(node))
            {
                comercio = getInfo(node);
                info = getInfoQt(treeObjeto[9], comercio);
                p = getComercioPonto(info);
                pessoa = getValue(hash[2], getComercioCpf(info));

                if(strcmp(getComercioCodt(comercio), tipo) == 0)
                {
                    fprintf(saida, "COMERCIO\n Nome: %s CNPJ: %s\nCODT: %s CEP: %s Face: %s Numero:%lf", getComercioNome(info),
                    getComercioCnpj(info), getComercioCodt(info), getComercioCep(info), getComercioFace(info), getComercioNum(info));

                    if(pessoa == NULL)
                    {
                        printf("COMANDO EPGL NAO PODE SER TERMINADO");
                        fprintf(saida, "PESSOA PARA ESTE ESTABELECIMENTO NAO ENCONTRADA");
                        return;
                    }
                    else
                    {
                        fprintf(saida, "DONO COMERCIO\nNome completo: %s %s\nCPF: %s Data de Nascimento: %s Sexo: %s", getPessoaNome(pessoa),
                        getPessoaSobre(pessoa), getPessoaCpf(pessoa), getPessoaNasc(pessoa), getPessoaSexo(pessoa));

                        Circulo circulo = criaCirculo("0", 7, getPontoX(p), getPontoY(p), "3", "black", "blue");
                        insert(listaQry[3], circulo);
                    }
                }
            }
        }
    }
    else
    {
        return;
    }

}

void catac(QuadTree treeObjeto[], FILE* saida, double x, double y, double r, Lista listaQry[], HashTable hash[])
{
    Lista q = nosDentroCirculoQt(treeObjeto[3], x, y, r); 
    for(No no = getFirst(q); no != NULL; no = getNext(no))
    {
        Info quadra = getInfoQt(treeObjeto[3], getInfo(no));
        Ponto p = getQuadraPonto(quadra);

        if(retInternoCirc(getPontoX(p), getPontoY(p), getQuadraW(quadra), getQuadraH(quadra), x, y, r))
        {
            fprintf(saida, "QUADRA\n");
            fprintf(saida, "\tCEP: %s\nX: %lf Y: %lf W: %lf H:%lf\n", getQuadraCep(quadra), getQuadraX(quadra), 
            getQuadraY(quadra), getQuadraW(quadra), getQuadraH(quadra));
            deleteItemTable(hash[0], getQuadraCep(quadra));
            Info info = removeNoQt(treeObjeto[3], getInfo(no));
            desalocaQuadraPonto(info);
        }

    }
    removeList(q, NULL);

    Lista s = nosDentroCirculoQt(treeObjeto[5], x, y, r);
    
    for(No no = getFirst(s); no != NULL; no = getNext(no))
    {
        Info sema = getInfoQt(treeObjeto[5], getInfo(no));
        fprintf(saida, "SEMAFORO\n");
        fprintf(saida, "\tID: %s\nX: %lf Y: %lf", getSemaforoId(sema), getSemaforoX(sema), getSemaforoY(sema));
        Info info = removeNoQt(treeObjeto[5], getInfo(no));
        desalocaSemaPonto(info);

    }
    removeList(s, NULL);

    Lista h = nosDentroCirculoQt(treeObjeto[4], x, y, r);
    
    for(No no = getFirst(h); no != NULL; no = getNext(no))
    {
        Info hidra = getInfoQt(treeObjeto[4], getInfo(no));
        fprintf(saida, "HIDRANTE\n");
        fprintf(saida, "\tID: %s\nX: %lf Y: %lf", getHidranteId(hidra), getHidranteX(hidra), getHidranteY(hidra));
        Info info = removeNoQt(treeObjeto[4], getInfo(no));
        desalocaHidraPonto(info);
    }
    removeList(h, NULL);

    Lista rb = nosDentroCirculoQt(treeObjeto[6], x, y, r);
    
    for(No no = getFirst(rb); no != NULL; no = getNext(no))
    {
        Info radioB = getInfoQt(treeObjeto[6], getInfo(no));
        fprintf(saida, "RADIO BASE\n");
        fprintf(saida, "\tID: %s\nX: %lf Y: %lf", getRadiobaseId(radioB), getRadiobaseX(radioB), getRadiobaseY(radioB));
        Info info = removeNoQt(treeObjeto[6], getInfo(no));
        desalocaRBPonto(info);
    }
    removeList(rb, NULL);

    Lista  a = nosDentroCirculoQt(treeObjeto[10], x, y, r);
    for(No no = getFirst(a); no != NULL; no = getNext(no))
    {
        Info mora = getInfoQt(treeObjeto[10], getInfo(no));
        Ponto p = getAddressPonto(mora);
        fprintf(saida, "MORADOR\n");
        fprintf(saida, "\tCPF: %s\nCEP: %s Num: %lf Complemento: %s Face: %s\nX: %lf y: %lf", getAddressCpf(mora),
        getAddressCep(mora), getAddressNum(mora), getAddressComplemento(mora), getAddressFace(mora), 
        getPontoX(p), getPontoY(p));
        deleteItemTable(hash[3], getAddressCpf(mora));
        Info info = removeNoQt(treeObjeto[10], getInfo(no));
        desalocaAddress(info);
    }
    removeList(a, NULL);

    Lista c = nosDentroCirculoQt(treeObjeto[9], x, y, r);
    for(No no = getFirst(c); no != NULL; no = getNext(no))
    {
        Info com = getInfoQt(treeObjeto[9], getInfo(no));
        fprintf(saida, "COMERCIO\n");
        fprintf(saida, "\tNome: %s CPF: %s\nCEP: %s CNPJ: %s", getComercioNome(com), getComercioCpf(com), 
        getComercioCep(com), getComercioCnpj(com));
        Info info = removeNoQt(treeObjeto[9], getInfo(no));
        desalocaComercio(info);

    }
    removeList(c, NULL);
}
