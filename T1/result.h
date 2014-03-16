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

void mostrarResultado () {}

void resultado () {
  //mostrarResultado();
}

int novamente () {}