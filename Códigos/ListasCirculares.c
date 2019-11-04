#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define MAX 50000

typedef struct lista{
    char frase[MAX];
    int tamanho, first, last;
}Lista;

void inicia(Lista *lista);
int vazia(Lista *lista);
int insere(Lista *lista, int p, char x);
int retira(Lista *lista, int p, char *x);

void inicia(Lista *lista)
{
    lista->first = INICIO;
    lista->last = lista->first;
    lista->tamanho = 0;
}

int vazia(Lista *lista)
{
    return (lista->first == lista->last);
}

int insere(Lista *lista, int p, char x)
{
    int q;
    if((lista->last == MAX) || (p < lista->first) || (p > lista->last)){
        return 0;
    }
    for(q = lista->last-1; q >= p; q--){
        lista->frase[q+1] = lista->frase[q];
    }
    lista->frase[p] = x;
    lista->last++;
    lista->tamanho++;
    return 1;
}

int retira(Lista *lista, int p, char *x)
{
    int q;
    if((vazia(lista)) || (p < lista->first) || (p >= lista->last)){
        return 0;
    }
    *x = lista->frase[p];
    for(q = p+1; q < lista->last; q++){
        lista->frase[q-1] = lista->frase[q];
    }
    lista->last--;
    lista->tamanho--;
    return 1;
}
