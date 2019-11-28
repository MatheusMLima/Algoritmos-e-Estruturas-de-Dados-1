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
Celula configura(int forca, int participante, int forcaI);

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

Celula configura(int forca, int participante, int forcaI){
    Celula novo;
    novo.participante = participante;
    novo.forca = forca;
    novo.forcaI = forcaI;
    return novo;
}

int main()
{
    Fila fila;
    Celula p1, p2, aux;
    int N, K, i, poder, poderF;
    inicia(&fila);
    scanf("%d %d", &N, &K);
    for(i=0;i<pow(2,N);i++){
        scanf("%d", &poder);
        aux = configura(poder, i+1, poder);
        colocafila(&fila, aux);
    }
    while(fila.tamanho!=1){
        tirarfila(&fila,&p1);
        tirarfila(&fila,&p2);
        if(p1.forca >= p2.forca){
            poderF = (p1.forca - p2.forca) + K;
            if(poderF < p1.forcaI){
                aux = configura(poderF, p1.participante, p1.forcaI);
                colocafila(&fila, aux);
            }else{
                aux = configura(p1.forcaI, p1.participante, p1.forcaI);
                colocafila(&fila, aux);
            }
        }else{
            poderF = (p2.forca - p1.forca) + K;
            if(poderF < p2.forcaI){
                aux = configura(poderF, p2.participante, p2.forcaI);
                colocafila(&fila, aux);
            }else{
                aux = configura(p2.forcaI, p2.participante, p2.forcaI);
                colocafila(&fila, aux);
            }
        }
    }
    tirarfila(&fila,&p1);
    printf("%d\n", p1.participante);
}
