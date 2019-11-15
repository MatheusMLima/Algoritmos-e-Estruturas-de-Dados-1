#include <stdio.h>
#include <stdlib.h>

#define MAXGRAU 1000
#define INICIO 0
#define MAXTAM MAXGRAU

typedef struct SNo *TArvore;

typedef TArvore TItem;

typedef int TApontador;

typedef struct SLista {
    TItem Item[MAXTAM];
    TApontador Primeiro, Ultimo;
}TLista;

typedef int TDados;

typedef struct SNo {
    TDados Dados;
    TLista Filhos;
}TNo;

void TLista_Inicia(TLista *pLista)
{
    pLista->Primeiro = INICIO;
    pLista->Ultimo = pLista->Primeiro;
}

int TLista_EhVazia(TLista *pLista)
{
    return (pLista->Primeiro == pLista->Ultimo);
}

int TLista_Tamanho(TLista *pLista)
{
    return (pLista->Ultimo - pLista->Primeiro);
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x)
{
    TApontador q;
    if((pLista->Ultimo == MAXTAM) || (p < pLista->Primeiro) || (p > pLista->Ultimo)){
        return 0;
    }
    for(q = pLista->Ultimo-1; q >= p; q--){
        pLista->Item[q+1] = pLista->Item[q];
    }
    pLista->Item[p] = x;
    pLista->Ultimo++;
    return 1;
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX)
{
    TApontador q;
    if(TLista_EhVazia(pLista) || (p < pLista->Primeiro) || (p >= pLista->Ultimo)){
        return 0;
    }
    *pX = pLista->Item[p];
    for(q = p+1; q < pLista->Ultimo; q++){
        pLista->Item[q-1] = pLista->Item[q];
    }
    pLista->Ultimo--;
    return 1;
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
    return TLista_Insere(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos), SubArv);
}

TLista *TArvore_ListaDescendentes(TArvore Arvore)
{
    TLista *pLista, ListaArv;
    TArvore Arv;
    pLista = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(pLista);
    TLista_Inicia(&ListaArv);
    while (TLista_Retira(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos)-1, &Arv))
        TLista_Insere(&ListaArv, TLista_Tamanho(&ListaArv), Arv);
    while (TLista_Retira(&ListaArv, TLista_Tamanho(&ListaArv)-1, &Arv)) {
        TLista_Insere(&Arvore->Filhos, TLista_Tamanho(&Arvore->Filhos), Arv);
        TLista_Insere(pLista, TLista_Tamanho(pLista), Arv);
    }
    return pLista;
}

void TArvore_Imprime(TArvore Arvore)
{
    TLista *pLista;
    TArvore Arv;
    pLista = TArvore_ListaDescendentes(Arvore);
    printf("(%d", Arvore->Dados+1);
    while (TLista_Retira(pLista, 0, &Arv)){
        TArvore_Imprime(Arv);
    }
    printf(")");
    free(pLista);
}
