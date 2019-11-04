#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, **unidade, **a, *aluno, *aux1, aux, *conta, capacidade, *cont, *bloco, quantidade = 0, i, j, *alunos, codigo_uni;
    scanf("%d", &n);
    unidade = (int **) calloc(n,sizeof(int*));
    a = (int **) calloc(n,sizeof(int*));
    alunos = (int *) malloc(n*sizeof(int));
    cont = (int *) malloc(n*sizeof(int));
    conta = (int *) malloc(n*sizeof(int));
    aux1 = (int *) malloc(n*sizeof(int));
    aluno = (int *) malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d %d", &unidade[i], &alunos[i]);
        aux1[i] = unidade[i];
        aluno[i] = alunos[i];
        cont[i] = 0;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(aluno[i]>aluno[j]){
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }
    for(i=0;i<n;i++){
        unidade[i] = (int *) calloc(aluno[n-1],sizeof(int));
        a[i] = (int *) calloc(aluno[n-1],sizeof(int));
        unidade[i][0] = aux1[i];
    }
    scanf("%d", &capacidade);
    bloco = (int *) malloc(capacidade*sizeof(int));
    while(codigo_uni!=(-1)){
        scanf("%d", &codigo_uni);
        for(i=0;i<n;i++){
            if(aux1[i]==codigo_uni){
                for(j=0;j<aluno[n-1];j++){
                    if(unidade[i][j]==0){
                        scanf("%d", &unidade[i][j]);
                        quantidade++;
                        cont[i]++;
                        break;
                    }
                }
            }
        }
        if(capacidade==quantidade){
            capacidade = 2*capacidade;
            bloco = (int *) malloc(capacidade*sizeof(int));
        }
    }
    for(i=0;i<n;i++){
        conta[i] = (cont[i]*100)/alunos[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(conta[i]>conta[j]){
                aux = conta[i];
                conta[i] = conta[j];
                conta[j] = aux;
                a[i] = unidade[i];
                unidade[i] = unidade[j];
                unidade[j] = a[i];
            }
        }
    }
    i=0;
    printf("%d\n", unidade[i][0]);
    for(j=1;j<aluno[n-1];j++){
        if(unidade[i][j]!=0){
            printf("%d\n", unidade[i][j]);
        }
    }
    for(i=0;i<n;i++){
        free(a[i]);
        free(unidade[i]);
    }
    free(a);
    free(unidade);
    free(alunos);
    free(cont);
    free(conta);
    free(aux1);
    free(aluno);
    free(bloco);
}
