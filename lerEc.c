#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lerEc.h"

void lerEc(char arqEc[], QuadTree treeObjeto[], Lista listaObjeto[], HashTable hash[])
{
    char cnpj[20];
    char cpf[10];
    char cep[20];
    char face[2];
    char codt[20];
    char nome[300];
    char comando[5];
    char descricao[300];
    double num;
    Info info;

    FILE* ecArq;
    ecArq = fopen(arqEc, "r");

    if(ecArq == NULL)
    {
        printf("\nERRO\nArquivo .ec nao pode ser aberto\n");
        exit(1);
    }

    while(!feof(ecArq))
    {
        fscanf(ecArq, "%s", comando);

        if(strcmp(comando, "t") == 0)
        {
            fscanf(ecArq, "%s %s", codt, descricao);
            insertHTable(hash[1], codt, descricao);
            CodT codT = criaCod(codt, descricao);
            insert(listaObjeto[10], codT);

        }
        else if(strcmp(comando, "e") == 0)
        {
            fscanf(ecArq, "%s %s %s %s %s %lf %s", cnpj, cpf, codt, cep, face, &num, nome);
            info = getValue(hash[0], cep);
            if(info != NULL)
            {
                Comercio comercio = criaComercio(info, cnpj, cpf, face, codt, nome, num);
                insert(listaObjeto[9], comercio);
            }

        }
    }

    balancearQt(treeObjeto[9], listaObjeto[9], getComercioPonto, swapComercio);
    fclose(ecArq);
}