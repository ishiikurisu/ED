#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define aproximacao 5/*tempo de aproximacao*/
#define pouso 5 /*tempo de pouso*/
#define decolagem 5/*tempo de decolagem*/

typedef struct no {

  int comb;/*combustivel do aviao*/
  char estado;/*aproximacao ou decolagem*/
  char nome[10];/*nome do voo*/
  struct no *proximo;/*aponta o proximo da lista*/
  struct no *anterior;/*aponta o anterior da lista*/
}No;

typedef struct fila {

  No *inicio;/*ponteiro que marca o inicio da fila*/
  No *fim;/*ponteiro que marca o fim da fila*/
}Fila;

int geraRand(int mim, int max){/*gera numeros aleatorios em uma faixa*/

  int r;/*numero aleatorio*/
  r = mim + rand()%(max - mim +1);/*gera o numero a aleatorio e atribui*/
  return r;/*devolve o numero aleatorio*/
}/*fecha a funcao*/

void criaLista(No *lista){/*cria fila vazia*/

  lista->anterior = NULL;
  lista->proximo = NULL;
  lista-> comb = -1;
  
}/*fecha a funcao*/

No* insereLista(int estado, No *lista){
  
  No *temp;
  if(lista -> comb == -1){/*testa se a lsita esta vazia*/
    if(estado == 1){
      
      lista -> estado = 'A';
      
    }/*atribui o estado do aviao*/
    else{
      
            lista -> estado = 'D';
      
    }/*fecha o else*/
    lista -> comb = geraRand(0,12);
    
    return lista;
  }/*testa se a lista esta vazia*/
  
  temp = malloc(sizeof(No));/*aloca memoria para o ponteiro */
  
  temp -> comb = geraRand(0,12);/*insere o combustivel aleatoriamente*/
  if(estado == 1){
  
    temp -> estado = 'A';   
    
  }/*fecha o if*/
  else{
    
    temp -> estado = 'D';       
    
  }/*fecha o else*/
  
  temp -> proximo = lista -> proximo;/*aponta no sentido do final*/
  temp -> anterior = lista;/*aponta no sentido do inicio*/
  lista -> proximo = temp; /*faz o apontamento*/
  return temp;
}/*fecha a funcao no*/

No* geraVoos(int Naproximacao, No *lista, int estado){
  
  int i;
  for(i = 0; i < Naproximacao; i++){
      
     lista =  insereLista(estado,lista);
    
  }/*esse for cria nosso lista com voos desordenados*/
  
  return lista;
}/*fecha a funcao*/

void criaPista(Fila *pista){
  
  pista -> inicio = NULL;
  pista -> fim = NULL;
  
}/*fecha a funcao*/

void nomeVoo(No *lista){/*gera o nome dos voos*/
  
  No *p;
  for(p = lista; p != NULL; p = p -> anterior){/*itera por toda lista para inserir os nomes*/
    if(p -> estado == 'A'){
      
      p -> nome[0] = 'A';
      p -> nome[1] = 'B';
      
    }/*fecha o if*/
    else{
      
      p -> nome[0] = 'C';
      p -> nome[1] = 'D';

    }/*fecha o else*/
    
      p -> nome[2] = geraRand(48,57);/*na tabela asc os numeros de 48 a 57*/
      p -> nome[3] = geraRand(48,57);/*sao caracteres de numeros*/
      p -> nome[4] = geraRand(48,57);/*desse modo aqui esta sendo adicionado */
      p -> nome[5] = geraRand(48,57);/*numeros a string nome*/
      p -> nome[6] = '\0';/*encerra a string como sempre*/
    
  }/*termina o for*/
  
  
}/*fecha funcao*/

No* retiraDaLista(No *lista){/*quando um aviao entra na pista sai da lista*/
  
  No *aux;
  No *ant;
  No *prox;
  aux = lista;
  prox = aux -> proximo;
  ant = aux -> anterior;
  if(aux -> proximo == NULL){/*retira do final lista*/
    
    lista = aux -> anterior;
    ant -> proximo = aux -> proximo;
    
  }/*fecha o if*/
  else if(aux -> anterior == NULL){/*retira do final*/
    
    lista = aux -> proximo;
    prox -> anterior = aux -> anterior;
    
  }/*fecha o if*/
  else{
    
    ant -> proximo = prox;
    prox -> anterior = ant;
    lista = aux -> proximo;
  }/*fecha o if*/
  free(aux);
  
  return lista;
}/*fecha a funcao*/

int main(){

  int Naproximacao;/*recebe o numero de aproximacoes*/
  int Ndecolagem;/*recebe o numero de docolagens*/
  
  No *voos;/*declaracao dos voos*/
  
  Fila *pista1;/*declaracao das pistas*/
  Fila *pista2;/*declaracao das pistas*/
  Fila *pista3;/*declaracao das pistas*/
  
  pista1 = malloc(sizeof(Fila));/*aloca memoria*/
  pista2 = malloc(sizeof(Fila));/*aloca memoria*/
  pista3 = malloc(sizeof(Fila));/*aloca memoria*/
  
  voos = malloc(sizeof(No));/*aloca memoria*/
  
  criaLista(voos);/*cria a lista com as informacoes*/
  criaPista(pista1);/*cria a pista 1*/
  criaPista(pista2);/*cria a pista 2*/
  criaPista(pista3);/*cria a pista 3*/
  
  srand(time(NULL));/*pega a hora a sua como base para calculos aleatorios*/
  Naproximacao = geraRand(0,26);/*define o numero de proximacoes que terao no programa*/
  Ndecolagem = geraRand(0,16);/*define o numero de decolagens que terao no programa*/
  voos = geraVoos(Naproximacao,voos,1);/*perceber que aqui temos o final da lista entao o proximo e NULL*/
  voos = geraVoos(Ndecolagem,voos,2);/*perceber que aqui temos o final da lista entao o proximo e NULL*/
  nomeVoo(voos);/*gera os nomes dos voos*/
  
  return 0;
}/*fecha a main*/