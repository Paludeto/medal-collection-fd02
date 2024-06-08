#ifndef MEDALHA_H
#define MEDALHA_H

#include<stdio.h>
#include<stdlib.h>

#define TAM_STRING 64
#define TAM_LINHA 1024

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

int linhasArquivo(FILE *);

void parseArquivo(FILE *, int, Medalha*);

void escreveArquivo( Medalha*, int numLinhas);

void leArquivo(FILE *arq, Medalha* medalhas,int numLinhas);

int leNumero(FILE * numMedalhas);

void inserirAtleta(Medalha* medalhas, int *numLinhas);

#endif