#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int idade;
}Pessoa;

int main()
{
    FILE *f, *f1, *f2;
    Pessoa p;
    int teste[5], i, teste1[5];
    float teste2, teste3;
    char nome_arquivo[30], nome_arquivo1[30], nome_arquivo2[20], texto[100], c, nome[20];

    printf("Digite o nome do arquivo de texto que deseja abrir!\n");
    scanf("%s", nome_arquivo);
    sprintf(nome_arquivo,"%s.txt", nome_arquivo);

    printf("Digite o nome do arquivo de texto que deseja abrir!\n");
    scanf("%s", nome_arquivo2);
    sprintf(nome_arquivo2,"%s.txt", nome_arquivo2);

    printf("Digite o nome do arquivo binario que deseja abrir!\n");
    scanf("%s", nome_arquivo1);
    sprintf(nome_arquivo1,"%s.txt", nome_arquivo1);

    f = fopen(nome_arquivo,"r");
    f2 = fopen(nome_arquivo2,"r");
    f1 = fopen(nome_arquivo1,"rb");

    fread(teste,sizeof(int),5,f1);
    fread(&teste2,sizeof(float),1,f1);        //ira ler o que esta contido no arquivo binario
    fread(&p,sizeof(Pessoa),1,f1);

    printf("\nTeste: %d %d %d %d %d\nTeste 2: %f\nNome: %s\nIdade: %d\n\n", teste[0], teste[1], teste[2], teste[3], teste[4], teste2, p.nome, p.idade);

    c = fgetc(f2);
    while(!feof(f2)){
        printf("%c", c);     //ira mostrar todo o conteudo string dentro do arquivo de texto
        c = fgetc(f2);
    }
    printf("\n\n");

    rewind(f2);       //ira voltar no começo

    fseek(f2,4*sizeof(char),SEEK_SET); //ira pular 4 posições char a partir do começo

    c = fgetc(f2);
    while(!feof(f2)){
        printf("%c", c);     //agora ira mostrar a frase a partir da posição que chegou ao pular anteriormente
        c = fgetc(f2);
    }
    printf("\n\n");

    rewind(f2);     //retornar ao começo para fazer outro teste

    fgets(texto,100,f2);
    printf("%s\n\n", texto);      //outra maneira de ver o conteudo string dentro do arquivo de texto

    fscanf(f,"%s %d %d %d %d %d", texto, &teste1[0], &teste1[1], &teste1[2], &teste1[3], &teste1[4]);
    printf("%s %d %d %d %d %d\n", texto, teste1[0], teste1[1], teste1[2], teste1[3], teste1[4]);
    fscanf(f,"%s %f", texto, &teste3);
    printf("%s %f\n", texto, teste3);                                     //automaticamente pegara os valores do arquivo de texto e ira inserir nas variaveis
    fscanf(f,"%s %s", texto, nome);                                          //tem que estar de acordo de como esta no arquivo de texto
    printf("%s %s\n", texto, nome);
    fscanf(f,"%s %d", texto, &i);
    printf("%s %d\n", texto, i);

    fclose(f);
    fclose(f1);
    fclose(f2);
}
