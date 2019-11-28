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
Celula Ajeita(char nome[]);

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

Celula Ajeita(char nome[]){
    Celula novo;
    strcpy(novo.nomes, nome);
    return novo;
}

int main()
{
    Lista lista;
    Celula aux;
    Inicia(&lista);
    int N, K, i, Kinicial, aux1;
    char nome[20];
    scanf("%d %d", &N, &K);
    for(i=0;i<N;i++){
        scanf("%s", nome);
        insere(&lista, i, Ajeita(nome));
    }
    Kinicial = K;
    aux1 = lista.last;
    for(i=0;i<N;i++){
        K = K%aux1;
        retira(&lista, K, &aux);
        K += Kinicial;
        aux1--;
        printf("%s\n", aux.nomes);
    }
}
