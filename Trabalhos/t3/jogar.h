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

no* ordPrior (no* prioridade)
{
  bool flag = true;
  no *pdd, *ant, *prox;

  while (flag)
  {
    flag = false;
    pdd = prioridade->prox;
    while (pdd->prox != NULL) {
      puts("FLAG");
      if (pdd->info > pdd->prox->info)
      {
        ant = pdd->ant;
        prox = pdd->prox;
        prox->ant = ant;
        ant->prox = prox;

        pdd->prox = prox->prox;
        prox->prox = pdd;
        pdd->ant = prox;

        flag = true;
      }
      else pdd = pdd->prox;
    }
  }

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
      pdd->prox->pos[0] = tab->pos[0];
      pdd->prox->pos[1] = tab->pos[1];
      pdd->prox->prox = NULL;
      pdd->prox->ant = pdd;
      pdd->prox->info = tab->info;
      pdd = pdd->prox;
    }

    tab = tab->prox;
  }
  
  mostrar(prioridade);
  prioridade = ordPrior(prioridade);
  mostrar(prioridade);

  return prioridade;
}

void jogar (no* tabuleiro)
{
  no* prioridade = definirPrioridades(tabuleiro);
  arvore* backtrack = plantarArvore();
  no* *pdd = prioridade->prox;
  no* tab = tabuleiro;
  no* objetivo;

  if (prioridade->endereco->info != 1)
  /*
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
