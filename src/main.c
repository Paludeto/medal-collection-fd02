#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *arq;
    FILE *numMedalhas;
    
    int numLinhas = 0;
    
    arq = fopen("data/medalhas.dat", "r+b");

    numMedalhas = fopen("data/num.dat", "rb");  

    //Se for a primeira execução do programa...
    if (arq == NULL) {   

        arq = fopen("data/medalhas.csv","r");
        
        numLinhas = linhasArquivo(arq); 

        rewind(arq);
        
        Medalha *medalhas = (Medalha *) malloc(numLinhas * sizeof(Medalha));
       
        parseArquivo(arq, numLinhas, medalhas);

        escreveBinario(medalhas, numLinhas);
    
    }

    //Se não for a primeira execução, ler do binário
    if (numMedalhas != NULL) {

        numLinhas = leLinhasBinario(numMedalhas);
    
        Medalha *medalhas = (Medalha *) malloc(numLinhas * sizeof(Medalha));

        leBinario(arq, medalhas, numLinhas);

    } 
    
    return 0;

}
    
    

