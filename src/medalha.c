#include "../include/medalha.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int linhasArquivo(FILE *arq) {

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

void parseArquivo(FILE *arq, int numLinhas, Medalha* medalhas) {

    int contador = 0;

    if (arq == NULL) {

        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
        
    }

    while (contador < numLinhas) {

        int campos = fscanf(arq, "%c,%63[^,],%63[^,],%d,%c,%63[^,],%63[^,],%63[^\n]\n",
                    &medalhas[contador].genero, medalhas[contador].modalidade, medalhas[contador].cidade, &medalhas[contador].ano, &medalhas[contador].gbs,
                    medalhas[contador].nome, medalhas[contador].pais, medalhas[contador].resultado);

        if (campos == EOF) { 
            break;
        }

        contador++;

    }
    
    fclose(arq);

    return;

}

void escreveBinario(Medalha* medalhas, int numLinhas) {

    FILE *arq_dat = fopen("data/medalhas.dat","wb");
    FILE *num_medalhas = fopen("data/num.dat","wb");


    fwrite(medalhas,numLinhas,sizeof(Medalha),arq_dat);

    fwrite(&numLinhas,1,sizeof(int),num_medalhas);

    fclose(arq_dat);

    fclose(num_medalhas);

    return;

}

int leLinhasBinario(FILE *numMedalhas) {

    int numLinhas;

    fread(&numLinhas, sizeof(int), 1, numMedalhas);

    return numLinhas;

}

void leBinario(FILE *arq, Medalha* medalhas, int numLinhas) {
    
    fread(medalhas, numLinhas, sizeof(Medalha), arq);
    
    for (int i = 0; i < numLinhas; i++) {  

        printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].gbs,
                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);

    }

    fclose(arq);
    
    return;
    
}

void exibeAtleta(Medalha **medalhas, int indice) {

    printf("%-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t |\n",
        "GÊNERO", "MODALIDADE", "CIDADE", "ANO", "GBS", "NOME", "PAÍS", "RESULTADO");   
    
    printf("%-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t | %-10s\t |\n",
        medalhas[indice]->genero, medalhas[indice]->modalidade, medalhas[indice]->cidade, medalhas[indice]->ano, 
        medalhas[indice]->gbs, medalhas[indice]->nome, medalhas[indice]->pais, medalhas[indice]->resultado);  

    return;

}

int buscaAtleta(Medalha **medalhas, int tamanhoArray, char nomeBuscado[TAM_STRING]) {

    for (int i = 0; i < tamanhoArray; i++) {
        if (strcmp(nomeBuscado, medalhas[i]->nome) == 0) {
            return i;
        }
    }

    return -1;

}

void modificaAtleta(Medalha** medalhas, int tamanhoArray) {

    typedef enum OPCOES {
        GENERO = 1,
        MODALIDADE,
        CIDADE, 
        ANO,
        GBS, 
        NOME,
        PAIS,
        RESULTADO
    };

    char nomeBuscado[TAM_STRING];
    fgets(nomeBuscado, TAM_STRING, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    int indice = buscaAtleta(medalhas, tamanhoArray, nomeBuscado);

    if (indice == -1) {
        perror("Atleta não encontrado!\n");
        return;
    }

    exibeAtleta(medalhas, indice);

    printf("Qual campo do atleta você deseja modificar?\n");
    printf("1 - GÊNERO\n2 - MODALIDADE\n3 - CIDADE\n4 - ANO\n 5 - GBS\n6 - NOME\n7 - PAIS\n8 - RESULTADO\n");
    
    //inacabada
    return;

}