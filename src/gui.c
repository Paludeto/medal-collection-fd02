#include "../include/gui.h"



const char * Olimpiadas = "          ^^^^^^^^^^~^                      ^$$$$$$$$$$~                      :^^^^^^^^^^          \n"
    "      .^^^^^^^:.:-^^^^^^^                $$$$$$$=::=$$$$$$$                ^^^^^^^-..:^^^^^^^      \n"
    "    -^^^+             .^^^^.          :$$$$.            .$$$$:          .^^^^.             +^^^=   \n"
    "   ^^^-                  ^^^^        $$$#                  #$$$        +^^^                  :^^^  \n"
    " .^^^                     .^^^      $$$                      $$$.     ^^^.                     ^^^.\n"
    ".^^^                       .^^+    $$$.                      .$$$    +^^.                       ^^^\n"
    "^^^                         +^^.  =$$=                        -$$=  .^^+                         ^^\n"
    "^^^                          ^^-  %$$                          $$%  -^^                          ^^\n"
    "^^^                      .---^^+--------.                  .^^^$$$********:                      ^^^\n"
    "^^^                   .------^^:  #$$:-----              ^^^^^-$$#  .^^-^^^^^.                   ^^^\n"
    ".^^=                .----   ^^^    $$$   ----          ^^^^   $$$    ^^^   ^^^^.                =^^.\n"
    " +^^-              :---    ^^^.    -$$%   .---.      .^^^.   %$$=    .^^^    ^^^=              :^^+ \n"
    "  +^^+            :--:    ^^^.      -$$$    ---.    .^^+    $$$=      .^^^    -^^=            +^^+  \n"
    "   .^^^+         .---  .^^^^          $$$$   ---    ^^^   $$$$          ^^^^.  +^^.         +^^^.   \n"
    "     :^^^^^:     ----^^^^^             .$$$$$---:  :^^-$$$$$.             ^^^^^-^^+     .+^^^^:     \n"
    "        -^^^^^^^^---^^^.                  :$$$$$$$$^^^$$$:                  .^^^^^^^^^^^-        \n"
    "                 ---                         .---  +^^.                         ^^^                 \n"
    "                 :--.                        :--.  .^^-                        .^^-                 \n"
    "                  ---                        ---    ^^^                        ^^^                  \n"
    "                   ---                     .---      ^^^.                     ^^^                   \n"
    "                    ---:                  ----        ^^^+                  -^^^.                   \n"
    "                     :----             .----.          .^^^^.             +^^^-                     \n"
    "                       .-------...:-------                ^^^^^^^-.:-^^^^^^^                        \n"
    "                           :----------:                      :^^^^^^^^^^                            \n";

   

int numAleatorio() {
    return rand() % 20; // Gera um número aleatório entre 0 e 19
}



void fatoCurioso(){

srand(time(0));

int num;

num = numAleatorio();

     char curiosidades[20][400] = {
        "1. Os Jogos Olímpicos da Antiguidade eram realizados em Olímpia, na Grécia, a cada quatro anos, a partir de 776 a.C.",
        "2. As mulheres eram proibidas de competir ou assistir aos Jogos Olímpicos na Grécia Antiga.",
        "3. O Barão Pierre de Coubertin é considerado o pai das Olimpíadas modernas, que começaram em 1896 em Atenas.",
        "4. O nadador Michael Phelps é o atleta olímpico mais condecorado de todos os tempos, com 23 medalhas de ouro.",
        "5. O jamaicano Usain Bolt é considerado o homem mais rápido do mundo, com recordes olímpicos nos 100m e 200m.",
        "6. As Olimpíadas de Tóquio 2020 foram adiadas para 2021 devido à pandemia de COVID-19, \numa decisão inédita na história moderna.",
        "7. A primeira mulher a ganhar uma medalha olímpica foi a tenista britânica Charlotte Cooper, em 1900.",
        "8. A tocha olímpica é acesa na Grécia e transportada até a cidade-sede dos Jogos por meio de um revezamento.",
        "9. O pentatlo moderno é composto por cinco disciplinas: esgrima, natação, hipismo, tiro e corrida.",
        "10. As Olimpíadas de Inverno, que começaram em 1924, incluem esportes como esqui, hóquei no gelo e patinação artística.",
        "11. A cerimônia de abertura das Olimpíadas é um evento grandioso, com desfiles de atletas, acendimento da pira olímpica e apresentações culturais.",
        "12. O mascote olímpico é um personagem que representa o espírito dos Jogos e da cidade-sede.",
        "13. A Vila Olímpica é o local onde os atletas ficam hospedados durante os Jogos.",
        "14. O símbolo olímpico dos cinco anéis representa a união dos cinco continentes e as cores foram escolhidas porque pelo menos \numa delas está presente em cada bandeira nacional.",
        "15. As Paralimpíadas ocorrem logo após as Olimpíadas, com atletas com deficiências físicas competindo em esportes adaptados.",
        "16. O Maracanã, no Rio de Janeiro, foi o palco da cerimônia de abertura dos Jogos Olímpicos de 2016.",
        "17. Em 1920, nos Jogos de Antuérpia, a bandeira olímpica com os cinco anéis entrelaçados foi usada pela primeira vez.",
        "18. O atleta finlandês Paavo Nurmi, conhecido como o 'Finlandês Voador', \nganhou nove medalhas de ouro em corridas de longa distância nas Olimpíadas de 1920, 1924 e 1928.",
        "19. A nadadora americana Katie Ledecky, com várias medalhas de ouro, é uma das maiores nadadoras da história olímpica.",
        "20. O judoca japonês Tadahiro Nomura é o único atleta a ganhar três medalhas de ouro olímpicas consecutivas na mesma categoria de peso."
    };

    printf("%s",Olimpiadas);
    printf("\n");
    printf("%s",curiosidades[num]);
    printf("\n");
}