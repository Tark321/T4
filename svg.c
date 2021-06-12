#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"svg.h"

void iniciaSvg(FILE* arqSvg)
{
    char* sombra[6] = {"#FFF00", "#FF9955", "#FF0000", "#FF00CC","#6600FF", "#A02C5A"};

    fprintf(arqSvg, "<svg>\n\t<defs>\n");

    for(int i = 0; i < 6; i++)
    {
        fprintf(arqSvg, "\t\t<filter id=\"shadow%d\">\n\t\t\t<feDropShadow dx=\"2\" dy=\"2\" stdDeviation=\"0.2\" flood-color=\"%s\"/>\n\t\t</filter>\n", i, sombra[i]);
    }
    fprintf(arqSvg, "\t</defs>\n");
    
}

void desenhaCirculo(Circulo circulo, FILE* arqSvg)
{
    double x = getCirculoX(circulo);
    double y = getCirculoY(circulo);
    double raio = getCirculoR(circulo);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getCirculoCorb(circulo));
    strcpy(cor_p, getCirculoCorp(circulo));

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, cor_p);
}


void desenhaRetangulo(Retangulo retangulo, FILE* arqSvg)
{
    double x = getRetanguloX(retangulo);
    double y = getRetanguloY(retangulo);
    double w = getRetanguloW(retangulo);
    double h = getRetanguloH(retangulo);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getRetanguloCorb(retangulo));
    strcpy(cor_p, getRetanguloCorp(retangulo));

    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width =\"1\"/>\n",x,y,w,h,cor_p,cor_b);
}

void desenhaRetanguloTracejado(Retangulo retangulo, FILE* arqSvg)
{
    double x = getRetanguloX(retangulo);
    double y = getRetanguloY(retangulo);
    double w = getRetanguloW(retangulo);
    double h = getRetanguloH(retangulo);
    char cor_b[22];
    strcpy(cor_b, getRetanguloCorb(retangulo));
    
    fprintf(arqSvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width =\"1\" stroke-dasharray=\"1\" />\n",x,y,w,h,cor_b);
}

void desenhaRetanguloArredondado(Retangulo retangulo, FILE* arqSvg)
{
    double x = getRetanguloX(retangulo);
    double y = getRetanguloY(retangulo);
    double w = getRetanguloW(retangulo);
    double h = getRetanguloH(retangulo);
    char sw[22];
    strcpy(sw, getRetanguloSw(retangulo));

    fprintf(arqSvg, "\n<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\"  stroke-width=\"%s\" rx=\"20\"/>\n",x,y,w,h,sw);
}

void escreveTexto(Texto texto, FILE* arqSvg)
{
    double x = getTextoX(texto);
    double y = getTextoY(texto);
    char cor_b[22];
    char cor_p[22];
    char text[1000];
    strcpy(cor_b, getTextoCorb(texto));
    strcpy(cor_p, getTextoCorp(texto));
    strcpy(text, getTextoTxto(texto));

    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",x,y,cor_b,cor_p,text);
}

void escreveTextoNumerico(TextoNumerico textoNum, FILE* arqSvg)
{
    double x = getTextoNumericoX(textoNum);
    double y = getTextoNumericoY(textoNum);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getTextoNumericoCorb(textoNum));
    strcpy(cor_p, getTextoNumericoCorp(textoNum));
    double text = getTextoNumericoTexto(textoNum);
    fprintf(arqSvg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%lf</text>\n", x, y, cor_b, cor_p, text);
}

void desenhaQuadra(Quadra quadra, FILE* arqSvg)
{
    int aux;
    double x = getQuadraX(quadra);
    double y = getQuadraY(quadra);
    double w = getQuadraW(quadra);
    double h = getQuadraH(quadra);
    double d = getQuadraDensidade(quadra);
    char cor_p[22];
    char cor_b[22];
    char qSW[22];
    char cep[22];
    strcpy(cor_b, getQuadraCstrk(quadra));
    strcpy(cor_p, getQuadraCfill(quadra));
    strcpy(qSW, getQuadraSw(quadra));
    strcpy(cep, getQuadraCep(quadra));

    if(d <= 500)
    {
        aux = 0;
    }
    else if(d <= 1500)
    {
        aux = 1;
    }
    else if(d <= 3000)
    {
        aux = 2;
    }
    else if(d <= 4500)
    {
        aux = 3;
    }
    else if(d <= 6000)
    {
        aux = 4;
    }
    else
    {
        aux = 5;
    }
    fprintf(arqSvg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" filter=\"url(#shadow%d)\"/>\n",x, y, w, h, cor_p, cor_b, qSW, aux);
    fprintf(arqSvg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>\n", x+w/4, y+h/2, cep);

}

void desenhaHidrante(Hidrante hidrante, FILE* arqSvg)
{
    double raio = 1;
    double x = getHidranteX(hidrante);
    double y = getHidranteY(hidrante);
    char cor_p[22];
    char cor_b[22];
    char hSW[22];
    strcpy(cor_b, getHidranteCstrk(hidrante));
    strcpy(cor_p, getHidranteCfill(hidrante));
    strcpy(hSW, getHidranteSw(hidrante));

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, hSW,cor_p);
}

void desenhaSemaforo(Semaforo semaforo, FILE* arqSvg)
{
    double raio = 1;
    double x = getSemaforoX(semaforo);
    double y = getSemaforoY(semaforo);
    char cor_p[22];
    char cor_b[22];
    char sSW[22];
    strcpy(cor_b, getSemaforoCstrk(semaforo));
    strcpy(cor_p, getSemaforoCfill(semaforo));
    strcpy(sSW, getSemaforoSw(semaforo));

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, sSW, cor_p);
}

void desenhaRadioBase(Radiobase radiobase, FILE* arqSvg)
{
    double raio = 1;
    double x = getRadiobaseX(radiobase);
    double y = getRadiobaseY(radiobase);
    char cor_p[22];
    char cor_b[22];
    char rSW[22];
    strcpy(cor_b, getRadiobaseCstrk(radiobase));
    strcpy(cor_p, getRadiobaseCfill(radiobase));
    strcpy(rSW, getRadiobaseSw(radiobase));

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, rSW, cor_p);
}

void desenhaPosto(Posto posto, FILE* arqSvg)
{
    double x = getPontoX(posto);
    double y = getPontoY(posto);

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, 5, "green", "blue");
}

void desenhaLinha(Linha linha, FILE* arqSvg)
{
    double x1 = getLinhaX1(linha);
    double x2 = getLinhaX2(linha);
    double y1 = getLinhaY1(linha);
    double y2 = getLinhaY2(linha);
    char cor[22];
    strcpy(cor, getLinhaCor(linha));

    fprintf(arqSvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cor);

}

void desenhaLinhaTracejada(Linha linha, FILE* arqSvg)
{
    double x1 = getLinhaX1(linha);
    double x2 = getLinhaX2(linha);
    double y1 = getLinhaY1(linha);
    double y2 = getLinhaY2(linha);

    fprintf(arqSvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" stroke-dasharray=\"5\" />\n ", x1, y1, x2, y2);
}

void desenhaCirculoTransparente(Circulo circulo, FILE* arqSvg)
{
    double x = getCirculoX(circulo);
    double y = getCirculoY(circulo);
    double raio = getCirculoR(circulo);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getCirculoCorb(circulo));
    strcpy(cor_p, getCirculoCorp(circulo));

    fprintf(arqSvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"0.5\"/>\n ", x, y, raio, cor_b, cor_p);
}

void finalizaSvg(FILE* arqSvg)
{
    fprintf(arqSvg, "</svg>");
}

void desenhaGeoSvg(FILE* arqSvg, QuadTree treeObjeto[], Lista l)
{
    No no;

    void (*desenhar[8])(void*, FILE*) = {desenhaCirculo, desenhaRetangulo, escreveTexto, desenhaQuadra, desenhaHidrante, desenhaSemaforo, desenhaRadioBase, desenhaPosto};

    for(int i = 0; i < 8; i++)
    {
        percorreLarguraQt(treeObjeto[i],(void(*)(void*, void*))desenhar[i], arqSvg);
    }

    if(l != NULL)
    {
        for(no = getFirst(l); no != NULL; no = getNext(no))
        {
            fprintf(arqSvg,"\t<use xlink:href=\"#%d\"/>", *(int*)getInfo(no));
        }
    }
}

void gerarSvgQry(QuadTree treeObjeto[], FILE *saidaSvg, Lista listasQry[])
{
    desenhaGeoSvg(saidaSvg, treeObjeto, NULL);

    int i=0;

    if(i==0)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info textNum = getInfo(node);
            escreveTextoNumerico(textNum, saidaSvg);
        } 
        i++;
    }
    if(i==1)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetangulo(r, saidaSvg);           
        } 
        i++;
    }
    if(i==2)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinha(lin, saidaSvg);
        } 
        i++;
    }
    if(i==3)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculo(c, saidaSvg);
        } 
        i++;
    }
    if(i==4)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info t = getInfo(node);
            escreveTexto(t, saidaSvg);
        } 
        i++;
    }
    if(i==5)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloTracejado(r, saidaSvg);
        } 
        i++;
    }
    if(i==6)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloArredondado(r, saidaSvg);
        } 
        i++;
    }
    if(i==7)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinhaTracejada(lin, saidaSvg);
        } 
        i++;
    }
    if(i==8)
    {

        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculoTransparente(c, saidaSvg);
        }
    }
}