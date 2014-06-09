/*
UNIVERSIDADE DE BRASILIA
DEPARTAMENTO DE CIENCIA DA COMPUTACAO
Materia:
  Estruturas de Dados
Professor:
  Dibio Borges

Aluno:
  Cristiano Silva Jr. 13/0070629

Descricao:
  Este programa le uma lista de amizades e a aplica
  a funcao que gera rankings na maquina de buscas
  Google. Sua funcao eh descobrir qual pessoa eh a
  mais influente dentro deste grupo de pessoas.

*/

/* 
# INDICE
+ DEFINICOES ACESSORIAS
  + alerta()
  + instrucoes()
  + definicao de no*
  + definicao de dados
+ FUNCOES DE LISTA
  + nova_lista()
  + adicionar_a_lista()
  + escrever_lista()
  + presente_na_lista()
+ FUNCOES DE GRAFO
  + novo_grafo()
  + nova_conexao()
  + mostrar_conexoes()
+ FUNCOES DE LIGACAO
  + identificar_amigo()
  + leitura_arquivo()
+ FUNCOES DE RANKING
  + preparar_loop()
  + distribuir_influencia()
  + gerar_ranking()
+ FUNCOES PRINCIPAIS
  + main()
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0
#define maybe (-1)

#define inc(A) (A) = (A)->direita
#define clear() system("clear")

void alerta()
{
  puts("!FLAG!");
  return;
}

void instrucoes ()
{
  printf("ARQUIVO NAO ENCONTRADO!\nfaca um arquivo chamado \"amigos.txt\"\ne escreva uma lista de adjacencias como a seguir:\n\n\tjesus: joao, maria, pedro, mateus\n\tpedro: mateus, judas\n\tjudas: joao, maria\n\n");
}

/*
a proxima definicao eh o prototipo que sera compartilhado
no programa por todas as estruturas de dados do programa.

#variaveis
a variavel 'nome' eh a identificao do no*; info, a informacao
contida no no* atual; tipo, qual o tipo de no* (como descrito
a seguir); direita, o proximo item na lista; esquerda, o no*
anterior ou uma informacao adicional

#tipos de no:
+ l - lista (endereco de um noh em um lista)
+ g - grafo (endereco de um noh de um grafo)
+ e - endereco (usado para listas de adjacencia em grafos)
*/
typedef struct no 
{
  void* nome;
  void* info;
  char tipo;
  struct no* direita;
  struct no* esquerda;
} no;

typedef struct {
  int no_amigos;
  float influencia;
} dados;

/*FUNCOES DE LISTA*/
/*esta funcao cria um novo no do tipo lista*/
no* nova_lista ()
{
  no* lista = (no*) malloc(sizeof(no));

  lista->direita = lista->esquerda = NULL;
  lista->nome = lista->info = NULL;
  lista->tipo = 'l';

  return lista;
}

/*esta funcao adiciona um no na lista*/
no* adicionar_a_lista(no* lista, no* amigo)
{
  no* desbravador = lista;

  while (desbravador->direita != NULL)
    desbravador = desbravador->direita;

  desbravador->direita = nova_lista();
  desbravador = desbravador->direita;
  desbravador->info = amigo;

  return lista;
}

/*esta funcao mostra quais pessoas estao na lista*/
void escrever_lista (no* lista_amigos)
{
  no* lista = lista_amigos;

  puts("lista:");
  while (lista != NULL)
  {
    no* amigo = lista->info;
    if (amigo != NULL)
    {
      /*
      printf("\t");
      mostrar_conexoes(amigo);
      printf("\n");
      */
      printf("%s ", amigo->nome, amigo);
    }
    inc(lista);
  }

  fflush(stdout);
}

/*esta funcao checa se um nome esta na lista*/
bool presente_na_lista(char* nome, no* lista)
{
  no* desbravador = lista;
  no* pessoa;
  bool resultado = false;

  if (nome == NULL)
    return false;

  while (desbravador != NULL && resultado == false)
  {
    pessoa = desbravador->info;
    if (pessoa != NULL)
      resultado = (strcmp(nome, pessoa->nome) == 0)? true:false;
    inc(desbravador);
  }

  return resultado;
}

/*FUNCOES DE GRAFO*/
/*esta funcao cria um novo grafo tanto para 
criar uma nova pessoa como para adicionar 
aa lista de adjacencia de uma dada pessoa*/
no* novo_grafo (char* nome, no* pai)
{
  no* grafo = (no*) malloc(sizeof(no));

  grafo->esquerda = grafo->direita = NULL;

  /*teste de paternidade*/
  if (pai != NULL)
  {
    grafo->tipo = 'e';
    grafo->info = pai;
  }
  else
  {
    grafo->tipo = 'g';
    grafo->info = grafo;
  }

  /*nome*/
  if (strlen(nome) == 0)
    return NULL;

  if (nome != NULL)
  {
    int tamanho = strlen(nome);
    grafo->nome = (char*) malloc(sizeof(char)*(tamanho+1));
    strcpy(grafo->nome, nome);
  }

  return grafo;
}

/*esta funcao cria uma conexao uni-direcional
entre duas pessoas. aqui, o grafo_a apontara
para o grafo_b*/
no* nova_conexao (no* grafo_a, no* grafo_b)
{
  no *a = grafo_a, *b = grafo_b;

  if
  (
    (a == NULL || b == NULL) ||
    (a == b)
  )
  {
    /*fprintf(stderr, "es gibt nichts zu add\n");*/
    return NULL;
  }

  while (a->direita != NULL)
  {
    a = a->direita;
    if (a->esquerda == b)
    {
      fprintf(stderr, "es gibt schon eine connection\n");
      return a;
    }
  }

  if (strlen(b->nome) == 0)
  {
    a->direita = NULL;
    return a;
  }

  a->direita = novo_grafo(a->nome, a);
  a = a->direita;
  a->esquerda = b;

  return a;
}

/*esta funcao mostra a quais amigos uma
pessoa esta ligada*/
void mostrar_conexoes(no* pai)
{
  no* vertice = pai;

  printf("%s esta ligado a ", vertice->nome);
  inc(vertice);
  if (vertice == NULL)
    printf("nada ");
  while (vertice != NULL)
  {
    no* amigo = vertice->esquerda;
    printf("%s ", amigo->nome);
    inc(vertice);
  }
}

/*esta funcao procura por uma pessoa na lista
pelo nome e a retorna se ela estiver presente*/
no* trocar_amigo(char* nome, no* lista_amigos)
{
  no* lista = lista_amigos;
  no* amigo = lista->info;
  bool resultado = false;

  while (resultado == false && lista != NULL)
  {
    if (lista->info != NULL)
    {
      amigo = lista->info;
      /*printf("@%s x @%s? => ", amigo->nome, nome);*/
      resultado = (strcmp(amigo->nome, nome) == 0)? true:false;
    }
    inc(lista);
  }

  if (lista == NULL && resultado == false)
    return NULL; 

  /*printf("@%s!", amigo->nome);*/
  return amigo;
}

/*FUNCOES DE LIGACAO*/

/*esta funcao identifica um amigo de uma 
dada pessoa no arquivo e a adiciona na lista
de amigos desta pessoa*/
char identificar_amigos(no* lista, no* pessoa, FILE* fp)
{
  no* lista_amigos = lista;
  no* amigo;
  char* nome;
  char controle = ' ';
  int tamanho = 0;

  while (controle != ',' && controle != '\n')
  {
    nome = (char*) malloc(sizeof(char));
    do 
    {
      ++tamanho;
      fscanf(fp, "%c", &nome[tamanho-1]);
      if (nome[tamanho-1] == ' ')
        --tamanho;
      nome = (char*) realloc(nome, (tamanho+1)*sizeof(char));
    } 
    while (nome[tamanho-1] != ',' && nome[tamanho-1] != '\n');

    controle = nome[tamanho-1];
    nome[tamanho-1] = '\0';

    printf("\t"); puts(nome);

    if (!presente_na_lista(nome, lista_amigos))
    {
      amigo = novo_grafo(nome, NULL);
      adicionar_a_lista(lista_amigos, amigo);
    }
    else
    {
      amigo = trocar_amigo(nome, lista_amigos);
    }
    nova_conexao(pessoa, amigo);
  }

  return controle;
}

/*esta funcao le o arquivo base e gera 
uma lista de nos com as relacoes*/
no* leitura_arquivo (FILE* fp, no* lista_amigos)
{
  char* nome;
  int tamanho = 0;
  no* amigo = NULL;

  /*criacao da lista de amigos*/
  if (lista_amigos == NULL)
    lista_amigos = nova_lista();

  printf("\n");
  /*identificacao da pessoa*/
  nome = (char*) malloc(sizeof(char));
  do 
  {
    ++tamanho;
    fscanf(fp, "%c", &nome[tamanho-1]);
    nome = (char*) realloc(nome, (tamanho+1)*sizeof(char));
  } 
  while (nome[tamanho-1] != ':');
  nome[tamanho-1] = '\0';

  if (strlen(nome) == 0)
    return lista_amigos;

  printf("%s:\n", nome);

  if (!presente_na_lista(nome, lista_amigos))
  {
    amigo = novo_grafo(nome, NULL);
    lista_amigos = adicionar_a_lista(lista_amigos, amigo);
  }
  else
  {
    amigo = trocar_amigo(nome, lista_amigos);
  }

  /*identificacao dos amigos*/
  do { 
    nome[0] = identificar_amigos(lista_amigos, amigo, fp);      
  } while (nome[0] != '\n');

  mostrar_conexoes(amigo);
  return lista_amigos;
}

/*FUNCOES DE RANKING*/

/*preparacao do loop*/
/*esta funcao descobre quantos amigos uma pessoa tem*/
int descobrir_no_amigos(no* lista_amigos)
{
  int no_amigos = -1;
  no* pessoa = lista_amigos;

  while (pessoa != NULL)
  {
    inc(pessoa);
    no_amigos++;
  }

  return no_amigos;
}

no* preparar_loop (no* lista_amigos)
{
  no* lista = inc(lista_amigos);  
  no* pessoa;
  dados* info;

  printf("\n\n");

  /*criacao dos nos*/
  while (lista->direita != NULL)
  {
    /*alocacao de memoria*/
    pessoa = lista->info;
    printf("%s: ", pessoa->nome); fflush(stdout);
    pessoa->info = (dados*) malloc(sizeof(dados));    

    /*atribuicao de valores*/
    info = pessoa->info;
    info->influencia = 1.0;
    info->no_amigos = descobrir_no_amigos(pessoa);
    printf("%.2f&%d\n", info->influencia, info->no_amigos);

    inc(lista);
  }

  return lista_amigos;
}

/*distribuicao de influencia*/
/*esta funcao anda pelo grafo somando os valores de influencia*/
void influenciar (no* grafo)
{
  no* pessoa = grafo;
  no* amigo;
  dados* info;
  float influencia;

  if (pessoa == NULL) return;

  /*descoberta de influencia*/
  info = pessoa->info;
  if (info != NULL)
    influencia = 0.85 / info->no_amigos;

  /*distribuicao de influencia*/
  inc(pessoa);
  while (pessoa != NULL)
  { 
    amigo = pessoa->esquerda;
    printf("%s... ", amigo->nome);
    info = amigo->info;
    info->influencia += influencia;      

    inc(pessoa);
  }

  fflush(stdout);
  return;
}

void distribuir_influencia(no* lista_amigos)
{
  no* lista = lista_amigos;
  no* amigo;

  while(lista->direita != NULL)
  {
    amigo = lista->info;
    printf("%s: ", amigo->nome);
    influenciar(amigo);
    inc(lista);
  }

  return;
}

/*geracao do ranking*/
no* ordenar_lista(no* lista_amigos)
{
  return lista_amigos;
}

void gerar_ranking(no* lista_amigos)
{
  no* lista = lista_amigos;
  no* lista_ordenada;
  no* pessoa;
  dados* info;

  /*resultado final do evento*/
  puts("resultado final:");
  while (lista != NULL)
  {
    pessoa = lista->info;
    if (pessoa != NULL)
    {
      info = pessoa->info;
      printf("\t%s: %.2f\n", pessoa->nome, info->influencia, info->no_amigos);
    }
    inc(lista);
  }

  /*ordenacao da lista*/
  lista_ordenada = ordenar_lista(lista_amigos);
  /*escrita da lista*/
  puts("ranking final:");
  while (lista != NULL)
  {

  }

  return;
}

/*FUNCOES PRINCIPAIS*/

int main (int argc, char* argv[])
{
  no* lista_amigos = NULL;
  FILE* fp = fopen("amigos.txt", "r");

  if (fp == NULL)
  {
    instrucoes();
    exit(1);
  }

  /*identificacao dos participantes*/
  while (!feof(fp))
    lista_amigos = leitura_arquivo(fp, lista_amigos);
  escrever_lista(lista_amigos);

  /*aplicacao do algoritmo*/
  lista_amigos = preparar_loop(lista_amigos);
  if (lista_amigos == NULL) exit(2);
  distribuir_influencia(lista_amigos);
  gerar_ranking(lista_amigos);

  return 0;
}
