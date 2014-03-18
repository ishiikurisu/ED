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
void contar (List** palavra, FILE** fp) {
  char* lido; int tamanho;

  while ((*palavra)->next != NULL) {
    tamanho = descobrirTamanho(fp); //+ Descobre o tamanho da palavra
    salvar (tamanho, lido, fp);          //+ Adicionam a palavra na
    addFreq ((*palavra), lido[tamanho]); //  memória do computador
    tratar (lido); //+ Trata a palavra para que ela possa ser adicionada
    adicionar (lido, (*palavra));  //+ Aumenta a frequecia da palavra
    (*palavra) = (*palavra)->prox; //  na lista e prossegue
  }
}

int teste () {
  int i = 0;
  List* palavra[2]; FILE* fp[2];
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro para o arquivo.
  Índice 0 para o primeiro arquivo e
  índice 1 para o segundo.*/
  
  for (i = 0; i < 2; i++) {
    abrir (fp[i], i); //Atribui a fp um arquivo
    contar (palavra[i], fp[i]); //Conta as palavras no arquivo
    ordernarPalavras (palavra[i], 0); //Ordena as palavras no arquivo
    fclose(fp[i]);
  }
  mostrarResultado(palavra); //Obtem e mostra os resultados
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
