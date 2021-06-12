#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

typedef struct ht
{
    Lista *table;
    int tamanho;
}HashStruct;

typedef struct item
{
    char key[27];
    InfoTable value;
}ItemStruct;

HashTable createTable(int tamanho)
{
    HashStruct* ht = (HashStruct*) malloc(sizeof(HashStruct));
    ht->tamanho = tamanho;
    ht->table = (Lista*) malloc(sizeof(Lista) * tamanho);

    for(int i=0; i < tamanho; i++)
    {
        ht->table[i] = create();
    }

    return ht;
}

void insertHTable(HashTable t, char key[], InfoTable value)
{
    HashStruct *ht = (HashStruct*) t;
    ItemStruct *it = (ItemStruct*)malloc(sizeof(ItemStruct));
    int index = hashKey(key, ht->tamanho);
    strcpy(it->key, key);
    it->value = value;

    insert(ht->table[index], it);
}

int hashKey(char key[], int tam)
{
    int som = 0;
    int index;
    int j = strlen(key);

    for(int i=0; i < j; i++)
    {
        som = som + key[i];
    }

    index = som%tam;

    return index;

}

void deleteItemTable(HashTable t, char key[])
{
    HashStruct *ht = (HashStruct*) t;
    int index = hashKey(key, ht->tamanho);
    No aux = getFirst(ht->table[index]);

    while(aux != NULL)
    {
        No aux2 = aux;
        aux = getNext(aux);

        ItemStruct* htaux = (ItemStruct*)getInfo(aux2);
        int result = strcmp(htaux->key, key);

        if(result == 0)
        {
            removerNo(ht->table[index], aux2, 1);
        }
    }
    
}

InfoTable getValue(HashTable t, char key[])
{
    HashStruct *ht = (HashStruct*) t;
    int index = hashKey(key, ht->tamanho);

    for(No aux = getFirst(ht->table[index]); aux != NULL; aux = getNext(aux))
    {
        ItemStruct *it = (ItemStruct*) getInfo(aux);

        if(strcmp(it->key, key) == 0)
        {
            return it->value;
        }
    }

    return NULL;
}

void deleteHTable(HashTable t)
{
    HashStruct *ht = (HashStruct*) t;

    for(int i=0; i < ht->tamanho; i++)
    {
        No aux = getFirst(ht->table[i]);
        while(aux != NULL)
        {
            No aux2 = aux;
            aux = getNext(aux);
            ItemStruct* htaux = (ItemStruct*)getInfo(aux2);

            free(htaux->value);
            removerNo(ht->table[i], aux2, 1);
        }
        
    }

    for(int i=0; i < ht->tamanho; i++)
    {
        free(ht->table[i]);
    }

    free(ht->table);
    free(ht);
}
