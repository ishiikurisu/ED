/*
# INDICE
+ DEFINICOES
  + define bool
  + define inc(A) 
  + struct no
  + ignorar()
  + alerta()
  + escrever_resultado()
+ FUNCOES DE LISTA
  + nova_lista()
  + presente_na_lista()
  + escrever_estradas()
  + escrever_mapa()
+ FUNCOES DE LEITURA
  + identificar_cidade()
  + gerar_mapa()
  + atualizar_cidades()
+ FUNCOES DE ALGORITMO
  + nocmp()
  + presente_no_grafo()
  + todos_incluidos()
  + menor_vizinho()
  + primeiro_vizinho()
  + prim()
+ FUNCOES PRINCIPAIS
  + leitura_do_arquivo()
  + main ()
*/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
 
/*********
DEFINICOES
*********/
/*esta eh a definicao de limpeza de tela*/
#ifdef win32
#define limpar() system("cls")
#else
#define limpar() system("clear")
#endif

/*esta eh a definicao do tipo de variavel booleana*/
#define bool int
#define true 1
#define false 0
 
/*esta eh a definicao do operador de incremento para o TAD no**/
#define inc(A) (A) = (A)->direita
 
/*
este eh o TAD que sera no programa. com esta uniao, pode-se
criar listas e grafos. neste caso, trabalharemos com duas listas:
uma lista de adjacencias e uma lista de nos; ambas descreverao
o grafo que representara as cidades.
*/
typedef struct no {
  char* cidade_1;
  char* cidade_2;
  int info;
  struct no* direita;
  struct no* esquerda;
  struct no* estado;
} no;
 
/*definicao de uma funcao auxiliar que nao faz nada*/
void ignorar(){return;}
void alerta() {printf("<ALERTA>"); fflush(stdout);}
void escrever_resultado(bool resultado)
{
  if (resultado == true)
    printf("true\n");
  else
    printf("false\n");

  return;
}
 
/***************
FUNCOES DE LISTA
***************/
/*esta funcao cria uma lista vazia*/
no* nova_lista()
{
  no* lista = (no*) malloc(sizeof(no));
 
  lista->cidade_1 = lista->cidade_2 = NULL;
  lista->info = false;
  lista->direita = lista->esquerda = NULL;
 
  return lista;
}
 
/*esta funcao checa se um nome esta na lista*/
bool presente_na_lista (no* lista, char* nome)
{
  no* item = lista;
  bool resultado = false;
  
  while (resultado == false && item != NULL)
  {
    if 
    (
      (item->cidade_1 != NULL && strcmp(nome, item->cidade_1) == 0) ||
      (item->cidade_2 != NULL && strcmp(nome, item->cidade_2) == 0)
    ) 
      resultado = true;
    else 
      inc(item);
  }
 
  return resultado;
}
 
/*esta funcao escreve quais conexoes existem entre as cidade*/
void escrever_estradas(no* estradas)
{
  no* trecho = estradas;
	
  puts("# ESTRADAS");
  while (trecho != NULL)
  {
    if (trecho->cidade_1 != NULL && trecho->cidade_2 != NULL)
    {
      printf("+ %s - %s: ", trecho->cidade_1, trecho->cidade_2);
      printf("%d km\n", trecho->info);
    }
    inc(trecho);
  }
	
  return;
}
 
/*esta funcao mostra quais cidades estao cadastradas no mapa*/
void escrever_mapa(no* mapa)
{
  no* cidade = mapa;
  int i = -1;
 
  puts("# CIDADES:");
  while (cidade != NULL)
  {
    if (cidade->cidade_1 != NULL)
    {
      printf("+ %s\n", cidade->cidade_1);
      ++i;
    }
    inc(cidade);
  }
 
  printf("## TOTAL: %d\n", i);
  return;
}
 
/*****************
FUNCOES DE LEITURA
*****************/
/*esta funcao le uma cidade do arquivo fornecido*/
char* identificar_cidade (FILE* fp)
{
  int tamanho = 0;
  char* nome = (char*) malloc(sizeof(char));
 
  do
  {
    tamanho++;
    fscanf(fp, "%c", &nome[tamanho-1]);
    nome = (char*) realloc(nome, (tamanho+1)*sizeof(char));
  }
  while (isalnum(nome[tamanho-1]) || nome[tamanho-1] == ' ');
  nome[tamanho-1] = '\0';
 
  return nome;
}
 
/*esta funcao gera uma lista de nos a partir de uma lista de adjacencias*/
no* gerar_mapa (no* estradas)
{
  no* mapa = nova_lista();
  no* cidade = mapa;
  no* estrada;
 
  for (estrada = estradas; estrada != NULL; inc(estrada))
  {
    if (presente_na_lista(mapa, estrada->cidade_1) == false)
    {
      cidade->cidade_1 = estrada->cidade_1;
      cidade->direita = nova_lista();
      inc(cidade);
    }
    if (presente_na_lista(mapa, estrada->cidade_2) == false)
    {
      cidade->cidade_1 = estrada->cidade_2;
      cidade->direita = nova_lista();
      inc(cidade);
    }
  }
 
  return mapa;
}
 
/*esta funcao gera um novo trecho para ser adicionado na lista de estradas*/
no* atualizar_estradas (char* cidade_a, char* cidade_b, int distancia)
{
  no* trecho = nova_lista();
 
  trecho->cidade_1 = cidade_a;
  trecho->cidade_2 = cidade_b;
  trecho->info = distancia;
  trecho->direita = NULL;
 
  return trecho;
}
 
/*FUNCOES DE ALGORITMO*/
/*esta funcao checa se dois nos sao iguais*/
bool nocmp(no* trecho_a, no* trecho_b)
{
  bool resultado = false;
  
  if (strcmp(trecho_a->cidade_1, trecho_b->cidade_1) == 0)
  if (strcmp(trecho_a->cidade_2, trecho_b->cidade_2) == 0)
    resultado = true;
    
  if (strcmp(trecho_a->cidade_1, trecho_b->cidade_2) == 0)
  if (strcmp(trecho_a->cidade_2, trecho_b->cidade_1) == 0)
    resultado = true;
  
  return resultado;
}

/*esta funcao checa se um no esta presente em um lista de adjacencias*/
bool presente_no_grafo (no* suspeito, no* grafo)
{
  bool resultado = false;
  no* item = grafo;
  
  if (suspeito->cidade_1 == NULL || suspeito->cidade_2 == NULL)
    return false;
  
  while (resultado == false && item != NULL)
  {
    while (item->cidade_1 == NULL || item->cidade_2 == NULL)
      inc(item);
    
    resultado = nocmp(item, suspeito);    
    inc(item);
  }
  
  return resultado;
}

/*
+ esta funcao checa se a lista de nos total e igual a lista de nos parcial
+ ela passa por cada um no*s da lista de no*s total checando se eles estao
  presentes na lista de no*s parcial. se algum deles nao estiver presente,
  a funcao ja retorna o valor falso;
*/
bool todos_incluidos (no* mapa, no* cidades_incluidas)
{
  bool resultado = true;
  no* cidade = mapa;

  cidade = mapa;
  while (cidade != NULL && resultado == true)
  {    
    while (cidade != NULL && cidade->cidade_1 == NULL)
      inc(cidade);
    
    if (cidade == NULL) 
      return true;
  
    resultado = presente_na_lista(cidades_incluidas, cidade->cidade_1);
    inc(cidade);  
  }

  return resultado;
}

/*
+ as duas proximas funcoes descobrem qual o menor trecho disponivel por enquanto
+ ela percorre todos os trechos do grafo, procurando pelos vertices que possuem
  alguma cidade dentro das cidades incluidas. destes vertices, vamos escolher qual
  o menor e retorna-lo.
*/
no* menor_vizinho (no* cidades_incluidas, no* estradas, no* arvore_minima)
{
  no* vizinho;
  no* arvore;
  no* trecho;
  no* cidade;
  int distancia = INT_MAX;
  char* nome_cidade;
  
  for (cidade = cidades_incluidas; cidade != NULL ; inc(cidade))
  {
    nome_cidade = cidade->cidade_1;
    
    if (nome_cidade != NULL)
    for (trecho = estradas; trecho != NULL; inc(trecho))
    {
      /*printf("\t# %s = %s\n", trecho->cidade_1, trecho->cidade_2);*/
      while 
      (
        trecho != NULL &&
        (
          presente_no_grafo(trecho, arvore_minima) == true ||
          trecho->cidade_1 == NULL || trecho->cidade_2 == NULL
        )
      )
      {
        /*printf("\t! %s = %s\n", trecho->cidade_1, trecho->cidade_2);*/
        inc(trecho);
      }
        
      if (trecho == NULL) break;
      
      if (strcmp(trecho->cidade_1, nome_cidade) == 0)
      if (presente_na_lista(cidades_incluidas, trecho->cidade_2) == false)
      if (trecho->info < distancia)
      {
        distancia = trecho->info;
        vizinho = trecho;
      }
      if (strcmp(trecho->cidade_2, nome_cidade) == 0)
      if (trecho->info < distancia)
      if (presente_na_lista(cidades_incluidas, trecho->cidade_1) == false)
      {
        distancia = trecho->info;
        vizinho = trecho;
      }
    }
  }
  
  return vizinho;
}
no* primeiro_vizinho(no* estradas, char* cidade)
{
  no* trecho;
  no* vizinho;
  int distancia = INT_MAX;
  
  for (trecho = estradas; trecho != NULL; inc(trecho))
  {
    while (trecho->cidade_1 == NULL || trecho->cidade_2 == NULL)
      inc(trecho);
    
    if (strcmp(cidade, trecho->cidade_1) == 0 ||
        strcmp(cidade, trecho->cidade_2) == 0)
    if (distancia > trecho->info)
    {
      distancia = trecho->info;
      vizinho = trecho;
    }
  }
  
  return vizinho;
}

/*
+ esta funcao aplica o algoritmo de Prim para descobrir a arvore
minima de um grafo. o algoritmo de Prim consiste em:
  + escolher um no aleatorio
  + a partir deste no, escolher a ligacao de menor peso
  + repetir o segundo passo enquanto houverem nos sobrando
+ aqui, vamos construir a arvore minima usando duas listas: uma de
nos parciais e outra de adjacencias parciais.
*/
no* prim(no* mapa, no* estradas)
{
  /*variaveis para construcao da arvore minima*/
  no* arvore_minima = nova_lista(); /*lista de adjacencias parcial*/
  no* cidades_incluidas = nova_lista(); /*lista de nos parcial*/
  no* arvore = arvore_minima;
  no* cidade_atual = cidades_incluidas;
  
  /*variaveis do grafo fixo*/
  no* cidade = mapa;
  no* vizinho;
  int distancia_percorrida = 0;
  
  puts("\n\n# PRIM");
  /*# primeiro passo*/
  while (cidade->cidade_1 == NULL)
    inc(cidade);
  arvore->cidade_1 = NULL;
  arvore->cidade_2 = cidade->cidade_1;
  cidade_atual->cidade_1 = cidade->cidade_1;
  cidade_atual->direita = nova_lista();
  inc(cidade_atual);
  
  /*# segundo passo*/
  vizinho = primeiro_vizinho(estradas, arvore->cidade_2);
  
  /*+ atualizacao da lista de nos parcial*/
  cidade_atual->cidade_1 = vizinho->cidade_2;
  cidade_atual->direita = nova_lista();
  inc(cidade_atual);
  
  /*+ atualizacao da lista de adjacencias parcial*/
  arvore->direita = atualizar_estradas(vizinho->cidade_1, vizinho->cidade_2, vizinho->info);
  inc(arvore);
  
  /*passos seguintes*/
  while (todos_incluidos(mapa, cidades_incluidas) == false)
  {
    vizinho = menor_vizinho(cidades_incluidas, estradas, arvore_minima->direita);
    
    /*atualizacao da lista de nos parciais*/
    if (presente_na_lista(cidades_incluidas, vizinho->cidade_1) == true)
      cidade_atual->cidade_1 = vizinho->cidade_2;
    else
      cidade_atual->cidade_1 = vizinho->cidade_1;
    cidade_atual->direita = nova_lista();
    inc(cidade_atual);
    
    /*atualizacao da arvore*/
    arvore->direita = atualizar_estradas(vizinho->cidade_1, vizinho->cidade_2, vizinho->info);
    inc(arvore);
    distancia_percorrida += vizinho->info;
    
    /*
    demonstracao da atualizacao
    puts("## ARVORE PARCIAL ATUAL");
    escrever_estradas(arvore_minima);
    escrever_mapa(cidades_incluidas);
    */
  }
 
  return arvore_minima;
}
 
/*****************
FUNCOES PRINCIPAIS
*****************/
/*esta funcao gera, para cada linha do arquivo, um trecho e o adiciona
a lista de estradas*/
no* leitura_do_arquivo (FILE* fp)
{
  char* cidade_a;
  char* cidade_b;
  int distancia;
  no* estradas = nova_lista();
  no* trecho = estradas;
 
  while (!feof(fp))
  {
    cidade_a = identificar_cidade(fp);
    cidade_b = identificar_cidade(fp);
    fscanf(fp, "%d\n", &distancia);
 
    trecho->direita = atualizar_estradas(cidade_a, cidade_b, distancia);
    inc(trecho);
  }
 
  return estradas;
}
 
int main ()
{
  FILE* fp = fopen("entrada.txt", "r");
  no* estradas = leitura_do_arquivo(fp);
  no* mapa = gerar_mapa(estradas);
 
  puts("# GRAFO TOTAL");
  escrever_estradas(estradas);
  escrever_mapa(mapa);
  
  no* rota_minima = prim(mapa, estradas);
 
  limpar();
  puts("# ARVORE MINIMA");
  escrever_estradas(rota_minima);
 
  fclose(fp);
  return 0;
}
 
/*
# IDEIAS
+ nil
# LISTA DE AFAZERES
- [ ] descobrir por que ha itens nulos na lista de nos
  + por enquanto, eles estao escondidos, mas isto nao quer dizer
    que eles sumiram
- [X] escrever algoritmo de Prim
- [ ] escrever arvore minima como uma arvore comum
*/