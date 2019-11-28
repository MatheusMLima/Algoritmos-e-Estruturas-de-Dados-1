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

int main()
{
    Fila fila;
    int N, K, i, poder, poderF, part1, part2, poder2, poderF2, poderF3;
    inicia(&fila);
    scanf("%d %d", &N, &K);
    for(i=0;i<pow(2,N);i++){
        scanf("%d", &poder);
        colocafila(&fila, poder, i+1, poder);
    }
    while(fila.tamanho!=1){
        tirarfila(&fila,&poderF,&part1,&poder);
        tirarfila(&fila,&poderF2,&part2,&poder2);
        if(poderF >= poderF2){
            poderF3 = (poderF - poderF2) + K;
            if(poderF3 < poder){
                colocafila(&fila, poderF3, part1, poder);
            }else{
                colocafila(&fila, poder, part1, poder);
            }
        }else{
            poderF3 = (poderF2 - poderF) + K;
            if(poderF3 < poder2){
                colocafila(&fila, poderF3, part2, poder2);
            }else{
                colocafila(&fila, poder2, part2, poder2);
            }
        }
    }
    tirarfila(&fila,&poderF2,&part2,&poder2);
    printf("%d\n", part2);
}
