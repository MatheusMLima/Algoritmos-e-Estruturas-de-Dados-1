#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef int TVertice;

typedef int TAresta;

typedef struct{
    int IncideAresta;
    TAresta Aresta;
}TAdjacencia;

typedef struct{
    TAdjacencia Adj[MAX][MAX];
    TAresta quantidade[MAX];
    int NVertices;
    int NArestas;
}TGrafo;

int inicia(TGrafo *grafo, int vertices)
{
    TVertice u,v;
    if(vertices > MAX){
        return 0;
    }
    grafo->NVertices = vertices;
    grafo->NArestas = 0;
    for(u = 0; u < grafo->NVertices; u++){
        for(v = 0; v < grafo->NVertices; v++){
            grafo->Adj[u][v].IncideAresta = 0;
            grafo->quantidade[u] = 0;
        }
    }
    grafo->quantidade[u] = 0;
    grafo->NVertices = vertices;
    return 1;
}

int ExisteAresta(TGrafo *grafo, TVertice u, TVertice v)
{
    return grafo->Adj[u][v].IncideAresta;
}

int InsereAresta(TGrafo *grafo, TVertice u, TVertice v)
{
    grafo->Adj[u][v].IncideAresta = 1;
    grafo->quantidade[u] += 1;
    grafo->NArestas++;
    return 1;
}

void lista_adj(TGrafo *grafo, TVertice u)
{
    TVertice v;
    for(v = 1; v <= grafo->NVertices; v++){
        if(ExisteAresta(grafo,u,v)){
            printf("%d ", v);
        }
    }
}

void verifica(TGrafo *grafo, TVertice u, int *quant)
{
    TVertice v;
    for(v = 1; v <= grafo->NVertices; v++){
        if(ExisteAresta(grafo,v,u)){
            *quant += 1;
        }
    }
}

int main()
{
    int i,d, quant = 0;
    TVertice u,v,n;
    TGrafo grafo;
    scanf("%d %d", &n, &d);
    inicia(&grafo,n);
    for(i=0;i<d;i++){
        scanf("%d %d", &u, &v);
        InsereAresta(&grafo,u,v);
    }
    for(u=1;u<=n;u++){
        quant = 0;
        verifica(&grafo,u,&quant);
        printf("%d %d %d ", u, quant, grafo.quantidade[u]);
        lista_adj(&grafo,u);
        printf("\n");
    }
}
