#include "../include/medalha.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Cores para textos coloridos
#define BLK "\e[0;30m" // Preto 
#define RED "\e[0;31m" // Vermelho
#define GRN "\e[0;32m" // Verde
#define YEL "\e[0;33m" // Amarelo
#define BLU "\e[0;34m" // Azul
#define MAG "\e[0;35m" // Magenta
#define CYN "\e[0;36m" // Ciano
#define WHT "\e[0;37m" // Branco
#define RESET "\e[0m"

#define LARG 10

typedef struct {
    int id;
    char acao[30];
    void (*funcao)();
} itemMenu;

/**
void tocarSom(int opcao){
    if (opcao == 0)
    {
        Beep(300, 500);
    } else if (opcao < 4) {
        Beep(535, 100);
        Beep(200, 50);
        Beep(535, 100);
    } else {
        Beep(750, 500);
    }
}
 */

void sair(){
    exit(0);
}

void menu (Medalha *medalhas, Medalha **medalhas2, int indice, int *indice2) {

    int opcao = 0;

    // Vetor das opções de menu
    itemMenu menu[7] = {
        {1, "Cadastrar atleta", inserirAtleta},
        {2, "Buscar atleta", buscaAtleta},
        {3, "Exibir atleta", exibeAtleta},
        {4, "Modificar atleta", modificaAtleta},
        {5, "Remover atleta", removeAtleta},
        {6, "Exibe olimpiada", exibeOlimpiada},
        {7, "Sair", sair}
    };

    // Tocar som de menu aparecendo na tela
    //tocarSom(0);

    // Printa o menu na tela
    printf(YEL " --------- MENU ------\n" RESET);
    printf("| %*s | %*s |\n",
            -LARG, "Opcao",
            -LARG/2, "Digite");
    for (int i = 0; i < 4; i++)
    {
        printf("| " BLU "%*s " RESET "| " BLU " %*d" RESET "|\n",
            -LARG, menu[i].acao,
            -LARG/2 - 1, menu[i].id);
    }
    
    // Opção do menu
    do
    {
        printf("\nDigite a opção (número) de menu: ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    
    // Som após escolha do menu
    //tocarSom(opcao);

    switch (opcao)
    {
    // inserirAtleta(Medalha *medalhas, int *numLinhas)
    case 1: 
        menu[opcao - 1].funcao(medalhas, indice2);
        break;
    // buscaAtleta(Medalha **medalhas, int tamanhoArray)
    case 2:
        menu[opcao - 1].funcao(medalhas2, indice);
        break;
    // exibeAtleta(Medalha **medalhas, int indice)
    case 3:
        menu[opcao - 1].funcao(medalhas2, indice);
        break;
    // modificaAtleta(Medalha **medalhas, int tamanhoArray)
    case 4:
        menu[opcao - 1].funcao(medalhas2, indice);
        break;

    // removeAtleta(Medalha * medalhas,int *tamanhoArray);
    case 5:
        menu[opcao - 1].funcao(medalhas, indice);
        break;

    // exibeOlimpiada(Medalha *medalhas, int tamanhoArray)
    case 6:
        menu[opcao - 1].funcao(medalhas, indice);
        break;
    // sair
    case 7:
        menu[opcao - 1].funcao();
        break;

    default:
        break;
    }

}