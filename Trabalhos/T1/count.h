/*Definição de uma lista*/
struct lista {
  char* nome;
  int ocor; /*ocorrencia*/
  struct lista* prox;
};
typedef struct lista List;

/******************
Funções acessórias
******************/
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

int alfanumerico (char letra) {
  if ((letra >= 48 && letra <= 90) || (letra >= 97 && letra <= 122))
    return 1;
  else
    return 0;
}

void novaPalavra (List* lst, int tamanho, List* tmp) {
  List* sequencia = lst;
  List* temp = tmp;
  int i = 0;

  while (sequencia->prox != NULL)
    sequencia = sequencia->prox;
  sequencia->prox = (List*) malloc(sizeof(List));
  sequencia = sequencia->prox;
  sequencia->prox = NULL;
  sequencia->ocor = 0;
  sequencia->nome = (char*) malloc((tamanho+1)*sizeof(tamanho));
  for (i = 0; i < tamanho; i++)
    sequencia->nome[i] = temp->nome[0];
  sequencia->nome[i] = '\0';
  
}

/******************
Funções em contar()
******************/
int salvar (FILE* fp, List* tmp) {
  int tamanho = 0;
  char letra;
  List* temp = tmp;

  do {
    tamanho++;
    temp->nome = (char*) malloc(sizeof(char));
    temp->nome[0] = letra;
    temp->prox = (List*) malloc(sizeof(List));
    temp = temp->prox;
  } while (letra != 32);

  return tamanho;
}

void adicionar (List* tmp, int tamanho, List* palavra, List* pontuacao) {
  int i = 0; char addPunct[2];
  List* sequencia;
  List* temp = tmp;

  /*add palavra*/
  sequencia = palavra;
  while ((temp->nome[0] != '\0' && sequencia->nome[i] != '\0') || sequencia->prox != NULL) {
    /*ELE NÃO PODE ACESSAR sequencia->nome[i] NA PRIMEIRA VEZ
    COMO FAZ???*/
    if (temp->nome[0] == sequencia->nome[i]) {
      i++;
      temp = temp->prox;
    } else {
      temp = tmp;
      sequencia = sequencia->prox;
      i = 0;
    }
  }
  if (temp->nome[0] == '\0' && sequencia->nome[i] == '\0')
    sequencia->ocor++;
  else
    novaPalavra(palavra, tamanho, tmp);

  /*add pontuacao*/
  sequencia = pontuacao->prox;
  temp = tmp;
  while (alfanumerico(temp->nome[0]) || temp->prox != NULL)
    temp = temp->prox;
  if (alfanumerico(temp->nome[0]) == 0) {
    while (temp->nome[0] != sequencia->nome[0] && sequencia != NULL)
      sequencia = sequencia->prox;
    if (sequencia->nome[0] == temp->nome[0])
      sequencia->ocor++;
  }
  if (sequencia == NULL)
    novaPalavra(pontuacao, 1, tmp);
}
