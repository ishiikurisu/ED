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

bool dentro (arvore* root)
{ //verifica se está dentro da fronteira
  return 
  (
      root->pos[0] >= 0 &&
      root->pos[1] >= 0 &&
      root->pos[0] < tamanho &&
      root->pos[1] < tamanho
  );
}

no* caminhar (no* tabuleiro, int passos)
{
  no* tab = tabuleiro;
  int i;

  if (passos > 0)
    for (i = 0; i < passos; i++)
      tab = tab->prox;
  else
  {
    passos = -passos;
    for (i = 0; i < passos; i++)
      tab = tab->ant;
  }

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
  arvore* root = raiz;
  bool flag = false; //tem filhos?

  if 
  (
    raiz->pos[0] > 0 &&
    raiz->pos[1] > 0
  )  
  {

    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] - 1;
    root->pos[1] = raiz->pos[1] - 1;
    root->vez = raiz->vez + 1;
  }  

  if
  (
    raiz->pos[1] > 0
  )
  {
    if (!flag)
    {
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] - 1;
    root->pos[1] = raiz->pos[1];
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho &&
    raiz->pos[1] > 0
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] - 1;
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] > 0
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0];
    root->pos[1] = raiz->pos[1] - 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0];
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] > 0 &&
    raiz->pos[1] < tamanho
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] + 1;
    root->pos[1] = raiz->pos[1] - 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[1] < tamanho
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] + 1;
    root->pos[1] = raiz->pos[1];
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho &&
    raiz->pos[1] < tamanho
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] + 1;
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  root->irmao = NULL;

  return raiz;
}

no* mover (no* tabuleiro, arvore* raiz)
{
  no* tab = tabuleiro;
  arvore* root = raiz;
  int passos;

  passos = (root->pos[1] - tab->pos[1]) * tamanho + 
  (root->pos[0] - tab->pos[0]);
  tab = caminhar(tab, passos);

  if (tab->estado == 0)
  {
    tab->info = root->vez;
    tab->estado = 1;
  }

  return tab; 
}

/*
void limpar(no* tabuleiro, arvore* raiz)
{
  
}
*/

arvore* percorrerArvore (arvore* raiz, no* tabuleiro, int limite)
{
  no* tab = tabuleiro;
  arvore* root;

  if 
  (
    root != NULL &&
    root->vez <= limite
  )
  {
    //ainda não chegou ao limite
    raiz = popularArvore(raiz);
    root = raiz->filho;
    tab = mover(tab, root);
    root = percorrerArvore(root, tab, limite);
  }

  return root;
}

bool jogar (no* tabuleiro)
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
  root->vez = 1;

  while 
  (
    pdd != NULL &&
    root != NULL
  )
  {
    root = percorrerArvore(root, tab, limite);
    if 
    (
      root->pos[0] == pdd->pos[0] &&
      root->pos[1] == pdd->pos[1] &&
      root->vez == pdd->info;
    )
    {
      tab = pdd->endereco;
      pdd = pdd->prox;
    }
    else if (root->irmao != NULL)
      root = root->irmao;
    else if (root->pai->irmao != NULL)
      root = root->pai->irmao;      
    else if (root->pai->pai != NULL)
      //root = root->pai->pai;
      root == NULL;
  }

  if (root == NULL)
    return false;
  else
    return true;
}
