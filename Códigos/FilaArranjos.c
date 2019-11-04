#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 65536

typedef struct SCelula{
    int participante, forca, forcaI;
}Celula;

typedef struct{
    Celula participantes[MAX];
    int frente, tras, tamanho;
}Fila;

void inicia(Fila *fila);
int colocafila(Fila *fila, Celula valor);
int tirarfila(Fila *fila, Celula *valor);

void inicia(Fila *fila){
    fila->frente = 0;
    fila->tras = fila->frente;
}

int colocafila(Fila *fila, Celula valor){
    if(fila->frente == (fila->tras+1)%MAX){
        return 0;
    }else{
        fila->participantes[fila->tras] = valor;
        fila->tras = (fila->tras+1)%MAX;
        fila->tamanho++;
        return 1;
    }
}

int tirarfila(Fila *fila, Celula *valor){
    if(fila->frente==fila->tras){
        return 0;
    }else{
        *valor = fila->participantes[fila->frente];
        fila->frente = (fila->frente+1)%MAX;
        fila->tamanho--;
        return 1;
    }
}
