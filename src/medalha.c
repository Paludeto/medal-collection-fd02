#include "../include/medalha.h"
#include "../include/utilidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



/**
 * @brief Le a quantidade de linhas de um arquivo CSV.
 * 
 * @param arq 
 * @return A quantidade de linhas.
 */
int linhasArquivo(FILE *arq) {

    int contaLinhas = 1;

    if (arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);  
    }

   char c;
   while ((c = getc(arq)) != EOF) {

        if (c == '\n') {
            contaLinhas++;
        }
        
    }

    return contaLinhas;
    
}


/**
 * @brief Faz parsing do arquivo CSV atribuindo o conteúdo entre as vírgulas
 * a seus respectivos lugares dentro do struct.
 * 
 * @param arq 
 * @param numLinhas 
 * @param medalhas 
 */
void parseArquivo(FILE *arq, int numLinhas, Medalha* medalhas) {

    int contador = 0;

    if (arq == NULL) {

        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
        
    }

    while (contador < numLinhas) {

        int campos = fscanf(arq, "%c,%63[^,],%63[^,],%d,%c,%63[^,],%63[^,],%63[^\n]\n",
                    &medalhas[contador].genero, medalhas[contador].modalidade, medalhas[contador].cidade, &medalhas[contador].ano, &medalhas[contador].gbs,
                    medalhas[contador].nome, medalhas[contador].pais, medalhas[contador].resultado);

        if (campos == EOF) { 
            break;
        }

        contador++;

    }
    
    fclose(arq);

    return;

}

/**
 * @brief Salva as medalhas em um arquivo binário, assim
 * como o número de medalhas para leitura posterior
 * 
 * @param medalhas 
 * @param numLinhas 
 */
void escreveBinario(Medalha* medalhas, int numLinhas) {

    FILE *arq_dat = fopen("data/medalhas.dat","wb");
    FILE *num_medalhas = fopen("data/num.dat","wb");


    fwrite(medalhas,numLinhas,sizeof(Medalha),arq_dat);

    fwrite(&numLinhas,1,sizeof(int),num_medalhas);

    fclose(arq_dat);

    fclose(num_medalhas);

    return;

}

/**
 * @brief Le o número de linhas salvos por escreveBinario()
 * 
 * @param numMedalhas 
 * @return O número de medalhas
 */
int leLinhasBinario(FILE *numMedalhas) {

    int numLinhas;

    fread(&numLinhas, sizeof(int), 1, numMedalhas);

    return numLinhas;

}


/**
 * @brief Le todas as medalhas salvas por escreveBinario()
 * 
 * @param arq 
 * @param medalhas 
 * @param numLinhas 
 */
void leBinario(FILE *arq, Medalha* medalhas, int numLinhas) {
    
    fread(medalhas, numLinhas, sizeof(Medalha), arq);
    
    return;

}

/**
 * @brief Cria um novo arquivo CSV com as medalhas salvas pelo usuário
 * 
 * @param arq 
 * @param medalhas 
 * @param numLinhas 
 */
void exportaCsv(FILE *arq, Medalha* medalhas, int numLinhas) {

    arq = fopen("data/novoMedalhas.csv", "w");

    if (arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numLinhas; i++) {
        fprintf(arq, "%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].gbs,
                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }

    fclose(arq);

    return;

}


/**
 * @brief Cria um atleta no struct Medalhas
 * 
 * @param medalhas 
 * @param numLinhas 
 */
void inserirAtleta(Medalha *medalhas, int *numLinhas) {

    medalhas = realloc(medalhas,((*numLinhas + 1)*sizeof(Medalha)));
    
    *numLinhas = *numLinhas+1;

    setbuf(stdin, NULL);

    printf("Insira o genero do atleta:");
    scanf("%c%*c",&medalhas[*numLinhas].genero);

    setbuf(stdin, NULL);
    
    printf("Insira o nome:");
    recebeString(medalhas[*numLinhas].nome);

    printf("Insira a modalidade: ");
    recebeString(medalhas[*numLinhas].modalidade);

    printf("Insira o pais:");
    recebeString(medalhas[*numLinhas].pais);

    printf("Insira a cidade:");
    recebeString(medalhas[*numLinhas].cidade);

    printf("Insira o ano:");
    scanf("%d",&medalhas[*numLinhas].ano);

    setbuf(stdin, NULL);

    printf("Insira o resultado:");
    recebeString(medalhas[*numLinhas].resultado);

    printf("Insira a medalha:");
    scanf("%c",&medalhas[*numLinhas].gbs);

     printf("%c, %s, %s, %d, %c, %s, %s, %s\n", medalhas[*numLinhas].genero, medalhas[*numLinhas].modalidade, 
         medalhas[*numLinhas].cidade, medalhas[*numLinhas].ano, medalhas[*numLinhas].gbs,
         medalhas[*numLinhas].nome, medalhas[*numLinhas].pais, medalhas[*numLinhas].resultado);

    return;

}

/**
 * @brief Mostra o cabeçalho em formato de tabela
 * 
 */
void exibeCabecalho() {
    printf("%s\t | %-30s\t | %-10s\t | %s\t | %s\t | %-30s\t | %s\t | %s\t\n",
        "GÊNERO", "MODALIDADE", "CIDADE", "ANO", "GBS", "NOME", "PAíS", "RESULTADO");   
}


/**
 * @brief Recebe o indice de uma medalha e exibe as informações do respectivo atleta
 * 
 * @param medalhas 
 * @param indice 
 */
void exibeAtleta(Medalha **medalhas, int indice) {

    printf("%c\t | %-30s\t | %-10s\t | %d\t | %c\t | %-30s\t | %s\t | %s\t\n",
        (*medalhas)[indice].genero, (*medalhas)[indice].modalidade, (*medalhas)[indice].cidade, (*medalhas)[indice].ano, 
        (*medalhas)[indice].gbs, (*medalhas)[indice].nome, (*medalhas)[indice].pais, (*medalhas)[indice].resultado);  

    return;

}

/**
 * @brief Recebe o nome de um atleta e exibe suas informações
 * 
 * @param medalhas 
 * @param tamanhoArray 
 */
void buscaAtleta(Medalha **medalhas, int tamanhoArray) {

    int totalMedalhas = 0;
    int *vetorMedalhas = NULL;

    printf("Digite o nome do atleta a ser buscado\n");

    char nomeBuscado[TAM_STRING];
    recebeString(nomeBuscado);

    exibeCabecalho();

    for (int i = 0; i < tamanhoArray; i++) {
        if (strcmp(nomeBuscado, (*medalhas)[i].nome) == 0) {
            totalMedalhas++;
            vetorMedalhas = realloc(vetorMedalhas, totalMedalhas * sizeof(int));

            if (vetorMedalhas == NULL) {
                fprintf(stderr, "Erro de alocação de memória\n");
                exit(EXIT_FAILURE);
            }
            
            vetorMedalhas[totalMedalhas - 1] = i;
            exibeAtleta(medalhas, i);
        }
    }

    printf("Indíces das medalhas:\n[ ");
    for (int i = 0; i < totalMedalhas; i++) {
        printf("%d ", vetorMedalhas[i]);
    }
    printf("]\n");

    if (totalMedalhas == 0) {
        printf("Nenhuma medalha encontrada!\n");
    } else {
        printf("Total de medalhas: %d\n", totalMedalhas);
    }

    free(vetorMedalhas);

    return;

}

/**
 * @brief Altera qualquer aspecto de um atleta já cadastrado
 * 
 * @param medalhas 
 * @param tamanhoArray 
 */
void modificaAtleta(Medalha **medalhas, int tamanhoArray) { 

    enum {
        GENERO = 1,
        MODALIDADE,
        CIDADE, 
        ANO,
        GBS, 
        NOME,
        PAIS,
        RESULTADO
    };

    int opcao;
    int indice;

    printf("Digite o índice do atleta que deseja alterar\n");
    scanf("%d", &indice);

    while (indice < 0 || indice > tamanhoArray) {
        printf("Digite um valor válido!\n");
        scanf("%d", &indice);
    }

    exibeCabecalho();
    exibeAtleta(medalhas, indice);

    printf("Qual campo do(a) atleta você deseja modificar?\n");
    printf("1 - GÊNERO\n2 - MODALIDADE\n3 - CIDADE\n4 - ANO\n5 - GBS\n6 - NOME\n7 - PAIS\n8 - RESULTADO\n");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 8) {
        printf("Digite um valor válido!\n");
        printf("1 - GÊNERO\n2 - MODALIDADE\n3 - CIDADE\n4 - ANO\n 5 - GBS\n6 - NOME\n7 - PAIS\n8 - RESULTADO\n");
        scanf("%d", &opcao);
    }

    setbuf(stdin, NULL);

    switch (opcao) {
        
        case GENERO:
            
            printf("Digite um novo gênero para o(a) atleta %s\n", (*medalhas)[indice].nome);
            scanf("%c", &(*medalhas)[indice].genero);

            while ((*medalhas)[indice].genero != 'W' && (*medalhas)[indice].genero != 'M') {    
                printf("Digite apenas W ou M\n");
                scanf("%c", &(*medalhas)[indice].genero);
            }

            break;

        case MODALIDADE:
        
            printf("Digite uma nova modalidade para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].modalidade);

            break;

        case CIDADE:

            printf("Digite uma nova cidade para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].cidade);

            break;

        case ANO:
            
            printf("Digite um novo ano para o(a) atleta %s\n", (*medalhas)[indice].nome);
            scanf("%d", &(*medalhas)[indice].ano);

            break;

        case GBS:

            printf("Digite uma nova medalha para o(a) atleta %s (G, B ou S)\n", (*medalhas)[indice].nome);
            scanf("%c", &(*medalhas)[indice].gbs);

            while ((*medalhas)[indice].gbs != 'G' || (*medalhas)[indice].gbs != 'B' || (*medalhas)[indice].gbs != 'S') {
                printf("Digite apenas G, B ou S\n");
                scanf("%c", &(*medalhas)[indice].genero);
            }

            break;

        case NOME:

            printf("Digite um novo nome para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].nome);

            break;

        case PAIS:
            
            printf("Digite um novo país para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].pais);

            break;

        case RESULTADO:

            printf("Digite um novo resultado para o(a) atleta %s\n", (*medalhas)[indice].nome);
            recebeString((*medalhas)[indice].resultado);

            break;

    }


    return;
    
}

/**
 * @brief Remove um atleta do struct e realoca a quantidade de medalhas de acordo
 * 
 * @param medalhas 
 * @param tamanhoArray 
 */
void removeAtleta(Medalha *medalhas, int *tamanhoArray) {

    int indice;

    printf("Insira o número do(a) atleta que deseja excluir:");
    scanf("%d",&indice);

    for (int i = 0; i < *tamanhoArray; i++) {

        if(i == indice) {

            for (int j = indice; j < *tamanhoArray; j++) {
               medalhas[j].ano = medalhas[j + 1].ano;
               medalhas[j].gbs = medalhas[j + 1].gbs;
               medalhas[j].genero = medalhas[j + 1].genero;
               
               strcpy(medalhas[j].nome,medalhas[j + 1].nome);
               strcpy(medalhas[j].cidade,medalhas[j + 1].cidade);
               strcpy(medalhas[j].pais,medalhas[j + 1].pais);
               strcpy(medalhas[j].resultado,medalhas[j + 1].resultado);
               strcpy(medalhas[j].modalidade,medalhas[j + 1].modalidade);
    
            }
            
        }

    }

    *tamanhoArray = *tamanhoArray - 1 ;

    medalhas = realloc(medalhas,((*tamanhoArray)*sizeof(Medalha)));
    return;

}

/**
 * @brief Exibe todas as medalhas e as informações de seus medalhistas uma olimpíada especifica
 * 
 * @param medalhas 
 * @param tamanhoArray 
 */
void exibeOlimpiada(Medalha *medalhas, int tamanhoArray) {

    int encontrado = 1;

    char cidade[TAM_STRING];
    int ano;

    printf("Digite o nome da cidade em que as olímpiadas ocorreram\n");
    recebeString(cidade);

    printf("Digite o ano em que as olímpiadas ocorreram\n");
    scanf("%d", &ano);
    setbuf(stdin, NULL);

    exibeCabecalho();

    for (int i = 0; i < tamanhoArray; i++) {
        if ((strcmp(cidade, medalhas[i].cidade) == 0 && ano == medalhas[i].ano) && (strcmp("null", medalhas[i].nome) != 0)) {
            exibeAtleta(&medalhas, i);
            encontrado = 0;
        }
    }

    if (encontrado == 1) {
        printf("Nenhuma correspondência encontrada!\n");
    }

    return;

}

/**
 * @brief Exibe uma tabela de medalhas por países de acordo com a olimpíada digitada pelo usuário
 * 
 * @param medalhas 
 * @param tamanhoArray 
 */
void exibeTabelaMedalhas(Medalha *medalhas, int tamanhoArray) {
    
    char siglas[NUM_PAISES][TAM_SIGLAS] = {
        "USA", "KEN", "ETH", "MAR", "ITA", "GBR", "FIN", "POR", "TUN", "URS",
        "EUA", "AUS", "TCH", "FRA", "SWE", "ERI", "BEL", "HUN", "POL", "JAM",
        "CAN", "TTO", "BAR", "NAM", "NED", "GER", "RSA", "CUB", "BUL", "PAN",
        "NZL", "ESP", "CHN", "GDR", "ALG", "QAT", "FRG", "LUX", "IRL", "SUI",
        "GRE", "IND", "RUS", "ECU", "MEX", "GUA", "TAN", "NOR", "TUR", "KSA",
        "PHI", "DOM", "PUR", "ZAM", "UGA", "SRI", "GRN", "CIV", "DEN", "JPN",
        "BRA", "NGR", "BAH", "BWI", "BDI", "SVK", "LAT", "EUN", "SUD", "BOT",
        "BLR", "EST", "CZE", "TPE", "KAZ", "LTU", "IRI", "TJK", "SLO", "UKR",
        "ROU", "HAI", "KOR", "ARG", "CHI", "DJI", "YUG", "VEN", "BRN", "AUT",
        "COL", "MOZ", "CRO", "SYR", "SRB", "ISL", "CMR"
    };

    char nomesDosPaises[NUM_PAISES][TAM_STRING] = {
        "Estados Unidos", "Quênia", "Etiópia", "Marrocos", "Itália", "Reino Unido",
        "Finlândia", "Portugal", "Tunísia", "União Soviética", "Estados Unidos",
        "Austrália", "Tchecoslováquia", "França", "Suécia", "Eritreia", "Bélgica",
        "Hungria", "Polônia", "Jamaica", "Canadá", "Trinidad e Tobago", "Barbados",
        "Namíbia", "Países Baixos", "Alemanha", "África do Sul", "Cuba", "Bulgária",
        "Panamá", "Nova Zelândia", "Espanha", "China", "Alemanha Oriental", "Argélia",
        "Catar", "Alemanha Ocidental", "Luxemburgo", "Irlanda", "Suíça", "Grécia",
        "Índia", "Rússia", "Equador", "México", "Guatemala", "Tanzânia", "Noruega",
        "Turquia", "Arábia Saudita", "Filipinas", "República Dominicana", "Porto Rico",
        "Zâmbia", "Uganda", "Sri Lanka", "Granada", "Costa do Marfim", "Dinamarca",
        "Japão", "Brasil", "Nigéria", "Bahamas", "Índias Ocidentais Britânicas", "Burundi",
        "Eslováquia", "Letônia", "Equipe Unificada", "Sudão", "Botsuana", "Bielorrússia",
        "Estônia", "República Tcheca", "Taiwan", "Cazaquistão", "Lituânia", "Irã",
        "Tajiquistão", "Eslovênia", "Ucrânia", "Romênia", "Haiti", "Coreia do Sul",
        "Argentina", "Chile", "Djibuti", "Iugoslávia", "Venezuela", "Brunei", "Áustria",
        "Colômbia", "Moçambique", "Croácia", "Síria", "Sérvia", "Islândia", "Camarões"
    };

    int totalG = 0;
    int totalB = 0;
    int totalS = 0;

    char cidade[TAM_STRING];
    int ano;

    printf("Digite o nome da cidade em que as olímpiadas ocorreram\n");
    recebeString(cidade);

    printf("Digite o ano em que as olímpiadas ocorreram\n");
    scanf("%d", &ano);
    setbuf(stdin, NULL);

    printf("%-10s\t | %-40s\t | %-5s\t | %-5s\t | %-5s\t\n", "SIGLA", "PAÍS", "🥇", "🥈", "🥉");

    for (int i = 0; i < NUM_PAISES; i++) {
        for (int j = 0; j < tamanhoArray; j++) { 
            if ((strcmp(cidade, medalhas[j].cidade) == 0 && ano == medalhas[j].ano) && (strcmp("null", medalhas[j].nome) != 0) && (strcmp(siglas[i], medalhas[j].pais) == 0)) {
                if (medalhas[j].gbs == 'G') {
                    totalG++;
                } else if (medalhas[j].gbs == 'B') {
                    totalB++;
                } else {
                    totalS++;
                }
            }
        }

        printf("%-10s\t | %-40s\t | %-5d | %-5d | %-5d\n", siglas[i], nomesDosPaises[i], totalG, totalS, totalB);

        totalG = totalB = totalS = 0;
    }
}