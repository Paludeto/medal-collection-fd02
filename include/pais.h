#ifndef PAIS_H
#define PAIS_H

#define TAM_SIGLA 3
#define NUM_PAISES 97

#include "medalha.h"

typedef struct {
    char sigla[TAM_SIGLA];
} Pais;

void registraPaises(Medalha *medalhas, Pais *paises, int numMedalhas);
int buscaPais(Medalha *medalhas, char sigla[TAM_SIGLA]);
void contaMedalhas(Medalha *medalhas, char sigla[TAM_SIGLA]);

#endif