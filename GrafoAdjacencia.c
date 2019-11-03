#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int TVertice;

typedef int TAresta;

typedef struct{
    int IncideAresta;
    TAresta Aresta;
}TAdjacencia;

typedef struct{
    TAdjacencia Adj[MAX][MAX];
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
        for(v = 0; u < grafo->NVertices; v++){
            grafo->Adj[u][v].IncideAresta = 0;
        }
    }
    grafo->NVertices = vertices;
    return 1;
}

int ExisteAresta(TGrafo *grafo, TVertice u, TVertice v)
{
    return grafo->Adj[u][v].IncideAresta;
}

int InsereAresta(TGrafo *grafo, TVertice u, TVertice v, TAresta e)
{
    grafo->Adj[u][v].IncideAresta = 1;
    grafo->Adj[u][v].Aresta = e;
    grafo->NArestas++;
    return 1;
}

int RetiraAresta(TGrafo *grafo, TVertice u, TVertice v, TAresta *e)
{
    if(ExisteAresta(grafo, u, v)==0){
        printf("Nao existe aresta para ser retirada\n\n\n\n");
        return 0;
    }
    *e = grafo->Adj[u][v].Aresta;
    grafo->Adj[u][v].IncideAresta = 0;
    grafo->NArestas--;
    return 1;
}

void lista_adj(TGrafo *grafo, TVertice u)
{
    TVertice v;
    int i = 0;
    for(v = 0; v < grafo->NVertices; v++){
        if(ExisteAresta(grafo,u,v)){
            printf("%d\n", v);
            i++;
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
