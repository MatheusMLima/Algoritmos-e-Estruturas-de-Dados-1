#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct grafo Grafo;

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int **arestas;
    int *grau;
    int *quantidade;
    int *quant;
};

Grafo *cria_Grafo(int nro_vertices)
{
    Grafo *gr = (Grafo *) malloc(sizeof(struct grafo));
    if(gr!=NULL){
        int i;
        nro_vertices += 1;
        gr->nro_vertices = nro_vertices;
        gr->grau = (int *) calloc(nro_vertices,sizeof(int));
        gr->arestas = (int **) malloc(nro_vertices*sizeof(int*));
        gr->quantidade = (int *) calloc(nro_vertices,sizeof(int));
        gr->quant = (int *) calloc(nro_vertices,sizeof(int));
        for(i=0;i<nro_vertices;i++){
            gr->arestas[i] = (int *) malloc(MAX*sizeof(int));
        }
    }
    return gr;
}

int insereAresta(Grafo *gr, int orig, int dest)
{
    if(gr == NULL){
        return 0;
    }
    if(orig < 0 || orig > gr->nro_vertices){
        return 0;
    }
    if(dest < 0 || dest > gr->nro_vertices){
        return 0;
    }
    gr->arestas[orig][gr->grau[orig]] = dest;
    gr->grau[orig] += 1;
    gr->quantidade[orig] += 1;
    gr->quant[dest] += 1;
    return 1;
}

void imprimelista(Grafo *gr, int orig)
{
    if(gr == NULL){
        return;
    }
    int i,j;
    for(i=orig;i<gr->nro_vertices;i++){
        for(j=0;j<gr->grau[i];j++){
            printf("%d ", gr->arestas[i][j]);
        }
        break;
    }
}

void libera_Grafo(Grafo *gr)
{
    if(gr != NULL){
        int i;
        for(i=0;i<gr->nro_vertices;i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);
        free(gr->quant);
        free(gr->quantidade);
        free(gr->grau);
        free(gr);
    }
}

int main()
{
    int i,d,u,v,n;
    Grafo *gr;
    scanf("%d %d", &n, &d);
    gr = cria_Grafo(n);
    for(i=0;i<d;i++){
        scanf("%d %d", &u, &v);
        insereAresta(gr,u,v);
    }
    for(u=1;u<=n;u++){
        printf("%d %d %d ", u, gr->quant[u], gr->quantidade[u]);
        imprimelista(gr,u);
        printf("\n");
    }
    libera_Grafo(gr);
}
