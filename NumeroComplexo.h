//definicao do tipo
typedef struct{
    float real;
    float imaginario;
} complex;

typedef struct{
    float real1;
    float imaginario1;
} complex1;

typedef struct{
    float real2;
    float imaginario2;
} complex2;

//funcoes

void somar(complex*,complex1*,complex2*);
void atribuir(complex*,complex1*,complex2*);
void imprimir(complex,complex1,complex2);
void trocar(complex*,complex2*);
