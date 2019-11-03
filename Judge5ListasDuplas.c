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

int main()
{
    Lista lista;
    inicia(&lista);
    char texto[MAX], aux;
    int i, j, k;
    i=0;
    while(i < MAX){
        scanf("%c", &aux);
        if(aux == '\n'){
            break;
        }
        texto[i] = aux;
        i++;
    }
    j=0;
    for(i=0;i<strlen(texto);i++){
        switch(texto[i]){
            case '[':
                j = INICIO;
                break;
            case ']':
                j = lista.tamanho;
                break;
            case '-':
                if(j > 0){
                    j--;
                    retira(&lista, retorna(&lista, j), &aux);
                }
                break;
            case '<':
                if(j > 0){
                    j--;
                }
                break;
            case '>':
                if(j < lista.tamanho){
                    j++;
                }
                break;
            default:
                insere(&lista, retorna(&lista, j), texto[i]);
                j++;
        }
    }
    k = lista.tamanho;
    j = 0;
    for(i=k-1;i>=0;i--){
        retira(&lista, retorna(&lista, j), &aux);
        printf("%c", aux);
    }
}
