#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *arq;
    FILE *numMedalhas;
    
    int numLinhas = 0;
    
    arq = fopen("data/medalhas.dat", "r+b");

    numMedalhas = fopen("data/num.dat", "r+b");  

    //Se for a primeira execução do programa...
    if (arq == NULL) {   

        arq = fopen("data/medalhas.csv","r");
        
        numLinhas = linhasArquivo(arq); 

        rewind(arq);
        
        Medalha *medalhas = (Medalha *) malloc(numLinhas * sizeof(Medalha));
       
        parseArquivo(arq, numLinhas, medalhas);

        escreveBinario(medalhas, numLinhas);

        //Menu vai aqui

        free(medalhas);
    
    
    }

    //Favor manter, se não, dará segfault na primeira execução
    //checa se não é a primeira execução antes de usar o binário numMedalhas
    if (numMedalhas != NULL) {

        numLinhas = leLinhasBinario(numMedalhas);
    
        int *tamanhoMedalhas = &numLinhas;

        Medalha* medalhas=(Medalha*) malloc (numLinhas* sizeof(Medalha));

        leBinario(arq,medalhas,*tamanhoMedalhas);

        exportaCsv(arq, medalhas, numLinhas);

        free(medalhas);  

    }
   
   
    return 0;

}