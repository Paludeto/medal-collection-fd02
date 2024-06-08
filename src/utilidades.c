#include "../include/utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void recebeString(char string[]){

fgets(string, 21, stdin);
string[strcspn(string,"\n")]='\0';
setbuf(stdin, NULL);

}