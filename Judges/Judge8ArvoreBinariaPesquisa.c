#include <stdio.h>
#include <stdlib.h>

typedef struct No *ArvBin;

struct No{
    int info;
    struct No *esq;
    struct No *dir;
};

ArvBin *cria_ArvBin()
{
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz !=  NULL){
        *raiz = NULL;
    }
    return raiz;
}

void posOrdem_Arv(ArvBin *raiz)
{
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_Arv(&((*raiz)->esq));
        posOrdem_Arv(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int insere_Arv(ArvBin *raiz, int valor)
{
    if(raiz == NULL){
        return 0;
    }
    struct No *novo;
    novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        struct No *atual = *raiz;
        struct No *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor > ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

int main()
{
    ArvBin *raiz, *raiz1;
    raiz = cria_ArvBin();
    raiz1 = cria_ArvBin();
    int T,i,n;
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d", &n);
        insere_Arv(raiz,n);
    }
    for(i=0;i<T;i++){
        scanf("%d", &n);
        insere_Arv(raiz1,n);
    }
    posOrdem_Arv(raiz);
}
