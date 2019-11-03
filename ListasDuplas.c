#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define MAX 50000

typedef struct SCelula *TApontador;

typedef struct SCelula{
    char Item;
    TApontador Ant, Prox;
}TCelula;

typedef struct{
    TApontador ultimo;
    int tamanho;
}Lista;

void inicia(Lista *lista);
int vazia(Lista *lista);
void insere(Lista *lista, TApontador p, char x);
int retira(Lista *lista, TApontador p, char *x);
TApontador retorna(Lista *lista, int p);

void inicia(Lista *lista)
{
    lista->ultimo = (TApontador) malloc(sizeof(TCelula));
    lista->ultimo->Prox = lista->ultimo;
    lista->ultimo->Ant = lista->ultimo;
    lista->tamanho = 0;
}

int vazia(Lista *lista)
{
    return(lista->ultimo->Prox == lista->ultimo);
}

void insere(Lista *lista, TApontador p, char x)
{
    TApontador novo;
    if(p == NULL){
        return 0;
    }
    novo = (TApontador) malloc(sizeof(TCelula));
    novo->Item = x;
    novo->Prox = p;
    novo->Ant = p->Ant;
    p->Ant->Prox = novo;
    if(p->Ant == lista->ultimo){
        lista->ultimo = novo;
    }
    p->Ant = novo;
    lista->tamanho++;
    return 1;
}

int retira(Lista *lista, TApontador p, char *x)
{
    TApontador aux;
    if(vazia(lista)){
        return 0;
    }
    aux = p;
    p->Ant->Prox = p->Prox;
    p->Prox->Ant = p->Ant;
    if(aux == lista->ultimo){
        lista->ultimo = p->Ant;
    }
    *x = aux->Item;
    free(aux);
    lista->tamanho--;
    return 1;
}

TApontador retorna(Lista *lista, int p)
{
    TApontador apontador;
    int posicao;
    posicao = 0;
    apontador = lista->ultimo->Prox->Prox;
    while((apontador != lista->ultimo->Prox) && (posicao != p)){
        apontador = apontador->Prox;
        posicao++;
    }
    return apontador;
}
