Projeto Prático
Medal Collection
Universidade Tecnológica Federal do Paraná (UTFPR), campus Apucarana
Curso de Engenharia de Computação
Fundamentos de Programação 2 – FDCO2B - 1◦Semestre 2024
Prof. Muriel de Souza Godoi

Nesta atividade os alunos deverão desenvolver um sistema que permita gerenciar as medalhas
olímpicas: Medal Collection utilizando a linguagem C e os conceitos visto em sala de aula. A
atividade deverá ser desenvolvida em trios impreterivelmente.
O sistema desenvolvido deverá obrigatoriamente contemplar, mas não estar restrito, aos
seguintes aspectos:
◦ Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
◦ Deverá gerar e exibir as tabelas ordenadas de totais medalhas por edição dos jogos
olímpicos (País, Ouro, Prata, Bronze), navegando entre elas. Para isso utilize cores,
sons e sua criatividade;
◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;
◦ Ao carregar o programa pela primeira vez, os dados iniciais de todas as medalhas deve
ser lido e carregado em um vetor de tamanho dinâmico e uma mensagem de boas
vindas será exibida ao usuário. Os dados estão disponibilizados no moodle em um
arquivo no formato .csv (valores separados por vírgula);
◦ Ao sair do programa, todos os dados sobre as medalhas devem ser salvos em arquivos
binários no HD. O mesmo arquivo binário deverá ser recarregado novamente ao iniciar o
programa nas próximas vezes;
◦ O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula).
Observações sobre o código:
◦ Os códigos referentes a cada estrutura devem estar em um arquivo fonte (.c) separado
com seu respectivo arquivo de cabeçalho(.h). Utilize outros arquivos para organizar seu
código conforme necessidade;
1
◦ O programa deverá acompanhar um arquivo makefile que permita as operações básicas
de make (compilação), clean (limpeza) e run (execução);
◦ Como parte do critério de avaliação, a qualidade do código-fonte do sistema será
avaliada. Organize seu programa em arquivos .c e .h, funções. Evite o uso de variáveis
globais. O código deverá estar comentado, edentado e com bons nomes de variáveis e
funções. Siga o padrão de documentação apresentado na disciplina (Doxygen).
• Parte Criativa (30% da nota)
◦ Adicione novas funcionalidades ao seu sistema de álbuns de maneira livre. Exemplos:
exibir tabela de recordes por modalidade; informar se um recorde for batido ao se
cadastrar uma nova medalha; quiz com pergunta sobre as olimpíadas com perguntas e
mini games; tabelas de totais de medalha por pais e/ou atleta; interface gráfica em GTK
ou outra biblioteca, reproduzir os hinos dos países sedes ou líderes; e o que mais sua
criatividade permitir. Para isso explore, além dos recursos vistos na disciplina e novos
recursos na internet.
• Entrega via Github
◦ Cada equipe deverá criar um repositório no Github, compartilhado entre os membros e
com o professor (Github user: murielgodoi). O link do repositório deverá ser enviado ao
professor até dia 17/05 juntamente com os dados iniciais.
Avaliação: Implementação + Apresentação
Além do envio do código fonte, os(as) alunos(as) deverão realizar uma apresentação projeto
que terá duração de 10 e 15 minutos. Durante a apresentação, deverão descrever a abordagem
utilizada e apresentar uma visão geral da implementação. Em seguida, deverão mostrar o
sistema em funcionamento. Após a apresentação, serão arguidos individualmente pelo professor
e pelos demais alunos da turma em relação ao desenvolvimento do projeto. A apresentação
será avaliada de acordo com os seguintes critérios:
● Respeito ao tempo estipulado para a apresentação;
● Criatividade na apresentação e no desenvolvimento do sistema;
● Coerência do projeto desenvolvido e o que foi apresentado;
● Domínio do projeto verificado por meio da explicação do código fonte;
