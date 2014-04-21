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
  char fnome[20];

  printf("Digite o nome do %do arquivo\n", indice+1);
  gets(fnome);
  fp = fopen(fnome, "r");
}

int alfanumerico (char letra) {
  if (letra >= 48 && letra <= 90 || letra >= 97 && letra <= 122)
    return 1;
  else
    return 0;
}
/*int maiusculo (char letra) {
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
} FUNÇÃO INUTIL
void trocarTamanho (char* letra) {
  int conv = 97 - 65; //fator de conversão

  if (letra >= 97)
    letra -= conv;
  else
    letra += conv;
}
*/
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
  } while (letra != 32);

  return tamanho;
}

char salvar (int tamanho, FILE* arquivo) {
  int i; FILE* fp = arquivo;
  char* lido;

  char* lido = (char*) malloc(tamanho*sizeof(char));
  for (i = 0; i <= tamanho; i++)
    fscanf(fp, "%c", lido[i]);
  lido[i] = '\0';

  return lido;
}

/*
void tratar (char* lido) { //refina a palavra
  int i = 0;

  while (lido[i] != '\0')
    if (maiusculo(lido[i])) trocarTamanho(lido[i]);
}*/

void adicionar (char* lido, List* palavra, List* pontuacao) {
  int i, pos = strlen(lido) - 1; char[2] addPunct;
  List* sequencia = pontucao;

  //add pontuacao
  if (alfanumerico(lido[pos]) == 0) {
    while (sequencia != NULL) {
      if (lido[pos] == sequencia->nome[0])
        sequenia->ocor++;
      break;
      else
        sequencia = sequencia->prox;
    }
    if (punct == NULL) {
      addPunct[0] = lido[pos];
      addPunct[1] = '\0';
      novaPalavra(pontuacao, &addPunct);
    }
  }
  //add palavra
  sequencia = palavra;
  while (lido[i] != '\0' && sequencia->nome[i] != '\0'
  || sequencia != NULL) {
    if (lido[i] == sequencia->nome[i])
      i++;
    else {
      sequencia = sequencia->prox;
      i = 0;
    }
  }
  if (lido[i] == '\0')
    sequencia->ocor++;
  else
    novaPalavra(palavra, lido);
}
