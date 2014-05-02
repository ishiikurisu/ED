/*
  else if 
  (
    root->pai->irmao != NULL
  )
  { 
    //acabou a lista de filhos
    //CRIAR FUNÇÃO PARA LIMPAR TABULEIRO
    root = root->pai->irmao;
    tab = mover(tab, root);
    root = percorrerArvore(root);
  }
  else if (root->vez != limite)
  {
    //CRIAR FUNÇÃO PARA LIMPAR TABULEIRO
    root = root->pai->pai; 
  }
  */

397@jogar.h if (root->pai->irmao != NULL)

void escreverArvore (arvore* raiz)
{
  printf
  (
    "%d:%p:%p:%p\t%d:%d\n",
    raiz->vez, raiz, raiz->pai, raiz->irmao, 
    raiz->pos[1], raiz->pos[0]
  );
  if (raiz->filho != NULL)
    escreverArvore(raiz->filho, mode);

  if (raiz->irmao != NULL)
  escreverArvore(raiz->irmao);

  return;
}

void escreverArvore (arvore* raiz)
{
  printf ("%d:%d:%d ", raiz->vez, raiz->pos[1], raiz->pos[0]);
  if (raiz->filho != NULL)
    {
      printf("< ");
      escreverArvore(raiz->filho, mode);
      printf("> ");
    }

   if (raiz->irmao != NULL)
  escreverArvore(raiz->irmao);

  return;
}

/*
    while (tab->estado != 0 && root != NULL)
    {
      root = root->irmao;
      tab = mover(tab, root); 
    }
    */

    /*
    else if (temp->pai != NULL)
    {
      puts("father");
      showTree(temp);
      root = limpar(tab, temp->pai);
      temp = root = root->irmao;
    }
    else
    {
      puts("exception");
      puts("exception");
      do {root = temp->pai;}
      while (root->pai->irmao == NULL && root->pai != NULL);
      if (root->pai == NULL)
        root = NULL;
      #btw we 697 lines by now
      pass();
    }    
      */

