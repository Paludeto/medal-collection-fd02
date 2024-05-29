#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *arq;

    arq = fopen("data/medalhas.csv", "r");
    int numLinhas = linhasArquivo(arq);  

    Medalha medalhas[numLinhas];

    rewind(arq);
    
    parseArquivo(arq, numLinhas, medalhas);

    escreveArquivo(numLinhas,medalhas);

    
    return 0;

}