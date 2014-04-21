void mostrar(no* tabuleiro)
{
  no* tab = tabuleiro;

  while (tab != NULL)
  {
    if (tab->pos[1] == 0)
    {
      puts(" ");
    }
    printf("%d:%d:%d\t", tab->info, tab->pos[0], tab->pos[1]);

    tab = tab->prox;
  }

  puts("\n"); 
}

no* ordenarPrioridade (no* prioridade)
{
  no* pdd = prioridade->prox;
  int menor = 666;

  while (pdd != NULL)
  {
    puts("FLAG");
    if
    (
      (pdd->info < menor) &&
      (pdd->info > 0) &&
      (prioridade->prox != pdd)
    )
    {
      menor = pdd->info;

      pdd->ant->prox = pdd->prox;
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

no* definirPrioridades (no* tabuleiro) 
{
  no* tab = tabuleiro->prox;
  no* prioridade = (no*) malloc(sizeof(no));
  no* pdd = prioridade;
  
  pdd->info = 0;
  while (tab != NULL)
  {
    if (tab->estado < 0)
    {
      pdd->endereco = tab;
      pdd->prox = (no*) malloc(sizeof(no));
      pdd->prox->prox = NULL;
      pdd->prox->ant = pdd;
      pdd->prox->info = tab->info;
      pdd = pdd->prox;
    }

    tab = tab->prox;
  }
  
  mostrar(prioridade);
  prioridade = ordenarPrioridade(prioridade);
  mostrar(prioridade);

  return prioridade;
}

void jogar (no* tabuleiro)
{
  arvore* backtrack = plantarArvore();
  no* prioridade, *pdd;
  no* tab = tabuleiro;
  no* objetivo;

  pdd = prioridade = definirPrioridades(tabuleiro);

  /*
  if (prioridade->endereco->info != 1)
    do the first move;

  while (things are fucked up)
  {
    priority = moverFila(prioridade);
    while (not good or not bad)
    {
      follow one direction;
      if (failure)
      {
        back to father;
        change direction;
      }
      else
      {
        moveOn? = check step number;
      }
    }
    if (back to root)
      declare failure;
  }

  do the last move
  */

  return;
}
