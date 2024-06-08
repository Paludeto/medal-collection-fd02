#include "../include/medalha.h"
#include "../include/utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int linhasArquivo(FILE *arq){

   int contaLinhas = 1;

    if (arq == NULL) {

        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);  

    }

   char c;
   while ((c = getc(arq)) != EOF) {

        if (c == '\n') {
            contaLinhas++;
        }
        
    }

    return contaLinhas;
    
}

void parseArquivo(FILE *arq, int numLinhas, Medalha* medalhas){

    int contador = 0;

    if (arq == NULL) {

        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
        
    }

    while (contador < numLinhas) {

        int campos = fscanf(arq, "%c,%63[^,],%63[^,],%d,%c,%63[^,],%63[^,],%63[^\n]\n",
                    &medalhas[contador].genero, medalhas[contador].modalidade, medalhas[contador].cidade, &medalhas[contador].ano, &medalhas[contador].gbs,
                    medalhas[contador].nome, medalhas[contador].pais, medalhas[contador].resultado);

        if (campos == EOF){ //Por recomendação do professor.
            break;
        }

        contador++;

    }
    fclose(arq);

}

void escreveArquivo(Medalha* medalhas, int numLinhas){

FILE *arq_dat = fopen("data/medalhas.dat","wb");
FILE *num_medalhas = fopen("data/num.dat","wb");


fwrite(medalhas,numLinhas,sizeof(Medalha),arq_dat);

fwrite(&numLinhas,1,sizeof(int),num_medalhas);

fclose(arq_dat);

fclose(num_medalhas);

}

int leNumero(FILE * numMedalhas){

    int numLinhas;

    fread(&numLinhas,sizeof(int),1,numMedalhas);
    

    return numLinhas;
}

void leArquivo(FILE *arq,Medalha* medalhas,int numLinhas){

    
    fread(medalhas,numLinhas,sizeof(Medalha),arq);
    
    for (int i = 0; i < numLinhas; i++) {  

        printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].gbs,
                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);

    }
    printf("funciona\n");
    
    
}

void inserirAtleta(Medalha* medalhas,int *numLinhas){


    medalhas = realloc(medalhas,((*numLinhas + 1)*sizeof(Medalha)));
    
    *numLinhas = *numLinhas+1;

    printf("Insira o genero do atleta:");
    scanf("%c",&medalhas[*numLinhas].genero);

    setbuf(stdin, NULL);
    
    printf("Insira o nome:");
    recebeString(medalhas[*numLinhas].nome);

    printf("Insira a modalidade: ");
    recebeString(medalhas[*numLinhas].modalidade);

    printf("Insira o pais:");
    recebeString(medalhas[*numLinhas].pais);

    printf("Insira a cidade:");
    recebeString(medalhas[*numLinhas].cidade);

    printf("Insira o ano:");
    scanf("%d",&medalhas[*numLinhas].ano);

    setbuf(stdin, NULL);

    printf("Insira o resultado:");
    recebeString(medalhas[*numLinhas].resultado);

    printf("Insira a medalha:");
    scanf("%c",&medalhas[*numLinhas].gbs);

     printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[*numLinhas].genero, medalhas[*numLinhas].modalidade, 
         medalhas[*numLinhas].cidade, medalhas[*numLinhas].ano, medalhas[*numLinhas].gbs,
         medalhas[*numLinhas].nome, medalhas[*numLinhas].pais, medalhas[*numLinhas].resultado);

    }


    

    

    
