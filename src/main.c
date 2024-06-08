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
        printf("funciona");

        //Menu vai aqui

        free(medalhas);
    
    
    }
   
    numLinhas = leLinhasBinario(numMedalhas);
    
    int *tamanhoMedalhas = &numLinhas;

    Medalha* medalhas=(Medalha*) malloc (numLinhas* sizeof(Medalha));

    leBinario(arq,medalhas,*tamanhoMedalhas);

    //Menu Vai aqui
    
    // teste
    inserirAtleta(medalhas,tamanhoMedalhas);
    
    printf("%s",medalhas[0].nome);

    removeAtleta(medalhas,tamanhoMedalhas);
    //teste, confirma tamanho do vetor de structs
    printf("%d",numLinhas);
    //teste, confirma deslocamento do vetor
    printf("%s",medalhas[0].nome);
                                                                                                          
    free(medalhas); 

    return 0;
    }
    
    

