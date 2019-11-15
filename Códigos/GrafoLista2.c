#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;

struct grafo{
    int nro_vertices;
    int grau_max;
    int **arestas;
    int *grau;
};

Grafo *cria_Grafo(int nro_vertices, int grau_max)
{
    Grafo *gr = (Grafo *) malloc(sizeof(struct grafo));
    if(gr!=NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->grau = (int *) calloc(nro_vertices,sizeof(int));
        gr->arestas = (int **) malloc(nro_vertices*sizeof(int*));
        for(i=0;i<nro_vertices;i++){
            gr->arestas[i] = (int *) malloc(grau_max*sizeof(int));
        }
    }
    return gr;
}

void libera_Grafo(Grafo *gr)
{
    if(gr != NULL){
        int i;
        for(i=0;i<gr->nro_vertices;i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo *gr, int orig, int dest)
{
    if(gr == NULL){
        return 0;
    }
    if(orig < 0 || orig >= gr->nro_vertices){
        return 0;
    }
    if(dest < 0 || dest >= gr->nro_vertices){
        return 0;
    }
    gr->arestas[orig][gr->grau[orig]] = dest;
    gr->grau[orig]++;
    return 1;
}

int removeAresta(Grafo *gr, int orig, int dest, int eh_digrafo)
{
    if(gr == NULL){
        return 0;
    }
    if(orig < 0 || orig >= gr->nro_vertices){
        return 0;
    }
    if(dest < 0 || dest >= gr->nro_vertices){
        return 0;
    }
    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i]!=dest){
        i++;
    }
    if(i == gr->grau[orig]){
        return 0;
    }
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL){
        return;
    }
    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            printf("%d ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Grafo *gr;
    gr = cria_Grafo(10,7);
    insereAresta(gr,1,8);
    insereAresta(gr,1,5);
    insereAresta(gr,1,3);
    insereAresta(gr,2,6);
    insereAresta(gr,3,4);
    imprime_Grafo(gr);

}
