#ifndef __LISTA__
#define __LISTA__

enum removerNoFlag{nodefree, allfree, semfree};

//Define "No" como um void pointer
typedef void* No;

//Define "Lista" como um void pointer
typedef void* Lista;

//Define "Info" como um void pointer
typedef void* Info;

/*
*Cria uma lista vazia
*Não precisa de parametros
*Retorna um void pointer para a lista que foi criada
*/
Lista create();

/*
*Cria um no
*Não precisa de parametros
*Retorna um no
*/
No criarNo();

/*
*Insere um no em uma lista
*Precisa de um void pointer info e de um void pointer lista
*Não retorna nada
*/
void insert(Lista l, Info info);

/*
*Obtem o primeiro elemento de uma lista
*Precisa de uma lista como parametro
*Retorna um void pointer para o primeiro no da lista
*/
No getFirst(Lista lista);

/*
*Obtem o ultimo elemento de uma lista
*Precisa de uma lista como parametro
*Retorna um void pointer para o ultimo no da lista
*/
No getLast(Lista lista);

int getTamanhoLista(Lista lista);

/*
*Obtem o elemento anterior do no que é passado como parametro 
*Precisa de um void pointer no
*Retorna um void pointer para o no anterior
*/
No getPrevious(No elemento);

/*
*Obtem o proximo elemento do no que é passado como parametro 
*Precisa de um void pointer no
*Retorna um void pointer para o proximo no
*/
No getNext(No elemento);

/*
*Obtem as informacoes do no 
*Precisa de um void pointer no
*Retorna um void pointer para as informacoes do no que foi passado como parametro
*/
Info getInfo(No elemento);

/*
*Insere um elemento depois
*Precisa da lista, do no a ser inserido e das informacoes
*Retorna nada.
*/
void insertAfter(Lista lista, No node, Info info);

/*
*Insere um elemento antes
*Precisa da lista, do no a ser inserido e das informacoes
*Retorna nada.
*/
void insertBefore(Lista lista, No node, Info info);

/*
*Remove um no da lista escolhida
*Precisa da lista e do no a ser excluido
*Retorna nada. 
*/
void removerNo(Lista lista, No no, int flag);

/*
*Remove as listas liberando a memoria
*Precisa da lista
*Retorna nada.
*/
void removeList(Lista l, void (*desaloca)(void*));

/*
*Obtem o tamanho da lista
*Precisa de parametro de listasObjetos
*Retorna o tamanho da lista
*/
int tamanhoDaLista(Lista listasObjetos);

/*
*Obtem a posicao para um determinado no
*Precisa de parametro de listasObjetos e a posicao desejada
*Retorna o no buscado caso achado ou um no igual a NULL caso nao encontrado
*/
No buscarPosicao(Lista listasObjetos[], int posicao);


#endif