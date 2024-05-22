#include "../include/medalha.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Medalha medalhas[NUM_MEDALHAS];

    FILE *arq;
    arq = fopen("../../data/medalhas.csv", "r");
    int contador = 0;

    if(arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    while (contador < NUM_MEDALHAS) {

        int campos = fscanf(arq, "%c,%63[^,],%63[^,],%d,%c,%63[^,],%63[^,],%63[^\n]\n",
                    &medalhas[contador].genero, medalhas[contador].modalidade, medalhas[contador].cidade, &medalhas[contador].ano, &medalhas[contador].gbs,
                    medalhas[contador].nome, medalhas[contador].pais, medalhas[contador].resultado);

        if (campos != 8){
            break;
        }

        contador++;

    }

    for (int i = 0; i < contador; i++) {  

        printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].gbs,
                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                    
    }

    fclose(arq);

    return 0;

}