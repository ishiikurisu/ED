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
