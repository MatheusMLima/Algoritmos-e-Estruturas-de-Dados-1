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
void operacao(t_pilha *pilha, char pos[]);


int main()
{
    t_pilha pilha;
    char pos[MAX];
    Inicia(&pilha);
    scanf("%s", pos);
    operacao(&pilha,pos);
}

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
