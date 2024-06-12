# Projeto Medal Collection

## Descrição do Projeto
Neste projeto, os alunos foram incumbidos de desenvolver um sistema em linguagem C para gerenciar medalhas olímpicas, denominado Medal Collection. O sistema deve ser desenvolvido em grupos de três alunos e deve aplicar os conceitos aprendidos em sala de aula. O sistema deve abranger os seguintes aspectos:

Definição da estrutura Medalha, incluindo campos como código, gênero, modalidade, cidade, ano, tipo de medalha (ouro, prata, bronze), nome do atleta, país de origem e resultado.
Funcionalidades de cadastro, listagem, pesquisa, alteração e exclusão de medalhas.
Geração e exibição de tabelas ordenadas dos totais de medalhas por edição dos Jogos Olímpicos (país, ouro, prata, bronze), com uso de cores e sons.
Interface intuitiva com menu inicial e possíveis submenus, utilizando cores e sons para facilitar a interação com o usuário.
Tratamento de erros do usuário com mensagens e alertas.
Carregamento inicial dos dados de todas as medalhas a partir de um arquivo CSV, e salvamento dos dados em arquivos binários ao sair do programa.
Opção de exportar os dados das estruturas para um arquivo CSV.
Organização do código em arquivos .c e .h, evitando o uso de variáveis globais e seguindo padrões de documentação como Doxygen.

# Estrutura de arquivos

/ProjetoMedalhas<br>
├── data/<br>
│   ├── medalhas.csv<br>
│   ├── medalhas.dat<br>
├── assets/<br>
│   ├── images/<br>
│   │   ├── atletas/<br>
│   │   │   └── atleta_1.jpg<br>
│   │   ├── bandeiras/<br>
│   │   │   └── brasil.png<br>
│   └── sounds/<br>
│       └── hinos/<br>
│           └── brasil.mp3<br>
├── include/<br>
│   ├── medalha.h<br>
│   ├── menu.h<br>
│   ├── util.h<br>
│   ├── gui.h<br>
│   ├── recordes.h<br>
│   ├── esportes.h<br>
│   └── pais.h<br>
├── src/<br>
│   ├── medalha.c<br>
│   ├── menu.c<br>
│   ├── util.c<br>
│   ├── gui.c<br>
│   ├── records.c<br>
│   ├── sports.c<br>
│   └── main.c<br>
├── makefile<br>
└── README.md<br>

## Descrição de cada diretório

<ul>
  <li>
    <strong>data/:</strong> Este diretório contém os arquivos de dados usados pelo programa. Ele armazena tanto os dados iniciais, que são carregados quando o programa é executado pela primeira vez, quanto os dados salvos durante a execução do programa.
    <ul>
      <li><strong>medalhas.csv:</strong> Arquivo CSV que contém os dados iniciais das medalhas, usado para carregar os dados na primeira execução.</li>
      <li><strong>medalhas.dat:</strong> Arquivo binário que contém os dados das medalhas salvos durante a execução do programa. Este arquivo é usado para carregar os dados nas execuções subsequentes.</li>
    </ul>
  </li>
  <li>
    <strong>assets/:</strong> Este diretório contém os recursos multimídia do programa, como imagens e sons.
    <ul>
      <li>
        <strong>images/:</strong> Contém subdiretórios para as fotos dos atletas e bandeiras dos países.
        <ul>
          <li><strong>atletas/:</strong> Armazena as fotos dos atletas.</li>
          <li><strong>bandeiras/:</strong> Armazena as bandeiras dos países.</li>
        </ul>
      </li>
      <li>
        <strong>sounds/:</strong> Contém subdiretórios para os hinos dos países.
        <ul>
          <li><strong>hinos/:</strong> Armazena os arquivos de áudio dos hinos dos países.</li>
        </ul>
      </li>
    </ul>
  </li>
  <li>
    <strong>include/:</strong> Este diretório contém os arquivos de cabeçalho (.h). Esses arquivos definem as estruturas de dados, constantes, declarações de funções e macros usados no projeto. Eles são incluídos nos arquivos fonte (.c) para fornecer as declarações necessárias.
    <ul>
      <li><strong>medalha.h:</strong> Define a estrutura Medalha e declara funções relacionadas ao gerenciamento das medalhas.</li>
      <li><strong>menu.h:</strong> Declara funções relacionadas ao menu do programa.</li>
      <li><strong>util.h:</strong> Declara funções utilitárias usadas em várias partes do programa.</li>
      <li><strong>gui.h:</strong> Declara funções relacionadas à interface gráfica usando GTK.</li>
      <li><strong>records.h:</strong> Declara funções para exibir e gerenciar os recordes.</li>
      <li><strong>esportes.h:</strong> Declara funções para exibir informações sobre modalidades esportivas.</li>
      <li><strong>pais.h:</strong> Declara funções para exibir informações sobre os países.</li>
    </ul>
  </li>
  <li>
    <strong>src/:</strong> Este diretório contém os arquivos fonte (.c). Cada arquivo fonte implementa as funções declaradas nos arquivos de cabeçalho correspondentes.
    <ul>
      <li><strong>medalha.c:</strong> Implementa as funções relacionadas ao gerenciamento da estrutura Medalha.</li>
      <li><strong>menu.c:</strong> Implementa as funções do menu do programa.</li>
      <li><strong>util.c:</strong> Implementa funções utilitárias, como limpar a tela e pausar a execução.</li>
      <li><strong>gui.c:</strong> Implementa as funções para a interface gráfica usando GTK.</li>
      <li><strong>records.c:</strong> Implementa as funções para exibir e gerenciar os recordes.</li>
      <li><strong>esportes.c:</strong> Implementa as funções para exibir informações sobre modalidades esportivas.</li>
      <li><strong>pais.c:</strong> Implementa as funções para exibir informações sobre os países.</li>
      <li><strong>main.c:</strong> Contém a função main, que é o ponto de entrada do programa. Ele carrega os dados, exibe a mensagem de boas-vindas e o menu, e salva os dados ao sair do programa.</li>
    </ul>
  </li>
</ul>

