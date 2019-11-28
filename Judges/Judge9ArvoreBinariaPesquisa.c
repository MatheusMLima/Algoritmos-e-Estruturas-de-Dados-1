#include <stdio.h>
#include <stdlib.h>

typedef struct No *ArvBin;

struct No{
    int info;
    struct No *esq;
    struct No *dir;
};

ArvBin *cria_ArvBin();
int insere_Arv(ArvBin *raiz, int valor);
int consulta_Arv(ArvBin *raiz, int valor);
void imprime_Arv(ArvBin *raiz);
void sucessor(ArvBin *q, ArvBin *r);
int remove_Arv(ArvBin *raiz, int x);

ArvBin *cria_ArvBin()
{
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz !=  NULL){
        *raiz = NULL;
    }
    return raiz;
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

int consulta_Arv(ArvBin *raiz, int valor)
{
    if(raiz == NULL){
        return 0;
    }
    struct No *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

void imprime_Arv(ArvBin *raiz)
{
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("(C%d", (*raiz)->info);
        imprime_Arv(&((*raiz)->esq));
        if((*raiz)->esq == NULL){
            printf("()");
        }
        imprime_Arv(&((*raiz)->dir));
        if((*raiz)->dir == NULL){
            printf("()");
        }
        printf(")");
    }
}

void sucessor(ArvBin *q, ArvBin *r)
{
    if ((*r)->esq != NULL)
        sucessor(q, &(*r)->esq);
    else {
        (*q)->info = (*r)->info;
        *q = *r;
        *r = (*r)->dir;
    }
}

int remove_Arv(ArvBin *raiz, int x)
{
    ArvBin *p, q;
    p = raiz;
    while ((*p != NULL) && (x != (*p)->info)) {
        if (x < (*p)->info)
            p = &(*p)->esq;
        else if (x > (*p)->info)
            p = &(*p)->dir;
    }
    if (*p != NULL) {
        q = *p;
        if (q->esq == NULL)
            *p = q->dir;
        else if (q->dir == NULL)
            *p = q->esq;
        else
            sucessor(&q, &q->dir);
        free(q);
        return 1;
    }
    return 0;
}

int main()
{
    ArvBin *raiz;
    raiz = cria_ArvBin();
    int T,i,n=0,pesquisa=0,v=0;
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d ", &n);
        insere_Arv(raiz,n);
    }
    scanf("%d",&v);
    pesquisa = consulta_Arv(raiz,v);
    if(pesquisa == 0){
        insere_Arv(raiz,v);
    }else{
        remove_Arv(raiz,v);
    }
    imprime_Arv(raiz);
}
