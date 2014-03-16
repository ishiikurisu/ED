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

void abrir (FILE* fp, int indice) {
  sprintf(char fnome[], "file%d.txt", indice+1);
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
void addFreq (List* palavra, char letra) {
  List* sequencia = palavra;

  while (sequencia->prox != NULL)
    sequencia = sequencia->prox;
  if (sequencia->prox == NULL)
    novaPalavra(palavra, &letra);
  else
    sequencia->ocor++;
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
  FILE* checkpoint = fp;
  int tamanho = 0;
  char letra;

  do {
    fscanf(checkpoint, "%c", &letra);
    tamanho++;
  } while (alfanumerico(letra));

  return tamanho;
}

void salvar (int tamanho, char* lido, FILE* fp) {
  int i;

  char* lido = (char*) malloc(tamanho*sizeof(char));
  for (i = 0; i <= tamanho; i++)
    fscanf(fp, "%c", lido[i]);
  //adicionar pontuação
  lido[i] = '\0';
}

void tratar (char* lido) { //refina a palavra
  int i = 0;

  while (lido[i] != '\0')
    if (maiusculo(lido[i])) trocarTamanho(lido[i]);
}

void adicionar (char* lido, List* palavra) {
  int i;

  while (lido[i] != '\0' and palavra->nome[i] != '\0' \
  or palavra != NULL) {
    if (lido[i] == palavra->nome[i])
      i++;
    else {
      palavra = palavra->prox;
      i = 0;
    }
  }

  if (lido[i] == '\0')
    palavra->ocor++;
  else
    novaPalavra(palavra, lido);
}
