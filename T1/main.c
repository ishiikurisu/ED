#include <stdlib.h>
#include <stdio.h>
#include "count.h"
#include "result.h"

void contar (List** palavra, FILE** fp) {
  char* lido; int tamanho;

  while ((*palavra)->next != NULL) {
    tamanho = descobrirTamanho(fp); //Descobre o tamanho da palavra
    salvar (tamanho, lido, fp);          //Adicionam a palavra na
    addFreq ((*palavra), lido[tamanho]); //lista
    tratar (lido); //Trata a palavra para que ela possa ser adicionada
    adicionar (lido, (*palavra)); //Aumenta a frequecia da palavra
    (*palavra) = (*word)->prox;   //na lista e prossegue
  }
}

int teste () {
  int i = 0;
  List* palavra[2]; FILE* fp[2];
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro 
  para o arquivo. Índice 0 para o pri-
  meiro arquivo e índice 1 para o segundo*/
  
  for (i = 0; i < 2; i++) {
    abrir (fp[i], i); //Atribui a fp um arquivo
    contar (palavra[i]); //Conta as palavras no arquivo
    ordernarPalavras (palavra[i], 0); //Ordena as palavras no arquivo
    fclose(fp[i]);
  }
  resultado(); //Mostra os resultados
  return novamente(); //Pergunta se quer repetir o processo
}

int menu() {
  int resposta;

  printf("COMPARANDO ARQUIVOS\n\n");
  printf("1. COMPARAR ARQUIVOS\n");
  printf("2. SAIR\n\nOPCAO: ");
  scanf("%d", &resposta);
  
  if (resposta) resposta = teste();
  else resposta = 0;
  
  return resposta;
}

int main () {
  while(menu()){NILL};
  return 0;
}
