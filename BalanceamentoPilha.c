#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	char dado;
	struct elemento *proximo;
}t_elemento;

typedef struct pilha{
	t_elemento *topo;
	int tamanho;
}t_pilha;

void criaPilha(t_pilha *pilha) {
	pilha->topo = NULL;
	pilha->tamanho = 0;
}

void empilhar(char valor, t_pilha *pilha) {
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

int desempilha(t_pilha *pilha, char *valor) {
	char primer = pilha->topo->dado;
	t_elemento *removido;
	removido = pilha->topo;
	*valor = pilha->topo->dado;
	pilha->topo = pilha->topo->proximo;
	free(removido);
	pilha->tamanho--;
	return 1;
}

int esta_vazia(t_pilha *pilha) {
	if(pilha->topo == NULL) {
		return 1;
	}else {
		return 0;
	}
}

int tamanho_pilha(t_pilha *pilha) {
	return pilha->tamanho;
}

void imprimir(t_pilha *pilha){
    t_elemento *atual = pilha->topo;
    while(atual != NULL){
          printf("%d ",atual->dado);
          atual = atual->proximo;
    }
    printf("\nFIM DA PILHA\n");
}

char fixa(char *cadeia)
{
    int i, balanceada = 1;
    t_pilha *pilha;
    char c;
    pilha = (t_pilha *) malloc(sizeof(t_pilha));
    criaPilha(pilha);
    for (i = 0; balanceada && i < strlen(cadeia); i++) {
        switch (cadeia[i]) {
            case ')': if (desempilha(pilha, &c) && (c != '(')) balanceada = 0; break;
            case ']': if (desempilha(pilha, &c) && (c != '[')) balanceada = 0; break;
            default: empilhar(cadeia[i], pilha);
        }
    }
    while (! esta_vazia(pilha))
        desempilha(pilha, &c);
    free(pilha);
    return balanceada;
}

int main(void)
{
    char *cadeia = "([](([[[]]])]";
    if ( fixa(cadeia) )
        printf("Correto\n");
    else
        printf("Incorreto\n");
    return 0;
}
