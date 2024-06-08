#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *arq;
    FILE *numMedalhas;
    
    int numLinhas = 0;
    
    arq = fopen("data/medalhas.dat", "r+b");

    numMedalhas = fopen("data/num.dat","rb");  
    if (arq == NULL)
    {   

        arq = fopen("data/medalhas.csv","r");
        
        numLinhas = linhasArquivo(arq); 

        rewind(arq);
        
        Medalha* medalhas=(Medalha*) malloc (numLinhas * sizeof(Medalha));
       
        parseArquivo(arq, numLinhas, medalhas);
        printf("funciona");
        //Menu vai aqui

        escreveArquivo(medalhas,numLinhas);

        free(medalhas);
    
    
    }
   
    numLinhas = leNumero(numMedalhas);
    
    int *tamanhoMedalhas = &numLinhas;

    Medalha* medalhas=(Medalha*) malloc (numLinhas* sizeof(Medalha));

    leArquivo(arq,medalhas,numLinhas);

    //Menu Vai aqui
    
    // teste
    inserirAtleta(medalhas,tamanhoMedalhas);
    
    //teste, confirma tamanho do vetor de structs
    printf("%d",numLinhas);
                                                                                                          
    free(medalhas); 

    return 0;
    }
    
    

