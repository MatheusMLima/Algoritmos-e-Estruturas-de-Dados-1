#include <stdio.h>
#include "NumeroComplexo.h"

int main()
{
    complex complexo;
    complex1 complexo1;
    complex2 complexo2;
    char a;
    while(a!='6'){
        printf("Menu:\n1)Atribuir valores\n2)Mostrar na forma 'R + Ci'\n3)Copiar um valor para o outro\n4)Somar dois numeros complexos\n5)Testar se eh real\n6)Sair\n");
        scanf("%s", &a);
        switch(a){
            case '1':
                atribuir(&complexo,&complexo1,&complexo2);
            break;
            case '2':
                imprimir(complexo,complexo1,complexo2);
            break;
            case '3':
                trocar(&complexo,&complexo2);
            break;
            case '4':
                somar(&complexo,&complexo1,&complexo2);
            break;
            case '5':
            break;
        }
    }
}

void atribuir(complex *pcomplexo, complex1 *pcomplexo1, complex2 *pcomplexo2)
{
    printf("Valor para o numero real:\n");
    scanf("%f", &pcomplexo->real);
    printf("Valor para o numero imaginario:\n");
    scanf("%f", &pcomplexo->imaginario);
    printf("Valor para o numero real:\n");
    scanf("%f", &pcomplexo1->real1);
    printf("Valor para o numero imaginario:\n");
    scanf("%f", &pcomplexo1->imaginario1);
    pcomplexo2->real2 = 0;
    pcomplexo2->imaginario2 = 0;

}

void imprimir(complex complexo, complex1 complexo1, complex2 complexo2)
{
    if(complexo2.real2 == 0 && complexo2.imaginario2 == 0){
        printf("primeiro numero: %.2f + %.2fi\n", complexo.real, complexo.imaginario);
        printf("segundo numero: %.2f + %.2fi\n", complexo1.real1, complexo1.imaginario1);
    } else {
        printf("primeiro numero: %.2f + %.2fi\n", complexo.real, complexo.imaginario);
        printf("segundo numero: %.2f + %.2fi\n", complexo1.real1, complexo1.imaginario1);
        printf("terceiro numero: %.2f + %.2fi\n", complexo2.real2, complexo2.imaginario2);
    }
    
}

void trocar(complex *pcomplexo, complex2* pcomplexo2)
{
    pcomplexo2->real2 = pcomplexo->real;
    pcomplexo2->imaginario2 = pcomplexo->imaginario;
}

void somar(complex *pcomplexo, complex1 *pcomplexo1, complex2 *pcomplexo2)
{
    pcomplexo2->real2 = pcomplexo->real + pcomplexo1->real1;
    pcomplexo2->imaginario2 = pcomplexo->imaginario + pcomplexo1->imaginario1;
    printf("A soma sera: %.2f + %.2fi\n", pcomplexo2->real2, pcomplexo2->imaginario2);
}
