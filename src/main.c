#include "../include/medalha.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Medalha medalhas[NUM_MEDALHAS];

    FILE *arq;
    arq = fopen("../data/medalhas.csv", "r");
    int contador = 0;

    if(arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(arq)) {
        int campos = fscanf(arq, "%c,%63[^,],%63[^,],%d,%c,%63[^,],%63[^,],%63[^,]\n",
                    &medalhas[contador].genero, &medalhas[contador].modalidade, &medalhas[contador].cidade, &medalhas[contador].ano, &medalhas[contador].gbs,
                    &medalhas[contador].nome, &medalhas[contador].pais, &medalhas[contador].resultado);
        if (campos != 8){
            break;
        }
    }

    for (int i = 0; i < NUM_MEDALHAS; i++) {
        printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[contador].genero, medalhas[contador].modalidade, medalhas[contador].cidade, medalhas[contador].ano, medalhas[contador].gbs,
                    medalhas[contador].nome, medalhas[contador].pais, medalhas[contador].resultado);
    }

    fclose(arq);

    return 0;

}