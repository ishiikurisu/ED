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

bool dentro (arvore* raiz)
{ //verifica se está dentro da fronteira
  return 
  (
      root->pos[0] >= 0 &&
      root->pos[1] >= 0 &&
      root->pos[0] < tamanho &&
      root->pos[1] < tamanho
  )
}

no* caminhar (no* tabuleiro, int vezes)
{
  no* tab = tabuleiro;
  int i;

  if (vezes > 0)
    for (i = 0; i < vezes; i++)
      tab = tab->prox;
  else
    for (i = 0; i < vezes; i++)
      tab = tab->ant;

  return tab;
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

arvore* popularArvore (arvore *raiz)
{
  arvore* root;

  root = raiz->filho = plantarArvore(raiz);

  root->pos[0] = raiz->pos[0] - 1;
  root->pos[1] = raiz->pos[1] - 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0] - 1;
  root->pos[1] = raiz->pos[1];
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0] - 1;
  root->pos[1] = raiz->pos[1] + 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0];
  root->pos[1] = raiz->pos[1] - 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0];
  root->pos[1] = raiz->pos[1] + 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0] + 1;
  root->pos[1] = raiz->pos[1] - 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0] + 1;
  root->pos[1] = raiz->pos[1];
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  root->pos[0] = raiz->pos[0] + 1;
  root->pos[1] = raiz->pos[1] + 1;
  root->irmao = plantarArvore(raiz);
  root = root->irmao;
  root->vez = raiz->vez + 1;

  return raiz;
}

arvore* percorrerArvore (arvore* raiz, no* tabuleiro, int limite)
{
  no* tab = tabuleiro;
  arvore* root;

  raiz = popularArvore(raiz, tab);
  root = raiz->filho;
  
  
  if 
  (
    root->vez != limite &&
    dentro(root);
  )
  {
    //ainda não chegou ao limite
    root = popularArvore(root, tab);
  }
  else if (root->pai->irmao != NULL)
  { /*!
      DEVEMOS MUDAR ISTO AQUI
      ELE DEVE IR PARA O PROXIMO IRMAO,
      NÃO PARA O PRIMEIRO IRMÃO
    !*/
    root = root->pai->irmao;
    root = popularArvore(root, tab);
  }


  return root;
}

void jogar (no* tabuleiro)
{
  no* prioridade = definirPrioridades(tabuleiro);
  arvore* backtrack = plantarArvore(NULL);
  arvore* root = backtrack;
  no* pdd = prioridade->prox;
  no* tab = tabuleiro;
  no* objetivo;
  int limite;

  /*
  if (prioridade->endereco->info != 1)
    do the first move;
  */
  tab = pdd->endereco;
  pdd = pdd->prox;
  limite = pdd->info - tab->info;
  root->pos[0] = tab->pos[0];
  root->pos[1] = tab->pos[1];
  root->vez = 0;

  while 
  (
    pdd != NULL &&
    root != NULL
  )
  {
    root = percorrerArvore(backtrack, tab, limite);
    if 
    (
      root->pos[0] == pdd->pos[0] &&
      root->pos[1] == pdd->pos[1]
    )
      pdd = pdd->prox;
    else
      root = root->pai->irmao;      
  }

  /*
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

