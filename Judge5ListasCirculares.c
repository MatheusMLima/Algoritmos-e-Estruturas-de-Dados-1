#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define MAX 50000

typedef struct lista{
    char frase[MAX];
    int tamanho, first, last;
}Lista;

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
                j = lista.first;
                break;
            case ']':
                j = lista.last;
                break;
            case '-':
                if(j > 0){
                    j--;
                    retira(&lista, j, &aux);
                }
                break;
            case '<':
                if(j > 0){
                    j--;
                }
                break;
            case '>':
                if(j < lista.last){
                    j++;
                }
                break;
            default:
                insere(&lista, j, texto[i]);
                j++;
        }
    }
    k = lista.tamanho;
    for(i=0;i<k;i++){
        printf("%c", lista.frase[i]);
    }
}
