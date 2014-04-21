git void mostrar(no* tabuleiro)
{
  no* tab = tabuleiro;

  while (tab != NULL)
  {
    if (tab->pos[1] == 0)
    {
      puts("\n");
    }
    printf("%d:%d:%d\t", tab->info,tab->pos[0], tab->pos[1]);
    tab = tab->prox;
  }

  puts("\n"); 
}

no* definirPrioridades (no* tabuleiro) 
{
  no* prioridade = (no*) malloc(sizeof(no));
  no* pdd = prioridade;
  no* tab = tabuleiro->prox;
  
  while (tab != NULL)
  {
    if (tab->estado < 0)
    {
      pdd->endereco = tab;
      pdd->prox = (no*) malloc(sizeof(no));
      pdd->prox->ant = pdd;
      pdd = pdd->prox;
    }

    tab = tab->prox;
  }
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

  do the first move

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
