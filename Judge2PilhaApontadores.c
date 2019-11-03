#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct elemento {
    float dado;
    struct elemento *proximo;
}t_elemento;

typedef struct pilha{
    t_elemento *topo;
    int tamanho;
}t_pilha;

void Inicia(t_pilha *pilha);
void empilhar(float valor, t_pilha *pilha);
void desempilha(t_pilha *pilha, float *valor);
int Vazia(t_pilha *pilha);
void operacao(t_pilha *pilha, char pos[]);


int main()
{
    t_pilha *pilha;
    char pos[MAX];
    int i;
    pilha = (t_pilha *) malloc(sizeof(t_pilha));
    Inicia(pilha);
    scanf("%s", pos);
    operacao(pilha,pos);
    free(pilha);
}

void Inicia(t_pilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

void empilhar(float valor, t_pilha *pilha) {
    t_elemento *novo = (t_elemento*)malloc(sizeof(t_elemento));
    novo->dado = valor;
    novo->proximo = NULL;
    if(pilha->topo == NULL){
        pilha->topo = novo;
        pilha->tamanho++;
    }else {
        novo->proximo = pilha->topo;
        pilha->topo = novo;
        pilha->tamanho++;
    }
}

void desempilha(t_pilha *pilha, float *valor) {
    t_elemento *removido;
    removido = pilha->topo;
    *valor = pilha->topo->dado;
    pilha->topo = pilha->topo->proximo;
    free(removido);
    pilha->tamanho--;
}

int Vazia(t_pilha *pilha) {
    if(pilha->topo == NULL) {
        return 1;
    }else {
        return 0;
    }
}

void operacao(t_pilha *pilha, char pos[])
{
    int i;
    float recebe1=0, recebe2=0, resultado=0, numero=0, resultadoFinal=0;
    for(i=0;i<strlen(pos);i++){
        switch(pos[i]){
            case '+':
                desempilha(pilha,&recebe1);
                desempilha(pilha,&recebe2);
                resultado = recebe2+recebe1;
                empilhar(resultado,pilha);
                break;
            case '-':
                desempilha(pilha,&recebe1);
                desempilha(pilha,&recebe2);
                resultado = recebe2-recebe1;
                empilhar(resultado,pilha);
                break;
            case '/':
                desempilha(pilha,&recebe1);
                desempilha(pilha,&recebe2);
                resultado = recebe2/recebe1;
                empilhar(resultado,pilha);
                break;
            case '*':
                desempilha(pilha,&recebe1);
                desempilha(pilha,&recebe2);
                resultado = recebe2*recebe1;
                empilhar(resultado,pilha);
                break;
            default:
                scanf("%f", &numero);
                empilhar(numero,pilha);
                break;
        }
    }
    desempilha(pilha,&resultadoFinal);
    printf("%f", resultadoFinal);
}
