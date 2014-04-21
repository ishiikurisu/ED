typedef struct lista List;

/*******************
funções de ordenação
*******************/
void ordernarPalavras(List* lst) {
  List* head = lst->prox;
  List *sequencia, *temp;
  int flag = 1;

  while (flag) {
    flag = 0;
    sequencia = head;
    /*primeira iteração*/
    if (sequencia->ocor < (sequencia->prox)->ocor) {
      head = sequencia->prox;
      sequencia->prox = sequencia;
      sequencia = head;
      lst->prox = head;
      flag++;
    }
    sequencia = sequencia->prox;
    /*iterações seguintes*/
    while (sequencia->prox != NULL) {
      if (sequencia->ocor < (sequencia->prox)->ocor) {
        temp = sequencia->prox;
        sequencia->prox = sequencia;
        sequencia = temp;
        flag++;
      }
      sequencia = sequencia->prox;
    }
  }
}

float modulo2 (List* palavra) {
  List* sequencia = palavra;
  float soma = 0.0;

  while (sequencia != NULL) {
    soma += pow(palavra->ocor ,2);
  }
  /*soma*/

  return soma;
}

float prodInt (List** listas) {
  List *w1 = listas[0], *w2 = listas[1];
  float soma = 0.0; int i = 0;

  while (w1 != NULL) {
    w2 = listas[1];
    while ((w1->nome[i] != '\0' && w2->nome[i] != '\0') || w2 != NULL) {
      if (w1->nome[i] == w2->nome[i])
        i++;
      else {
        w2 = w2->prox;
        i = 0;
      }
      if (w1->nome[i] == '\0')
        soma += (w1->ocor)*(w2->ocor);
      w1 = w1->prox;
    }
  }

  return soma;
}

/*******************
funções de resultado
*******************/
void mostrarResultado(List** palavra, List** pontuacao) {
  float soma = 0.0, mod = 0.0;
  int i;

  for (i = 0; i < 2; i++)
    mod = modulo2(palavra[i]) + modulo2(pontuacao[i]);
  mod = pow(mod, 0.5);

  soma += prodInt(palavra);
  soma += prodInt(pontuacao);
  soma = acos(soma/mod);

  if (soma > (3.14 / 4))
    printf("EH PLAGIO");
  else
    printf("NUM EH PLAGIO");
  printf("\n\n");
}


int novamente () {
  char result;

  printf("DESEJA TENTAR NOVAMENTE? ");
  scanf("%c", &result);

  return ('s' == result || 'S' == result)? 1: 0;
}
