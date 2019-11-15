#include <stdio.h>
#include <stdlib.h>

typedef struct SNo *TArvore;

typedef TArvore TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula {
    TItem Item;
    TApontador Prox;
}TCelula;

typedef struct {
    TApontador Primeiro, Ultimo;
    int Tamanho;
}TLista;

typedef int TDados;

typedef struct SNo {
    TDados Dados;
    TLista Filhos;
}TNo;

void TLista_Inicia(TLista *pLista)
{
    pLista->Primeiro = NULL;
    pLista->Ultimo = pLista->Primeiro;
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista)
{
    return (pLista->Primeiro == NULL);
}

int TLista_Tamanho(TLista *pLista)
{
    return (pLista->Tamanho);
}

int TLista_InserePrimeiro(TLista *pLista, TItem x)
{
    TApontador pNovo;
    pNovo = (TApontador) malloc(sizeof(TCelula));
    pNovo->Item = x;
    pNovo->Prox = pLista->Primeiro;
    if(TLista_EhVazia(pLista)){
        pLista->Ultimo = pNovo;
    }
    pLista->Primeiro = pNovo;
    pLista->Tamanho++;
    return 1;
}

int TLista_InsereUltimo(TLista *pLista, TItem x)
{
    TApontador pNovo;
    pNovo = (TApontador) malloc(sizeof(TCelula));
    pNovo->Item = x;
    pNovo->Prox = NULL;
    if(TLista_EhVazia(pLista)){
        pLista->Primeiro = pNovo;
    }else{
        pLista->Ultimo->Prox = pNovo;
        pLista->Ultimo = pNovo;
        pLista->Tamanho++;
        return 1;
    }
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    TApontador pAnterior, pNovo;
    if(p == pLista->Primeiro){
        return TLista_InserePrimeiro(pLista, x);
    }else if(p == NULL){
        return TLista_InsereUltimo(pLista, x);
    }else{
        pAnterior = pLista->Primeiro;
        while((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p)){
            pAnterior = pAnterior->Prox;
        }
        if(pAnterior == pLista->Ultimo){
            return 0;
        }
        pNovo = (TApontador) malloc(sizeof(TCelula));
        pNovo->Item = x;
        pNovo->Prox = pAnterior->Prox;
        pAnterior->Prox = pNovo;
        pLista->Tamanho++;
        return 1;
    }
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX)
{
    TApontador pAux;
    if (TLista_EhVazia(pLista)){
        return 0;
    }
    pAux = pLista->Primeiro;
    pLista->Primeiro = pAux->Prox;
    *pX = pAux->Item;
    free(pAux);
    pLista->Tamanho--;
    return 1;
}

int TLista_RetiraUltimo(TLista *pLista, TItem *pX)
{
    TApontador pAnterior, pAux;
    pAnterior = pLista->Primeiro;
    if(pAnterior == pLista->Ultimo){
        return TLista_RetiraPrimeiro(pLista, pX);
    }else{
        while (pAnterior->Prox != pLista->Ultimo){
            pAnterior = pAnterior->Prox;
        }
        pAux = pLista->Ultimo;
        pAnterior->Prox = NULL;
        pLista->Ultimo = pAnterior;
        *pX = pAux->Item;
        free(pAux);
        pLista->Tamanho--;
        return 1;
    }
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    TApontador pAnterior, pAux;
    if(p == pLista->Primeiro){
        return TLista_RetiraPrimeiro(pLista, pX);
    }else if(p == pLista->Ultimo){
        return TLista_RetiraUltimo(pLista, pX);
    }else{
        pAnterior = pLista->Primeiro;
        while((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p)){
            pAnterior = pAnterior->Prox;
        }
        if(pAnterior == pLista->Ultimo){
            return 0;
        }
        pAux = pAnterior->Prox;
        pAnterior->Prox = pAux->Prox;
        *pX = pAux->Item;
        free(pAux);
        pLista->Tamanho--;
        return 1;
    }
}

TApontador TLista_Retorna(TLista *pLista, int p)
{
    TApontador q;
    int pos;
    pos = 0;
    q = pLista->Primeiro;
    while((q != NULL) && (pos != p)){
        q = q->Prox;
        pos++;
    }
    return q;
}

void TArvore_Inicia(TArvore Arvore, TDados x)
{
    Arvore->Dados = x;
    TLista_Inicia(&Arvore->Filhos);
}

int TArvore_EhExterno(TArvore Arvore)
{
    return (TLista_Tamanho(&Arvore->Filhos) == 0);
}

int TArvore_NDescendentes(TArvore Arvore)
{
    return TLista_Tamanho(&Arvore->Filhos);
}

int TArvore_Insere(TArvore Arvore, TArvore SubArv)
{
    return TLista_Insere(&Arvore->Filhos, TLista_Retorna(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos)), SubArv);
}

TLista *TArvore_ListaDescendentes(TArvore Arvore)
{
    TLista *pLista, ListaArv;
    TArvore Arv;
    pLista = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(pLista);
    TLista_Inicia(&ListaArv);
    while(TLista_Retira(&Arvore->Filhos, TLista_Retorna(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos)-1), &Arv)){
        TLista_Insere(&ListaArv, TLista_Retorna(&ListaArv, TLista_Tamanho(&ListaArv)), Arv);
    }
    while(TLista_Retira(&ListaArv, TLista_Retorna(&ListaArv, TLista_Tamanho(&ListaArv)-1), &Arv)){
        TLista_Insere(&Arvore->Filhos, TLista_Retorna(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos)), Arv);
        TLista_Insere(pLista, TLista_Retorna(pLista, TLista_Tamanho(pLista)), Arv);
    }
    return pLista;
}

void TArvore_Imprime(TArvore Arvore)
{
    TLista *pLista;
    TArvore Arv;
    pLista = TArvore_ListaDescendentes(Arvore);
    printf("(%d", Arvore->Dados+1);
    while(TLista_Retira(pLista, TLista_Retorna(pLista, 0), &Arv)){
        TArvore_Imprime(Arv);
    }
    printf(")");
    free(pLista);
}

int main()
{
    int i, pai, filho, N, M;
    TNo No[1000];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++){
        TArvore_Inicia(&No[i], i);
    }
    for(i = 0; i < M; i++){
        scanf("%d %d", &pai, &filho);
        TArvore_Insere(&No[pai-1], &No[filho-1]);
    }
    TArvore_Imprime(&No[0]);
}
