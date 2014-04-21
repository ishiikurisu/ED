No* retiraDaLista (No *lista) 
{ 
  No *aux;
  No *ant;
  No *prox;

  aux = lista;
  prox = aux -> proximo;
  ant = aux -> anterior;

  if(aux -> proximo == NULL)
  {  
    lista = aux -> anterior;
    if(ant != NULL)
      ant -> proximo = aux -> proximo;
  }
  else if (aux -> anterior == NULL)
  {  
    lista = aux -> proximo;
    if(ant != NULL)
      prox -> anterior = aux -> anterior;    
  }
  else
  {
    puts("FLAG3");
    ant -> proximo = prox;
    prox -> anterior = ant;
    lista = aux -> proximo;
  }
  
  return aux;
}

Fila* inserePista (No* voo, Fila* pista) 
{
  if (pista->inicio == pista->fim)
  { //pista vazia
    pista->inicio = pista->fim = voo;
    voo->proximo = voo->anterior = NULL;
  }
  else
  { //pista nao-vazia
    voo->proximo = pista->fim;
    voo->anterior = NULL;
    pista->fim->anterior = voo;
    pista->fim = voo;
  }

  return pista;
}

void insPis (No* voo, Fila* pista)
{
  No* aux = voo->anterior;

  voo = retiraDaLista(voo);

  if (pista->inicio == pista->fim)
  {
    pista->fim->anterior = voo;
    voo->proximo = pista->fim;
    voo->anterior = NULL;
    pista->fim = voo;
  }
  else
  {
    pista->inicio = pista->fim = voo;
    pista->fim->anterior = NULL;
    pista->fim->proximo = pista->inicio;
  }

  return aux;
}

void preenchePistas (No* voos, Fila* pista1, Fila* pista2, Fila* pista3)
{
  int comb = 0, prioridade, decflag, flag;
  No* voo;
  Fila* pista[] = {pista1, pista2, pista3};

  while (voos->anterior != NULL) 
  {
    printf("COMB = %d\n", comb);
    decflag = 0;
    prioridade = 2;
    for (voo = voos; voo != NULL; voo = voo->anterior) 
    {
      puts("FOR");
      flag = 0;
      if ((voo -> comb == comb) && (prioridade - decflag > 0))
      { /*CASO COMUM*/
        if (voo -> estado == 'D' && decflag == 0)
        {
          pista1 = inserePista(voo, pista1);
          //voo = pista1->fim;
          decflag++;
        }
        else 
        {
          pista[prioridade] = inserePista(voo, pista[prioridade]);
          //voo = pista[prioridade]->fim;
          prioridade--;
        }
        flag++;
      }
      else if ((voo -> comb == comb) && (prioridade - decflag < 0))
      { /*CASO EMERGENCIAL*/
        printf("\n\n/!\\CAIU UM AVIAO/!\\\n\n");
        retiraDaLista(voo);
        flag++;
      }

      if (flag) mostra(voos);

    }
    comb++;
  }
}

void liberaPistas (Fila* pista1, Fila* pista2, Fila* pista3)
{
  Fila* pista[] = {pista1, pista2, pista3};
  No* temp;
  int i;

  for (i = 0; i < 3; i++)
  {
    temp = pista[i]->inicio;
    printf("PISTA %d:\n", i+1);
    while (temp != NULL)
    {
      printf("%s\n", temp->nome);
      temp = temp->anterior;
    }
    printf("===\n");
  }
}

/*if (pista[prioridade]->fim != NULL &&
          pista[prioridade]->fim->estado == 'D')
            inserePista(pista[prioridade]->fim, &pista1);*/