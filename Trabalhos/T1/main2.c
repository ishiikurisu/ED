#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*bibliotecas próprias*/
#include "count2.h"

/****************
FUNÇÕES MODULARES
****************/
typedef struct lista List;

int teste () {
  List *palavra[2], *pontuacao[2], *temp; FILE* fp[2];
  int i; char* lido; int tamanho;
  
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro para o arquivo.
  Índice 0 para o primeiro arquivo e
  índice 1 para o segundo.*/
  
  for (i = 0; i < 2; i++) {
    comecar (palavra[i]);
    comecar (pontuacao[i]);
    comecar (temp);
    fp[i] = abrir(i); /*Atribui um arquivo a fp*/
    printf("a...\n");
    do {
      temp = descobrirTamanho (fp[i], &tamanho); /*Salva a palavra em uma lista temporária*/
      printf("#TAG#");
      printf("t, ");
      salvar (tamanho, temp, palavra[i]); /*Adiciona a palavra na lista*/
      /*lido = salvar (tamanho, &fp[i]);*/
      printf("s, ");
      printf("%s\n", lido);
      getchar();
      getchar();
    } while (lido[0] != EOF);
    fclose(fp[i]);
  }
  /*mostrarResultado(palavra, pontuacao); /*Obtem e mostra os resultados*/
  return 0; /*Pergunta se quer repetir o processo*/
}

int main () {
  while(teste()){pass();}
  return 0;
}
