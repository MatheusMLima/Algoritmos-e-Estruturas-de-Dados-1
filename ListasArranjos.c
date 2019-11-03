#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define MAX 1000

typedef struct{
    char nomes[20];
}Celula;

typedef struct{
    Celula criancas[MAX];
    int first, last;
}Lista;

void Inicia(Lista *lista);
int insere(Lista *lista, int p, Celula x);
int retira(Lista *lista, int p, Celula *x);

void Inicia(Lista *lista)
{
    lista->first = INICIO;
    lista->last = lista->first;
}

int insere(Lista *lista, int p, Celula x)
{
    int q;
    if((lista->last == MAX) || (p<lista->first)  || (p>lista->last)){
        return 0;
    }
    for(q = lista->last-1; q >= p; q--){
        lista->criancas[q+1] = lista->criancas[q];
    }
    lista->criancas[p] = x;
    lista->last++;
    return 1;
}

int retira(Lista *lista, int p, Celula *x)
{
    int q;
    if((lista->first == lista->last) || (p<lista->first) || (p>=lista->last)){
        return 0;
    }
    *x = lista->criancas[p];
    for(q = p+1; q<lista->last;q++){
        lista->criancas[q-1] = lista->criancas[q];
    }
    lista->last--;
    return 1;
}
