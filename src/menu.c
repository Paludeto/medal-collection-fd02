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

#define LARG 20

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

void menu (FILE *arq, Medalha *medalhas, Medalha **medalhas2, int indice, int *indice2) {

    int opcao = 0;

    // Vetor das opções de menu
    itemMenu menu[7] = {
        {1, "Cadastrar atleta", inserirAtleta},
        {2, "Buscar atleta", buscaAtleta},
        {3, "Modificar atleta", modificaAtleta},
        {4, "Remover medalha", removeAtleta},
        {5, "Exibe olimpiada", exibeOlimpiada},
        {6, "Exportar CSV", exportaCsv},
        {7, "Sair", sair}
    };

    
    do
    {
        // Tocar som de menu aparecendo na tela
        //tocarSom(0);

        // Printa o menu na tela
        printf(YEL " --------- MENU ----------------\n" RESET);
        printf("| %*s | %*s |\n",
                -LARG, "Opcao",
                -LARG/4, "Digite");
        for (int i = 0; i < 7; i++)
        {
            printf("| " BLU "%*s " RESET "| " BLU " %*d" RESET "|\n",
                -LARG, menu[i].acao,
                -LARG/4 - 1, menu[i].id);
        }
        
        // Opção do menu       
        printf("\nDigite a opção (número) de menu: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
    
    
        // Som após escolha do menu
        //tocarSom(opcao);

        switch (opcao)
        {
        
        case 1: 
            menu[opcao - 1].funcao(medalhas, indice2);
            break;
        
        case 2:
            menu[opcao - 1].funcao(medalhas2, indice);
            break;
        
        case 3:
            menu[opcao - 1].funcao(medalhas2, indice);
            break;
        
        case 4:
            menu[opcao - 1].funcao(medalhas, indice2);
            break;

       
        case 5:

            menu[opcao - 1].funcao(medalhas, indice);
            break;

        
        case 6:

            menu[opcao - 1].funcao(arq, medalhas, indice);
            break;
        

        default:
            break;
        }

    } while (opcao != 7);

}