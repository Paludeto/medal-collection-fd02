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
        
        Medalha medalhas[numLinhas];
       
        parseArquivo(arq, numLinhas, medalhas);

        //Menu vai aqui

        escreveArquivo(medalhas,numLinhas);

    
    }
   
    numLinhas = leNumero(numMedalhas);
    
    Medalha medalhas[numLinhas];

    leArquivo(arq,medalhas,numLinhas);

    //Menu Vai aqui
    
    
    return 0;
    }
    
    

