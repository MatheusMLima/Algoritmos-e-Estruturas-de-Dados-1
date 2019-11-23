#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    int idade;
}Pessoa;

int main()
{
    FILE *f, *f1, *f2;
    Pessoa p;
    int teste[5], i;
    float teste2;
    char nome_arquivo[20], nome_arquivo1[20], nome_arquivo2[20], texto_armazenar[100];

    printf("Qual sera o nome do arquivo?\n");
    scanf("%s", nome_arquivo);

    printf("Qual sera o nome do arquivo 2?\n");
    scanf("%s", nome_arquivo2);

    printf("Qual sera o nome do arquivo binario?\n");
    scanf("%s", nome_arquivo1);

    sprintf(nome_arquivo,"%s.txt",nome_arquivo);
    sprintf(nome_arquivo1,"%s.txt",nome_arquivo1);
    sprintf(nome_arquivo2,"%s.txt",nome_arquivo2);

    f = fopen(nome_arquivo,"w"); //arquivo de texto
    f2 = fopen(nome_arquivo2,"w"); //arquivo de texto
    f1 = fopen(nome_arquivo1,"wb"); //arquivo binario

    printf("Insira valores para o vetor de teste!\n");
    for(i=0;i<5;i++){
        scanf("%d", &teste[i]);
    }

    printf("Insira um valor para o teste 2!\n");
    scanf("%f", &teste2);

    printf("Digite um nome!\n");
    scanf("%s", p.nome);

    printf("Digite uma idade!\n");
    scanf("%d", &p.idade);

    if(f == NULL || f1 == NULL || f2 == NULL){
        printf("Ocorreu um erro!");
    }else{
        printf("Entre com uma frase para ser armazenada no arquivo!\n");
        setbuf(stdin,NULL);
        scanf("%[^\n]", texto_armazenar);

        fputs(texto_armazenar,f2); //assim irá a frase toda de uma vez

        /*for(i=0; i<strlen(texto_armazenar);i++){
            fputc(texto_armazenar[i],f2);                desse modo irá colocar caractere por caractere no arquivo;
        }*/

        fwrite(teste,sizeof(int),5,f1);
        fwrite(&teste2,sizeof(float),1,f1);       //armazenar no arquivo binario
        fwrite(&p,sizeof(Pessoa),1,f1);

        fprintf(f,"Teste: %d %d %d %d %d\nTeste: %f\nNome: %s\nIdade: %d", teste[0], teste[1], teste[2], teste[3], teste[4], teste2, p.nome, p.idade); //escrever exatamente assim no arquivo de texto
    }
    fclose(f);
    fclose(f1);   //necessário lembrar de fechar
    fclose(f2);
}
