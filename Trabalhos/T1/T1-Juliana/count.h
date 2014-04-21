//Definição de uma lista
struct lista {
  char* nome;
  int ocor; //ocorrencia
  struct lista* prox;
};
typedef struct lista List;

/******************
Funções acessórias
******************/

void abrir_arquivo (FILE* fp, int indice) {
  char fnome[20];

  printf("Digite o nome do %do arquivo\n", indice+1);
  gets(fnome, 20); 
  fp = fopen(fnome, "r");
}

int alfanumerico (char letra) {
  if (letra >= 48 && letra <= 90 || letra >= 97 && letra <= 122)
    return 1;
  else
    return 0;
}
int maiusculo (char letra) {
  if (letra >= 65 && letra <= 90)
    return 1;
  else 
    return 0;
}

void trocarTamanho (char* letra) {
  int conv = 97 - 65; //fator de conversão

  if (letra >= 97)
    letra -= conv;
  else
    letra += conv;
}
void novaPalavra (List* palavra, char* lido) {
  List* sequencia = palavra;

  while (sequencia->prox != NULL)
    sequencia = sequencia->prox;
  sequencia->prox = (List*) malloc(sizeof(List));
  sequencia = sequencia->prox;
  sequencia->nome = lido;
  sequencia->ocor = 0;
}

/******************
Funções em contar()
******************/

int descobrirTamanho (FILE* fp) {
  FILE* checkpoint = fp; //NAO ENTENDI
  int tamanho = 0;
  char letra;

  do {
    fscanf(checkpoint, "%c", &letra);
    tamanho++;
  } while (letra != 32); /*esse tamanho está pegando também algum sinal de pontuacao*/

  return tamanho;
}

char* salvar (int tamanho, char* lido, FILE* fp) { /*não seria melhor fazer o teste do tamanho logo aqui?*/
  int i;
  char* lido;

  char* lido = (char*) malloc(tamanho*sizeof(char));
  for (i = 0; i <= tamanho; i++)
    fscanf(fp, "%c", lido[i]);
  lido[i] = '\0';

  return lido;
}

void tratar (char* lido) { //refina a palavra
  int i = 0;

  while (lido[i] != '\0')
    if (maiusculo(lido[i])) trocarTamanho(lido[i]);
}

void adicionar (char* lido, List* pontuacao, List* palavra) {
  int i = 0;
  List* sequencia = palavra; //TROCAR PALAVRA POR SEQUENCIA 

  do {
    if (lido[i] == palavra->nome[i])
      i++;
    else {
      palavra = palavra->prox;
      i = 0;
    }
  } while ((lido[i] != '\0' && palavra->nome[i] != '\0') || (palavra != NULL));

  if (lido[i] == '\0')
    palavra->ocor++;
  else
    novaPalavra(palavra, lido);
  free(lido);
}
