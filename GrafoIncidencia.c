#include <stdio.h>
#include <stdlib.h>

#define MAXARESTAS 100
#define MAXVERTICES 100

typedef int TVertice;

typedef int TAresta;

typedef struct{
    int IncideAresta;
    TAresta Aresta;
}TAdjacencia;

typedef struct{
    TAdjacencia Adj[MAXVERTICES][MAXARESTAS];
    int NVertices;
    int NArestas;
}TGrafo;

int inicia(TGrafo *grafo, int vertices)
{
    TVertice u,v;
    if(vertices > MAXVERTICES){
        return 0;
    }
    grafo->NVertices = vertices;
    grafo->NArestas = 0;
    return 1;
}

int ExisteAresta(TGrafo *grafo, TVertice u, TVertice v)
{
    TAresta e;
    for(e = 0; e < grafo->NArestas; e++){
        if((grafo->Adj[u][e].IncideAresta > 0) && (grafo->Adj[v][e].IncideAresta < 0)){
            return 1;
        }
    }
    return 0;
}

int InsereAresta(TGrafo *grafo, TVertice u, TVertice v, TAresta e)
{
    TVertice i;
    if(grafo->NArestas >= MAXARESTAS){
        return 0;
    }
    for(i = 0; i < grafo->NVertices; i++){
        grafo->Adj[i][grafo->NArestas].IncideAresta = 0;
    }
    grafo->Adj[u][grafo->NArestas].IncideAresta = 1;
    grafo->Adj[v][grafo->NArestas].IncideAresta = -1;
    grafo->Adj[u][grafo->NArestas].Aresta = e;
    grafo->Adj[v][grafo->NArestas].Aresta = e;
    grafo->NArestas++;
    return 1;
}

int RetiraAresta(TGrafo *grafo, TVertice u, TVertice v, TAresta *e)
{
    TVertice i;
    TAresta ee;
    if(ExisteAresta(grafo, u, v)==0){
        printf("Nao existe aresta para ser retirada\n\n\n\n");
        return 0;
    }
    for(ee = 0; ee < grafo->NArestas; ee++){
        if((grafo->Adj[u][ee].IncideAresta > 0) && (grafo->Adj[v][ee].IncideAresta < 0)){
            break;
        }
    }
    *e = grafo->Adj[u][ee].Aresta;
    for(i = 0; i < grafo->NVertices; i++){
        grafo->Adj[i][ee] = grafo->Adj[i][grafo->NArestas-1];
    }
    grafo->NArestas--;
    return 1;
}

void lista_adj(TGrafo *grafo, TVertice u)
{
    TVertice v;
    TAresta e;
    int i = 0;
    for(e = 0; e < grafo->NArestas; e++){
        if(grafo->Adj[u][e].IncideAresta > 0){
            for(v = 0; v < grafo->NVertices; v++){
                if(grafo->Adj[v][e].IncideAresta < 0){
                    printf("%d\n", v);
                    i++;
                }
            }
        }
    }
    if(i==0){
        printf("Nao existe nenhum adjacente desse vertice!\n");
    }
    printf("\n\n\n\n");
}

int NVertices_(TGrafo *grafo){
    return (grafo->NVertices);
}

int NArestas_(TGrafo *grafo){
    return (grafo->NArestas);
}

int main()
{
    TGrafo grafo;
    TVertice u,v;
    TAresta a;
    int vertices, n, j = 1, i;
    printf("Digite a quantidade de vertices que tera seu grafo!\n");
    scanf("%d", &vertices);
    inicia(&grafo,vertices);
    while(j>0){
        printf("Escolha a operacao que sera realizada!\n");
        printf("1) Inserir novas arestas.\n2) Retirar arestas.\n3) Quantidade de vertices.\n4) Quantidade de arestas.\n");
        printf("5) Lista de adjacentes.\n6) Existe arestas?\n7) Sair\n");
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("Entre quais vertices voce deseja inserir a aresta?\n");
                scanf("%d %d", &u, &v);
                printf("O que voce deseja colocar na aresta?\n");
                scanf("%d", &a);
                InsereAresta(&grafo,u,v,a);
                printf("\n\n\n");
                break;
            case 2:
                printf("Entre quais vertices voce deseja retirar a aresta?\n");
                scanf("%d %d", &u, &v);
                i = RetiraAresta(&grafo,u,v,&a);
                if(i==0){
                    break;
                }else{
                    printf("Deseja ver o conteudo da aresta?\n1) Sim\n2) Nao\n");
                    scanf("%d", &i);
                    if(i == 1){
                        printf("%d\n\n\n\n", a);
                    }else if(i == 2){
                        printf("\n\n\n\n");
                        break;
                    }
                }
                break;
            case 3:
                printf("%d\n\n\n\n", NVertices_(&grafo));
                break;
            case 4:
                printf("%d\n\n\n\n", NArestas_(&grafo));
                break;
            case 5:
                printf("Insira o vertice do qual voce quer ver a lista de adjacentes!\n");
                scanf("%d", &u);
                lista_adj(&grafo,u);
                break;
            case 6:
                printf("Digite os vertices dos quais voce quer verificar se existe alguma aresta!\n");
                scanf("%d %d", &u, &v);
                if(ExisteAresta(&grafo,u,v)==1){
                    printf("Existe!\n");
                }else{
                    printf("Nao existe!\n");
                }
                printf("\n\n\n");
                break;
            case 7:
                j = 0;
                break;
        }
    }

}
