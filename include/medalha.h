#ifndef MEDALHA_H
#define MEDALHA_H

#define TAM_STRING 64
#define NUM_MEDALHAS 2394

typedef struct Medalha {
    char nome[TAM_STRING]; 
    char pais[TAM_STRING];
    char modalidade[TAM_STRING];
    char cidade[TAM_STRING];
    char resultado[TAM_STRING];
    char genero;
    char gbs;
    int ano;
    int codigo;
} Medalha;

#endif