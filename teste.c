#include <stdio.h>
#include <stdlib.h>


int main(){


    FILE *arq;

    typedef struct 
    {
       char genero[5];
       char medalha[5];
       char cidade[50];
       char nome[50];
       char modalidade[50];
       char pais[50];

       int resultado;
       int ano;

    }Catalogo;
    

arq = fopen("medalhas.csv","r");



Catalogo cat[2394];

char l[1024];

int i = 0;


while (fgets(l,1024,arq))   /*Loop principal, atribui os conteúdos do arquivo as váriaveis do struct.
                             Uma condição do loop mais elegante deve ser encontrada*/
{
    fscanf(arq,"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d",cat[i].genero,cat[i].modalidade,cat[i].cidade,
    &cat[i].ano,cat[i].medalha,cat[i].nome,cat[i].pais,&cat[i].resultado);
    i++;
   


//Código de teste do funcionamento

for (int i = 0; i < 2393; i++)
{
    printf("%s %s %s %d %s %s %s %d \t \n",cat[i].genero,cat[i].modalidade,cat[i].cidade,cat[i].ano,
    cat[i].medalha,cat[i].nome,cat[i].pais,cat[i].resultado);



}
}