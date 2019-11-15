#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct fila_prioridade FilaPrio;

struct paciente{
    char nome[30];
    int prio;
};

struct fila_prioridade{
    int qtd;
    struct paciente dados[MAX];
};

FilaPrio *cria_FilaPrio(){
    FilaPrio *fila;
    fila = (FilaPrio*)malloc(sizeof(struct fila_prioridade));
    if(fila != NULL){
        fila->qtd = 0;
    }
    return fila;
}

void libera_FilaPrio(FilaPrio *fila)
{
    free(fila);
}

int tamanho_FilaPrio(FilaPrio *fila)
{
    if(fila == NULL){
        return -1;
    }else{
        return fila->qtd;
    }
}

int estaCheia_FilaPrio(FilaPrio *fila)
{
    if(fila == NULL){
        return -1;
    }
    return (fila->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio *fila)
{
    if(fila == NULL){
        return -1;
    }
    return (fila->qtd == 0);
}

void promoverElemento(FilaPrio *fila, int filho)
{
    int pai;
    struct paciente temp;
    pai = (filho - 1)/2;
    while((filho > 0) && (fila->dados[pai].prio <= fila->dados[filho].prio)){
        temp = fila->dados[filho];
        fila->dados[filho] = fila->dados[pai];
        fila->dados[pai] = temp;
        filho = pai;
        pai = (pai - 1)/2;
    }
}

int insere_FilaPrio(FilaPrio *fila, char *nome, int prio)
{
    if(fila == NULL){
        return 0;
    }
    if(fila->qtd == MAX){
        return 0;
    }
    strcpy(fila->dados[fila->qtd].nome,nome);
    fila->dados[fila->qtd].prio = prio;
    promoverElemento(fila,fila->qtd);
    fila->qtd++;
    return 1;
}

void rebaixarElemento(FilaPrio *fila, int pai)
{
    struct paciente temp;
    int filho = 2*pai+1;
    while(filho < fila->qtd){
        if(filho < fila->qtd-1){
            if(fila->dados[filho].prio < fila->dados[filho+1].prio){
                filho++;
            }
        }
        if(fila->dados[pai].prio >= fila->dados[filho].prio){
            break;
        }
        temp = fila->dados[pai];
        fila->dados[pai] = fila->dados[filho];
        fila->dados[filho] = temp;
        pai = filho;
        filho = 2*pai+1;
    }
}

int remove_FilaPrio(FilaPrio *fila, char *info)
{
    if(fila == NULL){
        return 0;
    }
    if(fila->qtd == 0){
        return 0;
    }
    strcpy(info,fila->dados[0].nome);
    fila->qtd--;
    fila->dados[0] = fila->dados[fila->qtd];
    rebaixarElemento(fila,0);
    return 1;
}

int consulta_FilaPrio(FilaPrio *fila, char *info)
{
    if(fila == NULL || fila->qtd == 0){
        return 0;
    }
    strcpy(info,fila->dados[0].nome);
    return 1;
}

int main()
{
    FilaPrio *fila;
}




