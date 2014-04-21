/*******************
funções de ordenação
*******************/
void ordernarPalavras(List* head) {
  List* sequencia, temp;
  int flag = ;

  while (flag) {
    flag = 0;
    sequencia = head;
    //primeira iteração
    if (sequencia->ocor < (sequencia->prox)->ocor) {
      head = sequencia->prox;
      sequencia->prox = sequencia;
      sequencia = head;
      flag++;
    }
    //iterações seguintes
    while (sequencia != NULL) {
      if (sequencia->ocor < (sequencia->prox)->ocor) {
        temp = sequencia->prox;
        sequencia->prox = sequencia;
        sequencia = temp;
        flag++
      }
      sequencia = sequencia->prox;
    }
  }
}

/*void ordernarPalavras (List** head, int nivel, List* cauda) {
  List* sequencia = head; //CHANGE THIS FSCKING FUNCTION
  List* checkpoint = sequencia;

  ordenar(sequencia, nivel);
  while (checkpoint->prox != cauda && \
  checkpoint->nome[nivel+1] != NULL) {
    sequencia = checkpoint;
    if (checkpoint->nome == (checkpoint->prox)->nome) {
      ordernarPalavras(sequencia, nivel+1,\
      descobrirCauda(sequencia, cauda, nivel));
      sequencia = checkpoint;
    }
    else
      checkpoint = checkpoint->prox;
  }
}*/

/*******************
funções de resultado
*******************/

void resultado (Lista** listas) {
  Lista* w1 = lista1, w2 = lista2;
  float soma = 0.0, result;

  while (w1 != NULL) {
    w2 = lista2;
    while (w1->nome[i] != '\0' && w2->nome[i] != '\0' || w2 != NULL) {
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

  result = acos(soma/(modulo(lista1)*modulo(lista2)));

  if (result < (3.14 / 4))
    printf("EH PLAGIO");
  else
    printf("NUM EH PLAGIO");
  printf("\n\n");
}

int novamente () {
  char result;

  printf("DESEJA TENTAR NOVAMENTE? ");
  scanf("%c", &result);

  return ('s' == result || 'S' == result);
}