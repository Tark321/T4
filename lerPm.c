#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lerPm.h"

void lerPm(char arqPm[], QuadTree treeObjeto[], Lista listaObjeto[], HashTable hash[])
{
    char cep[20];
    char face[2];
    char comando[5];
    char sexo[5];
    char cpf[10];
    char sobrenome[30];
    char nome[30];
    char nascimento[11];
    char complemento[30];
    double num;
    Info info;

    FILE* pmArq;
    pmArq = fopen(arqPm,"r");

    if(pmArq == NULL)
    {
        printf("\nERRO\nArquivo .pm nao pode ser aberto\n");
        exit(1);
    }

       while(!feof(pmArq))
    {
        fscanf(pmArq, "%s", comando);

        if(strcmp(comando, "p") == 0)
        {
            fscanf(pmArq, "%s %s %s %s %s", cpf, nome, sobrenome, sexo, nascimento);
            Pessoa pessoa = cadastraPessoa(cpf, nome, sobrenome, nascimento, sexo);
            insert(listaObjeto[11], pessoa);
            insertHTable(hash[2], cpf, pessoa);
        }
        else if(strcmp(comando, "m") == 0)
        {
            fscanf(pmArq, "%s %s %s %lf %s", cpf, cep, face, &num, complemento);
            info = getValue(hash[0], cep);
            if(info != NULL)
            {
                Address address = criaAddress(info, cpf, face, num, complemento);
                DadosPessoais dados = cadastraDados(cpf, address);
                insert(listaObjeto[12], address);
                insert(listaObjeto[13], dados);
            }
        }
    }

    balancearQt(treeObjeto[10], listaObjeto[12], getAddressPonto, swapAddress);

    for(No node = getFirst(listaObjeto[12]); node != NULL; node = getNext(node))
    {
        info = getInfo(node);
        insertHTable(hash[3], getAddressCpf(info), info);
    }
    fclose(pmArq);
}