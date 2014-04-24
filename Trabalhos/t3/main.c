#include <stdlib.h>
#include <stdio.h>

int tamanho = 0;

#include "def.h"
//#include "jogar.h"
#include "jogar.h"


int mult10 (int t) {
  int i, result = 1;

  for (i = 0; i < t; i++)
    result *= 10;

  return result;
}

void lerArquivo (no *tabuleiro) 
{
  FILE* fp;
  no *tab;
  int /*tamanho = 0,*/ i = -1, j = 0, x, y;
  char valor[3];

  fp = fopen("file.txt", "r");

  /*leitura do tamanho*/
  puts("leitura do tamanho");
  do
  {
    i++;
    fscanf(fp, "%c", &valor[i]);
  }
  while (valor[i] != ' ' && valor[i] != '\n');
  
  /*alocacao de memoria*/
  puts("alocacao");
  for(i = i-1; i >= 0; i--, j++)
    tamanho += (valor[i] - 48) * mult10(j);

  tab = tabuleiro->prox = (no*) malloc(sizeof(no));

  /*leitura da matriz*/
  puts("atribuicao");

  i = j = x = y = 0;
  while(!feof(fp))
  {
    fscanf(fp, "%c", &valor[i]);
    if 
    (
      (valor[i] == ' ' || valor[i] == '\n') && 
      (valor[i-1] != '\n')
    )
    {
      /*criacao de um no novo*/
      tab->prox = (no*) malloc(sizeof(no));
      tab->prox->ant = tab;
      tab = tab->prox;

      /*atribuicao de valores*/
      tab->info = 0;
      tab->pos[0] = x;
      tab->pos[1] = y;

      if (valor[0] == '0')
        tab->estado = 0;
      else 
      {
        for(i = i-1; i >= 0; i--, j++)
          tab->info += (valor[i] - 48) * mult10(j);
        tab->estado = -1;
      }
      i = j = 0;
      /*mudanca de posicao*/
      if (y == tamanho - 1) {
        y = 0;
        x++;
      }
      else
        y++;
    }
    else
      i++;
  }

  tabuleiro->prox = tabuleiro->prox->prox;
  tabuleiro->prox->ant = tabuleiro;
  fclose(fp);
}

int main ()
{
  no* tabuleiro;

  tabuleiro = criarTabuleiro(tabuleiro);
  lerArquivo(tabuleiro);
  mostrar(tabuleiro);
  if (jogar(tabuleiro))
    puts("SOLUCAO: ");
  else
    puts("ESTE TABULEIRO NÃO POSSUI SOLUÇÃO: ");
  mostrar(tabuleiro);

  return 0;
}

