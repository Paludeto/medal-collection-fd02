#include "../include/medalha.h"
#include <stdlib.h>
#include <stdio.h>


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

    for (int i = 0; i < contador; i++) {  

        printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].gbs,
                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);

    }

    fclose(arq);

}

void escreveArquivo(int numLinhas,Medalha* medalhas){

FILE *arq_dat = fopen("data/medalha.dat","w");

char linha[TAM_LINHA] = "";

for (int i = 0; i < numLinhas; i++)
{
    sprintf(linha,"%c,%s,%s,%d,%c,%s,%s,%s\n",medalhas[i].genero,medalhas[i].modalidade,medalhas[i].cidade,
    medalhas[i].ano,medalhas[i].gbs,medalhas[i].nome,medalhas[i].pais,medalhas[i].resultado);
    

    fwrite(linha,sizeof(char),TAM_LINHA,arq_dat);
    

}


fclose(arq_dat);

}
