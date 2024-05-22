#ifndef MEDALHA_H
#define MEDALHA_H

#define TAM_STRING 64

typedef union Resultado {
    float metros, tempo;
} Resultado;

typedef struct Medalha {
    char nome[TAM_STRING]; 
    char pais[TAM_STRING];
    char modalidade[TAM_STRING];
    char cidade[TAM_STRING];
    char genero;
    char gbs;
    int ano;
    int codigo;
    Resultado resultado;
} Medalha;

#endif