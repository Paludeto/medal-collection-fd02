#include "../include/utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void recebeString(char string[TAM_STRING]){

    fgets(string, TAM_STRING, stdin);
    string[strcspn(string,"\n")]='\0';
    setbuf(stdin, NULL);

    return;

}