/*Célula contendo um ponteiro para a palavra, sua quantidade e 
ponteiro para o proximo elemento*/
#define MAX_ARQUIV 2

struct lista
{
  char* palavra;
  unsigned int quantidade;
  struct lista *proximo;
};
typedef struct lista tipo_lista;

typedef struct arquivo Arquivo;
struct arquivo
{
  char* nome_arquivo;
  FILE* ponteiro_arquivo;
  tipo_lista* lista;
};

/*Liberando a lista*/
void libera_lista (tipo_lista *l)
{
  tipo_lista *desbravador = l, *dummy;

  while (desbravador->proximo != NULL)
  {
    dummy = desbravador->proximo;
    free(desbravador->palavra);
    desbravador->palavra = NULL;
    free(desbravador);
    desbravador = dummy;
  }
}

/*Recebe a palavra, procura se existe na lista
(ao mesmo tempo que guarda um ponteiro para a posição em que há variação de quantidades entre palavras diferentes)
(se é igual, incrementa o contador; senão, insere na lista)*/
void inclui_na_lista (char* aux,tipo_lista *l)
{
  tipo_lista *desbravador = l, *maior = l, *anterior, *novo;

  for (;desbravador->proximo->proximo != NULL; desbravador = desbravador->proximo)
  {
    if (maior->quantidade>desbravador->quantidade)
    {
      maior=desbravador;
    }
    if (strcmp(desbravador->palavra,aux) == 0)
    {
      ++desbravador->quantidade;
      anterior->proximo = desbravador->proximo;
      desbravador->proximo = maior->proximo;
      maior->proximo = desbravador;
      return;
    }
    anterior = desbravador;
  }
  if ((novo = (tipo_lista*) malloc(sizeof(tipo_lista))) == NULL)
  {
    printf("Memória insuficiente!");
    return;
  }
  novo->palavra = (char*)malloc(sizeof(aux));
  novo->proximo = desbravador->proximo;
  desbravador->proximo = novo;
  strcpy(novo->palavra,aux);
  novo->quantidade = 1;
}

/*Inicia a lista colocando no início o menor char possível e a maior quantidade possível,
para que todos fiquem depois dele e no fim o maior char possível e a menor quantidade possível,
para que todos fiquem antes dele*/
tipo_lista* inicia_lista (void)
{
  tipo_lista *dummy_de_inicio, *dummy_de_fim;

  if (((dummy_de_inicio = (tipo_lista*) malloc(sizeof(tipo_lista))) == NULL) && ((dummy_de_fim=(tipo_lista*)malloc(sizeof(tipo_lista)))==NULL))
  {
    printf("Memória insuficiente\n");
    return NULL;
  }
  else
  {
    dummy_de_inicio->palavra = (char*)malloc(2*sizeof(char));
    dummy_de_fim->palavra = (char*)malloc(2*sizeof(char));
    dummy_de_inicio->palavra[0] = 0;
    dummy_de_inicio->palavra[1] = '\0';
    dummy_de_inicio->quantidade = -1;
    dummy_de_inicio->proximo = dummy_de_fim;
    dummy_de_fim->palavra[0] = 127;
    dummy_de_fim->palavra[1] = '\0';
    dummy_de_fim->quantidade = 0;
    dummy_de_fim->proximo = NULL;
    return dummy_de_inicio;
  }
}

/*Função para testar se todas as palavras estão corretas na lista*/
void imprime_lista (tipo_lista *l)
{
  tipo_lista *desbravador=l->proximo;

  while (desbravador->proximo->proximo!=NULL)
  {
    printf("%s\t", desbravador->palavra);
    printf("%u\n", desbravador->quantidade);
    desbravador=desbravador->proximo;
  }
}

/*Recebe o arquivo e lê-se um char de cada vez, testanto se é alfanumérico ou pontuação*/
void gera_lista (Arquivo* file)
{
  FILE* fp = file->ponteiro_arquivo;
  tipo_lista* palavr = file->lista;
  char teste;
  char* aux;
  unsigned int i = 1;

  while ((teste=fgetc(fp)) != EOF)
  {
    if (isalnum(teste))
    {
      printf("%c\n", teste);
      if ((aux=(char*)malloc(3*sizeof(char)))==NULL)
      {
        printf("Memória insuficiente\n");
        exit(1);
      }
      aux[0]=teste;
      while
      (
        aux[i] = fgetc(fp) != EOF && 
        isalnum(aux[i])
      )
      {
        printf("Loop\n");
        printf("%c\n", aux[i]);
        if 
        ((aux=(char*)realloc(aux,(3+i)*sizeof(char)))==NULL)
        {
            printf("Memória insuficiente\n");
            exit(1);
        }
        ++i;
      }

      aux[i+1] = '\0';
      printf("%s\n", aux);
      free(aux);
      //inclui_na_lista(aux,palavr);
      i = 1;
    }
  }
  aux = NULL;
}

FILE* abre_arquivo (char* nome_arquivo)
{
  FILE *fp;

  fp = fopen(nome_arquivo,"r");
  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    system("echo '1'");
    exit(1);
  }
  return fp;
}

void le_arquivos (Arquivo* Files,FILE* fp)
{
  char* nome_arquivo_temp = (char*)malloc(sizeof(char));
  int indice_arquivo = 0;

  while 
  (
    (nome_arquivo_temp[0] = fgetc(fp)) != EOF && 
    indice_arquivo < MAX_ARQUIV
  )
  {
    nome_arquivo_temp = (char*)realloc(nome_arquivo_temp,2*sizeof(char));
    int i = 1;
    while((nome_arquivo_temp[i]=fgetc(fp))!=EOF && nome_arquivo_temp[i]!='\n')
    {
      nome_arquivo_temp = (char*)realloc(nome_arquivo_temp,(i+2)*sizeof(char));
      ++i;
    }
    nome_arquivo_temp[i] = '\0';
    Files[indice_arquivo].nome_arquivo = (char*) malloc(sizeof(nome_arquivo_temp));
    strcpy(Files[indice_arquivo].nome_arquivo, nome_arquivo_temp);
    free(nome_arquivo_temp);
    nome_arquivo_temp = (char*)malloc(sizeof(char));
  }
}

void acessa_arquivos (Arquivo* Files)
{
    int i;

    for (i = 0; i < MAX_ARQUIV; ++i)
    {
      Files[i].ponteiro_arquivo = fopen(Files[i].nome_arquivo,"r");
      if (Files[i].ponteiro_arquivo == NULL)
      {
        printf("Erro na abertura do arquivo!\n");
        system("echo '2'");
        exit(2);
      }
      Files[i].lista = inicia_lista();
      gera_lista(&Files[i]);
      imprime_lista(Files[i].lista);
    }
}

unsigned long hash (unsigned char *str)
{
  unsigned long hash = 5381;
  int c;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}

