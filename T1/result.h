//#include <math.h>
//#include <string.h>

/*******************
funções de ordenação
*******************/

void ordenar (List* seq, int nivel) {}

List* descobrirCauda (List* head, List* caudaAnterior, int nivel) {
  List* sequencia = head;

  while (sequencia->prox != caudaAnterior &&\
  sequencia->prox != caudaAnterior)
    sequencia = sequencia->prox;
  return sequencia;
}

void ordernarPalavras (List** head, int nivel, List* cauda) {
  List* sequencia = head;
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
}

/*******************
funções de resultado
*******************/

float modulo (Lista* l) {
  List* list; float soma = 0;

  while (list != NULL)
    soma += pow((list->ocor), 2);

  return pow(soma, 0.5);
}

float compararStrings (Lista* lista1, Lista* lista2) {
  Lista* w1 = lista1, w2 = lista2, checkpoint = lista2;

  while (w1->nome[0] == w2->nome[0] || w2 != NULL) {
    if (memcmp(w1->nome, w2->nome, strlen(w1->nome))) { //seg fault possibility
      lista2 = w2;
      return (w1->ocor)*(w2->ocor);
    } else
      w2 = w2->prox;
  }
  return 0.0;
}

int resultado (Lista* lista1, Lista* lista2) {
  Lista* w1 = lista1, w2 = lista2;
  float soma = 0;

  while (w1 != NULL) {
    while (w1->nome[0] != w2->nome[0] || w2 != NULL)
      w2 = w2->prox;
    if (w2 != NULL)
      soma += compararStrings(w1, w2);
    w1 = w1->prox;
  }

  return (3.14/4) > acos(soma/(modulo(lista1)*modulo(lista2)));
}

void mostrarResultado (Lista** listas) {
  float result =resultado(listas[0], listas[1]);

  if (result)
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