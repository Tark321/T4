#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "lista.h"

typedef void *InfoTable;
typedef void *HashTable;

HashTable createTable(int tamanho);

void insertHTable(HashTable t, char key[], InfoTable value);

int hashKey(char key[], int tam);

void deleteItemTable(HashTable t, char key[]);

InfoTable getValue(HashTable t, char key[]);

void deleteHTable(HashTable t);



#endif