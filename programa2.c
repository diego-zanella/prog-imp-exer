#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define qtdados 20
 struct dados{
  int codigo;
  char nome[20];
  char sobrenome[20];
  int idade;
  double peso;
 };
 void mostrarDados(struct dados *_dados, FILE *arqBinario){
  for(int i =0; i<qtdados;i++){
    fread(&_dados, sizeof(_dados),qtdados,arqBinario);
    printf("%d\t%s\t%s\t%d\t%.2lf\n",_dados[i].codigo, _dados[i].nome, 
_dados[i].sobrenome, _dados[i].idade, _dados[i].peso);
  }
 }
 void somaIdades(struct dados *_dados, int *somaidades){
  int sumidades = 0;
  for(int i = 0; i < qtdados;i++){
    sumidades += _dados[i].idade;
  }
  printf("Soma da idade dos membros %d", sumidades);
 }
 void mediaPesos(struct dados *_dados, float *mediapeso){
  float avgpeso = 0;
  for(int i = 0; i < qtdados;i++){
    avgpeso += _dados[i].peso;
  }
  *mediapeso = avgpeso/qtdados;
  printf("Media de peso dos membros %f", *mediapeso);
 }
 int main() {
  FILE *arqTxt, *arqBinario, *arqRead;
  char escolha;
  struct dados _dados[qtdados];
  int somaidades = 0;
  float mediapeso = 0, avgpeso = 0;
  arqBinario = fopen("saida.bin","rb");
    if(arqBinario == NULL){
        printf("Falha ao ABRIR o arquivo binario");
        return 0;
    }
  fread(&_dados,sizeof(_dados),1,arqBinario);
  arqTxt = fopen("saida.txt", "w");
  printf("\nEscolha uma operação: ");
  printf("\n1 - Exibir dados");
  printf("\n2 - Gerar soma das idades");
  printf("\n3 - Gerar medias dos pesos\n");
  scanf("%c", &escolha);
    switch (escolha){
      case '1':
        mostrarDados(_dados, arqBinario);
        fclose(arqBinario);
        break;
      case '2':
        somaIdades(_dados, &somaidades);
        break;
      case '3':
        mediaPesos(_dados, &mediapeso);
        break;
      default:
        printf("Digito invalido");
        break;
    }
   fclose(arqBinario);
  return 0;
 }
 /*#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 struct dados{
  enum cod_res{cod1=1, cod2=2, cod3, cod4, cod5, cod6, cod7, cod8, cod9, cod10, 
cod11, cod12, cod13, cod14, cod15, cod16, cod17, cod18, cod19, cod20}codigo;
  char nome[20];
  char sobrenome[20];
  int idade;
  double peso;
 };
 int main() {
  FILE *arqTxt, *arqBinario, *arqRead;
  int  qtdados;
  char nomeTxt[50];
  arqBinario = fopen("saida.bin", "ab");
  if(arqBinario == NULL){
    printf("falha ao criar arquivo\n");
    return 0;
  }
  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s",nomeTxt);
  if ((arqTxt = fopen(nomeTxt,"r")) == NULL) {
    printf("Problema na abertura do arquivo %s.\n",nomeTxt);
    return -1;
  }
  fscanf(arqTxt,"%d",&qtdados);
  struct dados _dados[qtdados];
  for(int i =0; i<qtdados;i++)
    fscanf(arqTxt,"%d %s %s %d %lf", &_dados[i].codigo, _dados[i].nome, 
_dados[i].sobrenome, &_dados[i].idade, &_dados[i].peso);
  fclose(arqTxt);
  fwrite(_dados, sizeof(_dados), 1, arqBinario);
  fclose(arqBinario);
  arqRead = fopen("saida.bin","rb");
  if(arqRead==NULL){
    printf("falha ao abrir arquivo\n");
    return 0;
  }
  printf("%s\t%s\t%s\t%s\t%s\n","codigo","nome","sobrenome","idade","peso");
  for(int i =0; i<qtdados;i++){
    fread(&_dados, sizeof(_dados),1,arqRead);
    printf("%d\t%s\t%s\t%d\t%.2lf\n",_dados[i].codigo, _dados[i].nome, 
_dados[i].sobrenome, _dados[i].idade, _dados[i].peso);
  }
  putchar('\n');
  system("pause");
  fclose(arqRead);
  return 0;
 }*/