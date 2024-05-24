#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    

FILE *arq;
arq = fopen("../../data/medalhas.csv", "r");

int NUM_MEDALHAS = linhasArquivo(arq);  

Medalha medalhas[NUM_MEDALHAS];

rewind(arq);
 
parseArquivo(arq,NUM_MEDALHAS,medalhas);

return 0;

}