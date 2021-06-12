#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"

void lerGeo(char arqGeo[], char nomeSvgGeo[], QuadTree treeObjeto[], Lista listaObjeto[], HashTable hash[])
{
    FILE *geo;
    Info info;
    char id1[20];
    double raio, distancia = 0;
    int max[5] = {1000, 1000, 1000, 1000, 1000};
    char id2[20];
    char txt[255];
    int n = 0;
    char tipo[10];
    char cep[20];
    double x, y, h, w, d;
    char expessura[20];
    char hidraExpessura[20] = "2";
    char semaExpessura[20] = "2";
    char quaExpessura[20] = "2";
    char radioExpessura[20] = "2";
    char circleExpessura[20] = "2";
    char rectExpessura[20] = "2";
    char borda[22]; 
    char preenchimento[22];
    char Qborda[22] = "black", Qpreenchimento[22] = "red";
    char RBborda[22] = "black", RBpreenchimento[22] = "green";
    char Sborda[22] = "black", Spreenchimento[22] = "red";
    char Hborda[22] = "black", Hpreenchimento[22] = "yellow";

    geo = fopen(arqGeo,"r");

    if(geo == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }

    FILE *arqSvg;
    arqSvg = fopen(nomeSvgGeo, "w");

    if(arqSvg == NULL)
    {
        printf("\nERRO\nArquivo .svg nao pode ser aberto\n");
        exit(1);
    }
    
    iniciaSvg(arqSvg);
    
    while(!feof(geo))
    {
        fscanf(geo, "%s", tipo);

        if(strcmp(tipo, "nx")==0)
        {
            fscanf(geo,"%d\n", &max[0]);
        }
        else if(strcmp(tipo, "c")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %s %s\n", id1, &raio, &x, &y, borda, preenchimento);
            Circulo circulo = criaCirculo(id1, raio, x, y, circleExpessura, borda, preenchimento);
            insert(listaObjeto[0], circulo); 
            
            n++;
        }
        else if(strcmp(tipo, "r")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf %s %s\n", id1, &w, &h, &x, &y, borda, preenchimento);
            Retangulo retangulo = criaRetangulo(id1, w, h, x, y, rectExpessura, borda, preenchimento);
            insert(listaObjeto[1], retangulo);
            
            n++;
        }
        else if(strcmp(tipo, "t")==0)
        {
            fscanf(geo,"%s %lf %lf %s %s", id1, &x, &y, borda, preenchimento);
            fgets(txt, 255, geo);
            Texto texto = criaTexto(id1, x, y, borda, preenchimento, txt);
            insert(listaObjeto[2], texto);
        }
        else if(strcmp(tipo, "q")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf\n", cep, &x, &y, &w, &h);
            Quadra quadra = criaQuadra(cep, x, y, w, h, quaExpessura, Qpreenchimento, Qborda);
            insert(listaObjeto[3], quadra);
            
            n++;
        }
        else if(strcmp(tipo, "h")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Hidrante hidrante = criaHidrante(id2, x, y, hidraExpessura, Hpreenchimento, Hborda);
            insert(listaObjeto[4], hidrante);

            n++;
        }
        else if(strcmp(tipo, "s")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Semaforo semaforo = criaSemaforo(id2, x, y, semaExpessura, Spreenchimento, Sborda);
            insert(listaObjeto[5], semaforo);
            
            n++;
        }
        else if(strcmp(tipo, "rb")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id2, &x, &y);
            Radiobase radioBase = criaRadiobase(id2, x, y, radioExpessura, RBpreenchimento, RBborda);
            insert(listaObjeto[6], radioBase);
            
            n++;
        }
        else if(strcmp(tipo, "cq")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(quaExpessura, expessura);
            strcpy(Qpreenchimento, preenchimento);
            strcpy(Qborda, borda); 

            n++;
        }
        else if(strcmp(tipo, "ch")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(hidraExpessura, expessura);
            strcpy(Hpreenchimento, preenchimento);
            strcpy(Hborda, borda);

            n++;
        }
        else if(strcmp(tipo, "cr")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);

            strcpy(radioExpessura, expessura);
            strcpy(RBpreenchimento, preenchimento);
            strcpy(RBborda, borda);

            n++;
        }
        else if(strcmp(tipo, "cs")==0)
        {
            fscanf(geo,"%s %s %s\n", expessura, preenchimento, borda);
            
            strcpy(semaExpessura, expessura);
            strcpy(Spreenchimento, preenchimento);
            strcpy(Sborda, borda);

            n++;
        }
        else if(strcmp(tipo, "sw")==0)
        {
            fscanf(geo,"%s %s\n", circleExpessura, rectExpessura); 

            n++;
        }
        else if(strcmp(tipo, "ps")==0)
        {
            fscanf(geo,"%lf %lf\n",&x, &y);
            Posto posto = criaPosto(x, y, distancia);
            insert(listaObjeto[7], posto);
        
            n++;
        }
        else if(strcmp(tipo, "dd")==0)
        {
            fscanf(geo,"%lf %lf %lf %lf %lf\n", &x, &y, &w, &h, &d);
            Densidade densidade = criaDensidade(x, y, w, h, d);
            insert(listaObjeto[8], densidade);

            n++;
        }
    }

    // void* (*getPonto[8])(void*) = {getCirculoPonto, getRetanguloPonto, getTextoPonto, getQuadraPonto, getHidrantePonto,
    // getSemaforoPonto, getRadiobasePonto, NULL};

    // void (*swap[8])(void*, void*) = {swapCirculo, swapRetangulo, swapTexto, swapQuadra, swapHidrante,
    // swapSemaforo, swapRB, swapPonto};
    
    balancearQt(treeObjeto[0], listaObjeto[0], getCirculoPonto, swapCirculo);
    balancearQt(treeObjeto[1], listaObjeto[1], getRetanguloPonto, swapRetangulo);
    balancearQt(treeObjeto[2], listaObjeto[2], getTextoPonto, swapTexto);
    balancearQt(treeObjeto[3], listaObjeto[3], getQuadraPonto, swapQuadra);
    balancearQt(treeObjeto[4], listaObjeto[4], getHidrantePonto, swapHidrante);
    balancearQt(treeObjeto[5], listaObjeto[5], getSemaforoPonto, swapSemaforo);
    balancearQt(treeObjeto[6], listaObjeto[6], getRadiobasePonto, swapRB);
    balancearQt(treeObjeto[7], listaObjeto[7], NULL, swapPonto);

    for(No no = getFirst(listaObjeto[3]); no != NULL; no = getNext(no))
    {
        info = getInfo(no);
        insertHTable(hash[0], getQuadraCep(info), info);
    }
    
    desenhaGeoSvg(arqSvg, treeObjeto, NULL);

    finalizaSvg(arqSvg);

    fclose(geo);

}

