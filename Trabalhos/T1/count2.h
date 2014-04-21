struct lista {
  char* nome;
  int ocor; /*ocorrencia*/
  struct lista* prox;
};
typedef struct lista List;

void pass() {return;} 

void comecar (List* sequencia) { /*cria um nó sentinela*/
  sequencia = (List*) malloc (sizeof(List));
  sequencia->nome = NULL;
  sequencia->ocor = 0;
  sequencia->prox = NULL;
}

FILE* abrir (int indice) {
  char fnome[10]; 

  printf("Digite o nome do %do arquivo: ", indice+1);
  scanf("%s", fnome);
  printf("!%s\n", fnome);
  return fopen(fnome, "r");
}

List* descobrirTamanho (FILE* fp, int* tamanho) {
  List *seq, *bkp;
  char letter;

  seq = (List*) malloc(sizeof(List));
  bkp = seq;

  seq->nome = (char*) malloc(sizeof(char));
  seq->prox = NULL;
  fscanf(fp, "%c", &letter);
  seq->nome[0] = letter;
  printf("?%c?", seq->nome[0]);
  (*tamanho)++;

  while (seq->nome[0] != 32) {
    seq->prox = (List*) malloc(sizeof(List));
    seq = seq->prox;
    seq->nome = (char*) malloc(sizeof(char));
    seq->prox = NULL;
    
    fscanf(fp, "%c", &letter);
    seq->nome[0] = letter;
    printf("?%c?", seq->nome[0]);
    (*tamanho)++;
  }

  printf("\n");
  return bkp;
}

void salvar (int tamanho, List* tmp, List* head) {
  List *temp = tmp, *word = head;
  int i;

  while (word->prox != NULL)
    word = word->prox;
  word->prox = (List*) malloc(sizeof(List));
  word = word->prox;
  word->nome = (char*) malloc((tamanho+1)*sizeof(char));
  word->prox = NULL;

  for (i = 0; i < tamanho; i++, temp = temp->prox) {
    word->nome[i] = temp->nome[0];
    printf("!%c!", word->nome[i]);
  }
  word->nome[i] = '\0';
}