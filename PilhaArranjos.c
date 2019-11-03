#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct pilha{
    int topo;
    float dado[MAX];
}t_pilha;

void Inicia(t_pilha *pilha);
void empilhar(float valor, t_pilha *pilha);
void desempilha(t_pilha *pilha, float *valor);
int Vazia(t_pilha *pilha);

void Inicia(t_pilha *pilha) {
    pilha->topo = 0;
}

void empilhar(float valor, t_pilha *pilha) {
    pilha->dado[pilha->topo] = valor;
    pilha->topo++;
}

void desempilha(t_pilha *pilha, float *valor) {
    pilha->topo--;
    *valor = pilha->dado[pilha->topo];
}

int Vazia(t_pilha *pilha) {
    if(pilha->topo == 0) {
        return 1;
    }else {
        return 0;
    }
}
