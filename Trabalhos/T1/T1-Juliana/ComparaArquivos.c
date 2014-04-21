#include <stdlib.h>
#include <stdio.h>
#include "count.h"
#include "result.h"

void contar (List** palavra, List** pontuacao, FILE** fp) { //TIRAR PONTEIRO DE PONTEIRO
  char* lido; int tamanho;

  while (fp != NULL) { //ENQUANTO O ARQUIVO NAO TERMINA
    tamanho = descobrirTamanho(fp); //Descobre o tamanho da palavra
    lido = salvar (tamanho, lido, fp);          //Adicionam a palavra na lista
    //tratar (lido); //Trata a palavra para que ela possa ser adicionada
    adicionar (lido, (*pontuacao), (*palavra)); //Aumenta a frequecia da palavra e adiociona se nao existir
    (*palavra) = (*)->prox;   //na lista e prossegue
  }
}

int teste () {
  int i = 0;
  List* palavra[2], pontuacao[2]; FILE* fp[2];
  /*Para cada um dos arquivos, teremos
  uma lista e um ponteiro 
  para o arquivo. Indice 0 para o pri-
  meiro arquivo e Indice 1 para o segundo*/
  
  for (i = 0; i < 2; i++) {
    abrir_arquivo (fp[i], i); //Atribui a fp um arquivo
    contar (palavra[i], pontuacao[i], fp[i]); //Conta as palavras no arquivo //ESTAVA FALTANDO O ENVIO DO PARAMETRO FP
    ordernarPalavras (palavra[i]); //Ordena as palavras no arquivo
    ordernarPalavras (pontuacao[i]); //Ordena os sinais de pontuacao
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
  
  if (resposta){
    
    abrir_
      resposta = teste()
    };
  else resposta = 0;
  
  return resposta;
}

int main () {
  while(menu()){NULL};//seria null, certo?
  return 0;
}