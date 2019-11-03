#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct itens{
    int participante, forca, forcaI;
    struct Itens *prox;
}Itens;

typedef struct{
    Itens *first, *last;
    int tamanho;
}Fila;

void inicia(Fila *fila);
int colocafila(Fila *fila, int poder, int participante, int poderInicial);
int tirarfila(Fila *fila, int *poder, int *participante, int *poderInicial);

void inicia(Fila *fila)
{
    fila->first = NULL;
    fila->last = NULL;
    fila->tamanho = 0;
}

int colocafila(Fila *fila, int poder, int participante, int poderInicial)
{
    Itens *novo;
    novo = (Itens *) malloc(sizeof(Itens));
    novo->prox = NULL;
    novo->forca = poder;
    novo->forcaI = poderInicial;
    novo->participante = participante;
    if(fila->tamanho == 0){
        fila->first = novo;
    }else{
        fila->last->prox = novo;
    }
    fila->last = novo;
    fila->tamanho++;
    return 1;
}

int tirarfila(Fila *fila, int *poder, int *participante, int *poderInicial)
{
    Itens *p;
    if(fila->tamanho == 0){
        return 0;
    }
    p = fila->first;
    *poder = fila->first->forca;
    *poderInicial = fila->first->forcaI;
    *participante = fila->first->participante;
    fila->first = fila->first->prox;
    fila->tamanho--;
    free(p);
    return 1;
}
