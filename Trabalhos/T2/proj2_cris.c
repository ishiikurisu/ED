#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mostra.h"
#include "processamento.h"

#ifdef win32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

#define aproximacao 5 /*tempo de aproximacao*/
#define pouso 5 /*tempo de pouso*/
#define decolagem 5 /*tempo de decolagem*/

int geraRand(int min, int max) /*gera numeros aleatorios em uma faixa*/
{
  int r; /*numero aleatorio*/

  r = min + rand()%(max - min +1);/*gera o numero a aleatorio e atribui*/
  return r;/*devolve o numero aleatorio*/
}

void criaLista(No *lista) /*cria lista vazia*/
{
  lista->anterior = NULL;
  lista->proximo = NULL;
  lista-> comb = -1;  
}

No* insereLista (int estado, No *lista)
{  
  No *temp;
  if (lista -> comb == -1) /*testa se a lista esta vazia*/ 
  {
    if (estado == 1)
    {      
      lista -> estado = 'A';      
    }/*atribui o estado do aviao*/
    else
    {      
      lista -> estado = 'D';      
    }

    lista -> comb = geraRand(0,12);
    
    return lista;
  }/*testa se a lista esta vazia*/
  
  temp = malloc(sizeof(No));/*aloca memoria para o ponteiro */
  
  temp -> comb = geraRand(0,12);/*insere o combustivel aleatoriamente*/
  if(estado == 1)
  {  
    temp -> estado = 'A';       
  }
  else
  {    
    temp -> estado = 'D';          
  }
  
  temp -> proximo = lista -> proximo;/*aponta no sentido do final*/
  temp -> anterior = lista;/*aponta no sentido do inicio*/
  lista -> proximo = temp; /*faz o apontamento*/
  return temp;
}

No* geraVoos(int Naproximacao, No *lista, int estado)/*esse for cria nosso lista com voos desordenados*/
{  
  int i;

  for(i = 0; i < Naproximacao; i++)      
     lista = insereLista(estado,lista);

  return lista;
}

void criaPista(Fila *pista)
{  
  pista -> inicio = NULL;
  pista -> fim = NULL;
  
}

void nomeVoo (No *lista) /*gera o nome dos voos*/
{
  No *p;

  for(p = lista; p != NULL; p = p -> anterior) /*itera por toda lista para inserir os nomes*/
  {
    if(p -> estado == 'A')
    {      
      p -> nome[0] = 'A';
      p -> nome[1] = 'B';
      
    }
    else
    {  
      p -> nome[0] = 'C';
      p -> nome[1] = 'D';

    }    
    p -> nome[2] = geraRand(48,57); /*na tabela asc os numeros de 48 a 57*/
    p -> nome[3] = geraRand(48,57); /*sao caracteres de numeros*/
    p -> nome[4] = geraRand(48,57); /*desse modo aqui esta sendo adicionado */
    p -> nome[5] = geraRand(48,57); /*numeros a string nome*/
    p -> nome[6] = '\0'; /*encerra a string como sempre*/
    
  }  
}

int main() 
{
  /*VARIAVEIS*/
  int Naproximacao; /*recebe o numero de aproximacoes*/
  int Ndecolagem; /*recebe o numero de docolagens*/
  
  /*declaracao dos voos*/
  No *voos;
  
  /*declaracao das pistas*/
  Fila *pista1; 
  Fila *pista2;
  Fila *pista3;
  
  /*aloca memoria*/
  pista1 = malloc(sizeof(Fila)); /*somente dec*/
  pista2 = malloc(sizeof(Fila)); /*dec e ater*/
  pista3 = malloc(sizeof(Fila)); /*dec e ater*/ 
  voos = malloc(sizeof(No));
  
  /*FUNCOES*/
  criaLista(voos); /*cria a lista com as informacoes*/
  criaPista(pista1);/*cria a pista 1*/
  criaPista(pista2);/*cria a pista 2*/
  criaPista(pista3);/*cria a pista 3*/
  
  srand(time(NULL));/*pega a hora a sua como base para calculos aleatorios*/
  Naproximacao = geraRand(0, 26); /*define o numero de proximacoes que terao no programa*/
  Ndecolagem = geraRand(0, 16); /*define o numero de decolagens que terao no programa*/
  voos = geraVoos(Naproximacao,voos, 1); /*perceber que aqui temos o final da lista entao o proximo e NULL*/
  voos = geraVoos(Ndecolagem,voos, 2); /*perceber que aqui temos o final da lista entao o proximo e NULL*/
  nomeVoo(voos); /*gera os nomes dos voos*/

  mostra(voos);
  preenchePistas(voos, pista1, pista2, pista3);
  /*clear();*/
  liberaPistas(pista1, pista2, pista3);
  
  return 0;
}
