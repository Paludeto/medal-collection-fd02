#include "../include/medalha.h"
#include "../include/utilidades.h"
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
    
    return;

}

void inserirAtleta(Medalha *medalhas, int *numLinhas) {

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

    return;

}

void exibeAtleta(Medalha **medalhas, int indice) {

    printf("%-15s\t | %-15s\t | %-15s\t | %-15s\t | %-10s\t | %-15s\t | %-10s\t | %-15s\t |\n",
        "GÊNERO", "MODALIDADE", "CIDADE", "ANO", "GBS", "NOME", "PAíS", "RESULTADO");   
    
    printf("%-15c\t | %-15s\t | %-15s\t | %-15d\t | %-10c\t | %-15s\t | %-10s\t | %-15s\t |\n",
        (*medalhas)[indice].genero, (*medalhas)[indice].modalidade, (*medalhas)[indice].cidade, (*medalhas)[indice].ano, 
        (*medalhas)[indice].gbs, (*medalhas)[indice].nome, (*medalhas)[indice].pais, (*medalhas)[indice].resultado);  

    return;

}

int buscaAtleta(Medalha **medalhas, int tamanhoArray) {

    printf("Digite o nome do atleta a ser buscado\n");

    char nomeBuscado[TAM_STRING];
    recebeString(nomeBuscado);

    for (int i = 0; i < tamanhoArray; i++) {
        printf("%s\n", (*medalhas)[i].nome);
        if (strcmp(nomeBuscado, (*medalhas)[i].nome) == 0) {
            printf("Índice do atleta: %d\n", i);
            exibeAtleta(medalhas, i);
            return i;
        }
    }

    return -1;

}

void modificaAtleta(Medalha** medalhas, int tamanhoArray) { 

    enum {
        GENERO = 1,
        MODALIDADE,
        CIDADE, 
        ANO,
        GBS, 
        NOME,
        PAIS,
        RESULTADO
    };

    int opcao;

    int indice = buscaAtleta(medalhas, tamanhoArray);

    if (indice == -1) {
        fprintf(stderr, "Atleta não encontrado!\n");
        return;
    }

    exibeAtleta(medalhas, indice);

    printf("Qual campo do(a) atleta você deseja modificar?\n");
    printf("1 - GÊNERO\n2 - MODALIDADE\n3 - CIDADE\n4 - ANO\n5 - GBS\n6 - NOME\n7 - PAIS\n8 - RESULTADO\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 8) {
        printf("Digite um valor válido!\n");
        printf("1 - GÊNERO\n2 - MODALIDADE\n3 - CIDADE\n4 - ANO\n 5 - GBS\n6 - NOME\n7 - PAIS\n8 - RESULTADO\n");
        scanf("%d", &opcao);
    }

    setbuf(stdin, NULL);

    switch (opcao) {
        
        case GENERO:
            
            printf("Digite um novo gênero para o(a) atleta %s\n", (*medalhas)[indice].nome);
            scanf("%c", &(*medalhas)[indice].genero);

            while ((*medalhas)[indice].genero != 'W' && (*medalhas)[indice].genero != 'M') {    
                printf("Digite apenas W ou M\n");
                scanf("%c", &(*medalhas)[indice].genero);
            }

            break;

        case MODALIDADE:
        
            printf("Digite uma nova modalidade para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].modalidade);

            break;

        case CIDADE:

            printf("Digite uma nova cidade para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].cidade);

            break;

        case ANO:
            
            printf("Digite um novo ano para o(a) atleta %s\n", (*medalhas)[indice].nome);
            scanf("%d", &(*medalhas)[indice].ano);

            break;

        case GBS:

            printf("Digite uma nova medalha para o(a) atleta %s (G, B ou S)\n", (*medalhas)[indice].nome);
            scanf("%c", &(*medalhas)[indice].gbs);

            while ((*medalhas)[indice].gbs != 'G' || (*medalhas)[indice].gbs != 'B' || (*medalhas)[indice].gbs != 'S') {
                printf("Digite apenas G, B ou S\n");
                scanf("%c", &(*medalhas)[indice].genero);
            }

            break;

        case NOME:

            printf("Digite um novo nome para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].nome);

            break;

        case PAIS:
            
            printf("Digite um novo país para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].pais);

            break;

        case RESULTADO:

            printf("Digite um novo resultado para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].resultado);

            break;

    }


    return;
    
}

void removeAtleta(Medalha *medalhas, int *tamanhoArray) {

    int indice;

    printf("Insira o número do(a) atleta que deseja excluir:");
    scanf("%d",&indice);

    for (int i = 0; i < *tamanhoArray; i++) {

        if(i == indice) {

            for (int j = indice; j < *tamanhoArray; j++) {
               medalhas[j].ano = medalhas[j + 1].ano;
               medalhas[j].gbs = medalhas[j + 1].gbs;
               medalhas[j].genero = medalhas[j + 1].genero;
               
               strcpy(medalhas[j].nome,medalhas[j + 1].nome);
               strcpy(medalhas[j].cidade,medalhas[j + 1].cidade);
               strcpy(medalhas[j].pais,medalhas[j + 1].pais);
               strcpy(medalhas[j].resultado,medalhas[j + 1].resultado);
               strcpy(medalhas[j].modalidade,medalhas[j + 1].modalidade);
    
            }
            
        }

    }

    *tamanhoArray = *tamanhoArray - 1;

}