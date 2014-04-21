no* ordenarPrioridade (no* prioridade)
{
  no* pdd = prioridade->prox;
  int menor = 666;

  while (pdd != NULL)
  {
    if
    (
      (pdd->info < menor) &&
      (pdd->info > 0) /*&&
      (prioridade->prox != pdd)*/
    )
    {
      printf("-%d", pdd->info);
      menor = pdd->info;

      pdd->ant->prox = pdd->prox;
      if (pdd->prox != NULL)
        pdd->prox->ant = pdd->ant;
      pdd->prox = prioridade->prox;
      pdd->ant = prioridade;
      prioridade->prox = pdd;
    }

    pdd = pdd->prox;
  }

  puts(" ");
  return prioridade;
}
