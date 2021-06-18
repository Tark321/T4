#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerQry.h"

void lerQry (char saidaQry[], QuadTree treeObjeto[], HashTable hashT[], char arqQry[], Lista listasQry[], Lista listaObjeto[])
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    if(qry == NULL)
    {
        printf("Erro ao abrir o QRY ");
    }

    FILE* saida = fopen(saidaTxt,"w");
    if(saida == NULL)
    {
        printf("Erro ao gerar o TXT\n");
        exit(1);
    }

    FILE* arqSaidaSvg = fopen(saidaSvg, "w");

    if(arqSaidaSvg == NULL)
    {
        printf("Erro ao abrir o arquivo de saida qry\n");
        exit(1);
    }

    iniciaSvg(arqSaidaSvg);

    char j[20];
    char k[20];
    char cnpj[20];
    char cpf[10];
    int ident, jj, kk;
    double x;
    double y;
    char tipo[5];
    char corb[20];
    char corp[20];
    char identificacao[20];
    double r;
    char parametroOpcional[1];
    char complemento[30];
    double w, h;
    char face[2];
    char cep [20];
    char aux[20];
    char sfx[20];
    char t;
    double num;
    double n;

    while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%s %s", j, k);
            fprintf(saida,"%s %s %s\n", tipo, j, k);
            o(j, k, saida, treeObjeto, listasQry);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%s %lf %lf", j,&x,&y);
            fprintf(saida,"%s %s %lf %lf\n", tipo, j, x, y);
            i(treeObjeto, j, x, y, saida, listasQry);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%s %s %s", j,corb,corp);
            fprintf(saida,"%s %s %s %s\n",tipo,j,corb,corp);
            pnt(treeObjeto, j, corb, corp, saida);

        }
        else if(strcmp(tipo,"pnt*") == 0)
        {
            fscanf(qry,"%d %d %s %s", &jj, &kk,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,jj,kk,corb,corp);
            
            for(int cont = jj; cont <= kk; cont++)
            {
                sprintf(j, "%d", cont);
                pnt(treeObjeto, j, corb, corp, saida);
            }
        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%s", j);
            fprintf(saida,"%s %s\n", tipo, j);
            delf(treeObjeto, j, saida);
        }
        else if(strcmp(tipo,"delf*") == 0)
        {
            fscanf(qry,"%d %d", &jj, &kk);
            fprintf(saida,"%s %d %d\n",tipo,jj,kk);
            
            for(int cont = jj; cont <= kk; cont++)
            {
                sprintf(j, "%d", cont);
                delf(treeObjeto, j, saida);
            }
        }
        else if(strcmp(tipo, "dq") == 0) 
        {
            
            fscanf(qry,"%s", parametroOpcional);

            if(strcmp(parametroOpcional,"#")==0)
            {
                ident=1;
                fscanf(qry,"%s %lf",identificacao, &r);
                fprintf(saida,"dq# %s %lf\n", identificacao, r);
            }
            else
            {
                ident=0;
                fscanf(qry,"%lf", &r);
                strcpy(identificacao, parametroOpcional);
                fprintf(saida,"dq %s %lf\n",identificacao, r);
            }
            dq(treeObjeto, saida, identificacao, r, ident, listasQry, arqSaidaSvg);
        }
        else if(strcmp(tipo, "del")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            del(treeObjeto, identificacao, saida, listasQry);
        }
           else if(strcmp(tipo, "cbq")==0)
        {
            fscanf(qry,"%lf %lf %lf %s",&x, &y, &r, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n",tipo,x, y, r, corb);
            cbq(treeObjeto, x, y, r, corb, saida);
        }
        else if(strcmp(tipo, "crd?")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            crd(treeObjeto, identificacao, saida);
        }
        else if(strcmp(tipo, "car")==0)
        {
            fscanf(qry,"%lf %lf %lf %lf",&x, &y, &w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n",tipo, x, y, w, h);
            car(treeObjeto, x, y, w, h, saida, listasQry);
        }
        else if(strcmp(tipo, "cv")==0)
        {
            fscanf(qry,"%lf %s %s %lf",&n, cep, face, &num);
            fprintf(saida,"cv %lf %s %s %lf\n", n, cep, face, num);
            cv(treeObjeto, n, cep, face, num, listasQry);
        }
        else if(strcmp(tipo, "soc")==0)
        {
            fscanf(qry,"%d %s %s %lf", &kk, cep, face, &num);
            fprintf(saida,"soc %s %s %s %lf\n", k, cep, face, num);
            soc(treeObjeto, kk, cep, face, num, saida, listasQry);
        }
        else if(strcmp(tipo, "ci")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
            ci(saida, treeObjeto, x, y, r, listasQry, arqSaidaSvg);
        }
        else if(strcmp(tipo, "m?") == 0)
        {
            fscanf(qry, "%s", cep);
            fprintf(saida,"%s %s\n",tipo, cep);
            m(saida, treeObjeto, cep);
        }
        else if(strcmp(tipo, "dm?") == 0)
        {
            fscanf(qry, "%s", cpf);
            fprintf(saida,"%s %s\n",tipo, cpf);
            dm(saida, treeObjeto, listasQry, hashT, cpf);
        }
        else if(strcmp(tipo, "de?") == 0)
        {
            fscanf(qry, "%s", cnpj);
            de(treeObjeto, saida, hashT, cnpj);
            
        }
        else if(strcmp(tipo, "mud") == 0)
        {
            fscanf(qry, "%s %s %s %lf %s", cpf, cep, face, &num, complemento);
            mud(treeObjeto, listasQry, hashT, saida, cpf, cep, face, complemento, num);
        }
        else if(strcmp(tipo, "dmprbt") == 0)
        {
            fscanf(qry, "%c %s", &t, sfx);
            fprintf(saida, "%s: %c %s\n", tipo, t, sfx);
            dmprbt(treeObjeto, t, saidaQry, sfx);
        }
        else if(strcmp(tipo, "eplg?") == 0)
        {
            fscanf(qry, "%s %lf %lf %lf %lf", aux, &x, &y, &w, &h);
            fprintf(saida, "%s: %s %lf %lf %lf %lf\n", tipo, aux, x, y, w, h);
            epgl(treeObjeto, saida, listasQry, hashT, x, y, w, h, aux);
        }
        else if(strcmp(tipo, "catac") == 0)
        {
            fscanf(qry, "%lf %lf %lf", &x, &y, &r);
            fprintf(saida, "%s: %lf %lf %lf\n", tipo, x, y, r);
            catac(treeObjeto, saida, x, y, r, listasQry, hashT);
        }
    }

    gerarSvgQry(treeObjeto, arqSaidaSvg, listasQry);

    finalizaSvg(arqSaidaSvg);

    fclose(saida);
    fclose(qry);
    fclose(arqSaidaSvg);
    free(saidaSvg);
    free(saidaTxt);
}

