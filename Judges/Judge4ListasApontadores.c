#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define MAX 1000

typedef struct SCelula{
    char criancas[20];
    struct TCelula *prox;
}TCelula;

typedef struct SCelula *Ponteiro;

typedef struct lista{
    TCelula *first, *last;
    int tamanho;
}Lista;

void Inicia(Lista *lista)
{
    lista->first = NULL;
    lista->last = lista->first;
    lista->tamanho = 0;
}

Ponteiro retorna(Lista *lista, int p)
{
    Ponteiro ponteiro;
    int posicao;
    posicao = 0;
    ponteiro = lista->first;
    while((ponteiro != NULL) && (posicao != p)){
        ponteiro = ponteiro->prox;
        posicao++;
    }
    return ponteiro;
}

int insereprimeiro(Lista *lista, char x[]){
    TCelula *novo;
    novo = (TCelula *) malloc(sizeof(TCelula));
    strcpy(novo->criancas, x);
    novo->prox = lista->first;
    if(lista->first == NULL){
        lista->last = novo;
    }
    lista->first = novo;
    lista->tamanho++;
    return 1;
}

int insereultima(Lista *lista, char x[]){
    TCelula *novo;
    novo = (TCelula *) malloc(sizeof(TCelula));
    strcpy(novo->criancas, x);
    novo->prox = NULL;
    if(lista->first == NULL){
        lista->first = novo;
    }else{
        lista->last->prox = novo;
    }
    lista->last = novo;
    lista->tamanho++;
    return 1;
}

int insere(Lista *lista, int p, char x[], int N)
{
    TCelula *antes, *novo;
    int i;
    if(p == 0){
        return insereprimeiro(lista,x);
    }else if(p == lista->tamanho){
        return insereultima(lista,x);
    }else if((p < 1) || (p > lista->tamanho)){
        return 0;
    }else{
        i = 2;
        antes = lista->first;
        while(i != p){
            antes = antes->prox;
            i++;
        }
        novo = (TCelula *) malloc(sizeof(TCelula));
        strcpy(novo->criancas, x);
        novo->prox = antes->prox;
        antes->prox = novo;
        lista->tamanho++;
        return 1;
    }
}

int retiraprimeiro(Lista *lista, char *x[]){
    TCelula *aux;
    if(lista->first == NULL){
        return 0;
    }
    aux = lista->first;
    lista->first = aux->prox;
    strcpy(x,aux->criancas);
    free(aux);
    lista->tamanho--;
    return 1;
}

int retiraultimo(Lista *lista, char *x[]){
    TCelula *antes, *aux;
    antes = lista->first;
    if(antes == lista->last){
        return retiraprimeiro(lista, x);
    }else{
        while(antes->prox != lista->last){
            antes = antes->prox;
        }
        aux = lista->last;
        antes->prox = NULL;
        lista->last = antes;
        strcpy(x,aux->criancas);
        free(aux);
        lista->tamanho--;
        return 1;
    }
}

int retira(Lista *lista, Ponteiro p, char *x[], int N)
{
    TCelula *antes, *aux;
    if(p == lista->first){
        return retiraprimeiro(lista, x);
    }else if(p == lista->last){
        return retiraultimo(lista, x);
    }else{
        antes = lista->first;
        while ((antes != lista->last) && (antes->prox != p)){
            antes = antes->prox;
        }
        if(antes == lista->last){
            return 0;
        }
        aux = antes->prox;
        antes->prox = aux->prox;
        strcpy(x,aux->criancas);
        free(aux);
        lista->tamanho--;
        return 1;
    }
}

int main()
{
    Lista lista;
    Inicia(&lista);
    int N, K, i, Kinicial = 0, aux1 = 0;
    char nome[20], a[20];
    scanf("%d %d", &N, &K);
    for(i=0;i<N;i++){
        scanf("%s", nome);
        insere(&lista, i, nome, N);
    }
    Kinicial = K;
    aux1 = lista.tamanho;
    for(i=0;i<N;i++){
        K = K%aux1;
        retira(&lista, retorna(&lista,K), &a, N);
        K += Kinicial;
        aux1--;
        printf("%s\n", a);
    }
}
