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

   

int numAleatorio(){
int num;
srand(time(0));

    for (int i = 0; i < 1; i++) { 
         num = (rand() % 
        (1 - 0 + 1)) + 0; 
      
    } 
    return num;
}



void fatoCurioso(){

int num;
num = numAleatorio();

    char fato[5][400];

//Exemplos de  curiosidades
    strcpy(fato[0],"Os primeiros Jogos Olímpicos ocorreram no século VIII A.C. em Olímpia, na Grécia.\nEles eram realizados a cada quatro anos e assim continuaram por 12 séculos. \nEm seguida, no IV século D.C., todos os festivais pagãos foram proibidos pelo Imperador Teodósio I\ne isso incluiu também os Jogos Olímpicos.\n");
    
    strcpy(fato[1],"Na Grécia antiga, os atletas não se preocupavam com patrocínio, proteção ou moda; eles competiam nus.\n"); 

    printf("%s",Olimpiadas);
    printf("\n");
    printf("%s",fato[num]);
}