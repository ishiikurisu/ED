#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//bibliotecas próprias
#include "count.h"
#include "result.h"

/****************
FUNÇÕES MODULARES
****************/
void contar (List* palavra, List* pontuacao, FILE* fp) { 
  char* lido; int tamanho;

  while (fp != NULL) {
    tamanho = descobrirTamanho(fp); // Descobre o tamanho da palavra
    lido = salvar (tamanho, lido, fp);          // Adiciona a palavra na memória do computador
    //tratar (lido); // Trata a palavra para que ela possa ser adicionada
    adicionar (lido, palavra, pontuacao);  // Aumenta a frequencia da palavra
    palavra = palavra->prox;               // na lista e prossegue
  }
}

int teste () {
  int i;
  List* palavra[2], pontuacao[2]; FILE* fp[2];
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro para o arquivo.
  Índice 0 para o primeiro arquivo e
  índice 1 para o segundo.*/
  
  for (i = 0; i < 2; i++) {
    abrir (fp[i], i); //Atribui um arquivo a fp
    contar (palavra[i], pontuacao[i], fp[i]); //Conta as palavras no arquivo
    ordernarPalavras (palavra[i]); //Ordena as palavras no arquivo
    ordernarPalavras (pontucao[i]); //Idem, pontuação
    fclose(fp[i]);
  }
  resultado(palavra); //Obtem e mostra os resultados
  return novamente(); //Pergunta se quer repetir o processo
}

int menu() { 
  int resposta;

  printf("COMPARANDO ARQUIVOS\n\n");
  printf("1. COMPARAR ARQUIVOS\n");
  printf("2. SAIR\n\nOPCAO: ");
  scanf("%d", &resposta);
  
  if (resposta == 1) resposta = teste();
  else resposta = 0;
  
  return resposta;
}

void pass() {return;} 
int main () {
  while(menu()){pass();}
  return 0;
}
