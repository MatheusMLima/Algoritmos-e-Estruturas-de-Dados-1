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

void libera_NO(struct No *no)
{
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_arv(ArvBin *raiz)
{
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

int estaVazia(ArvBin *raiz)
{
    if((raiz == NULL) || (*raiz == NULL)){
        return 1;
    }
    return 0;
}

int altura_Arv(ArvBin *raiz)
{
    if((raiz == NULL) || (*raiz == NULL)){
        return 0;
    }
    int alt_esq = altura_Arv(&((*raiz)->esq));
    int alt_dir = altura_Arv(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir + 1);
    }
}

int totalNo_Arv(ArvBin *raiz)
{
    if((raiz == NULL) || (*raiz == NULL)){
        return 0;
    }
    int alt_esq = totalNo_Arv(&((*raiz)->esq));
    int alt_dir = totalNo_Arv(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

void preOrdem_Arv(ArvBin *raiz)
{
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_Arv(&((*raiz)->esq));
        preOrdem_Arv(&((*raiz)->dir));
    }
}

void emOrdem_Arv(ArvBin *raiz)
{
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_Arv(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_Arv(&((*raiz)->dir));
    }
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

struct No *remove_atual(struct No *atual)
{
    struct No *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_Arv(ArvBin *raiz, int valor)
{
    if(raiz == NULL){
        return 0;
    }
    struct No *ant = NULL;
    struct No *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }else{
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
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

int main()
{
    ArvBin *raiz;
}

