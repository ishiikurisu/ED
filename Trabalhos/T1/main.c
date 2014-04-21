#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*bibliotecas próprias*/
#include "count.h"
#include "result.h"

#ifdef win32
#define limpar() system("cls")
#else
#define limpar() system("clear")
#endif

/****************
FUNÇÕES MODULARES
****************/
typedef struct lista List;

void contar (List* palavra, List* pontuacao, FILE* fp) { 
  int tamanho;
  List* temp = (List*) malloc(sizeof(List));

  temp->prox = NULL;
  while (feof(fp) == 0) {
    tamanho = salvar (fp, temp); 
    /*Salva a palavra na lista temporária*/
    adicionar (temp, tamanho, palavra, pontuacao);
    /* Aumenta a frequencia da palavra na lista e prossegue*/
  }
}

int teste () {
  List *palavra[2], *pontuacao[2]; FILE* fp[2];
  int i;
  
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro para o arquivo.
  Índice 0 para o primeiro arquivo e
  índice 1 para o segundo.*/
  
  for (i = 0; i < 2; i++) {
    comecar (palavra[i]);
    comecar (pontuacao[i]);
    fp[i] = abrir(i); /*Atribui um arquivo a fp*/
    printf("o!%d\n", fp[i]);
    contar (palavra[i], pontuacao[i], fp[i]); /*Conta as palavras no arquivo*/
    ordernarPalavras (palavra[i]); /*Ordena as palavras no arquivo*/
    ordernarPalavras (pontuacao[i]); /*Idem, pontuação*/
    fclose(fp[i]);
  }
  mostrarResultado(palavra, pontuacao); /*Obtem e mostra os resultados*/
  return novamente(); /*Pergunta se quer repetir o processo*/
}

int menu() { 
  int resposta;

  limpar();
  printf("COMPARANDO ARQUIVOS\n\n");
  printf("1. COMPARAR ARQUIVOS\n");
  printf("2. SAIR\n\nOPCAO: ");
  scanf("%d", &resposta);
  
  if (resposta == 1) resposta = teste();
  else resposta = 0;
  
  return resposta;
}

int main () {
  while(menu()){pass();}
  return 0;
}
