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
        int *numLinhas2 = &numLinhas;

        rewind(arq);
        
        Medalha *medalhas = (Medalha *) malloc(numLinhas * sizeof(Medalha));
        Medalha **medalhas2 = &medalhas;
       
        parseArquivo(arq, numLinhas, medalhas);

        menu (arq, medalhas, medalhas2, numLinhas, numLinhas2);

        escreveBinario(medalhas, numLinhas);

        //Menu vai aqui

        free(medalhas);
    
    }
   
    //Favor manter, se não, dará segfault na primeira execução
    //checa se não é a primeira execução antes de usar o binário numMedalhas
    if (numMedalhas != NULL) {

        numLinhas = leLinhasBinario(numMedalhas);
    
        int *tamanhoMedalhas = &numLinhas;
         int *numLinhas2 = &numLinhas;

        Medalha* medalhas=(Medalha*) malloc (numLinhas* sizeof(Medalha));
        Medalha **medalhas2 = &medalhas;

        //iniciou
        leBinario(arq, medalhas, *tamanhoMedalhas);
        
        menu (arq, medalhas, medalhas2, numLinhas, numLinhas2);
       // buscaAtleta(&medalhas, numLinhas);

        //saiu do programa
        escreveBinario(medalhas, numLinhas);

        free(medalhas);  

    }
   
   
    return 0;

}