#include "../include/pais.h"
#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registraPaises(Medalha *medalhas, Pais *paises, int numMedalhas);
int buscaPais(Medalha *medalhas, char sigla[TAM_SIGLA]);
void contaMedalhas(Medalha *medalhas, char sigla[TAM_SIGLA]);