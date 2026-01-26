Exercícios de Programação Imperativa (Manipulação de Ficheiros em C)

Este repositório contém implementações práticas em C para a manipulação de dados estruturados, realizando a conversão de ficheiros de texto simples para formatos binários e executando operações estatísticas sobre os mesmos.


📁 Estrutura do Projeto

O projeto utiliza uma estrutura de dados personalizada para gerir informações de membros, incluindo código, nome, idade e peso.

entrada.txt: Ficheiro de texto contendo a base de dados inicial com 20 registos formatados.

programa1.c / programa2.c: Códigos fonte que implementam a lógica de:

Leitura de dados formatados de ficheiros .txt.

Persistência de dados em ficheiros binários (.bin) para maior eficiência.

Cálculo de métricas a partir dos ficheiros binários.


🛠️ Funcionalidades Implementadas

Os programas oferecem um menu interativo para processar os dados dos membros:

Exibição de Dados: Lê o ficheiro binário e formata os dados no terminal (Código, Nome, Sobrenome, Idade e Peso).

Soma de Idades: Percorre os registos para calcular a idade total acumulada de todos os membros.

Média de Pesos: Calcula o peso médio dos 20 membros registados.


💻 Conceitos Aplicados

Estruturas (Structs): Utilização de struct dados para encapsular múltiplos tipos de informação num único bloco.

Ficheiros Binários: Uso de fwrite e fread para armazenamento persistente de baixo nível.

Ponteiros: Passagem de parâmetros por referência em funções como somaIdades e mediaPesos.


🚀 Como Executar

Compile o código utilizando um compilador C (como o GCC):



gcc programa1.c -o programa1

Garanta que o ficheiro saida.bin foi gerado (ou utilize o código comentado no final dos ficheiros para converter o entrada.txt primeiro).

Execute o binário:



./programa1

Escolha a operação desejada no menu apresentado.
