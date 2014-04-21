FILE* fp;

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
    if(prox != NULL)
      prox -> anterior = aux -> anterior;    
  }
  else
  {
    ant -> proximo = prox;
    prox -> anterior = ant;
    lista = aux -> proximo;
  }
  
  return aux;
}

No* inserePista (No* voo, Fila** pista)
{
  No* aux = voo->anterior;

  voo = retiraDaLista(voo);

  if ((*pista)->inicio != (*pista)->fim)
  { /*pista nao-vazia*/
    if ((*pista)->inicio->anterior == NULL)
    { /*pista com um elemento*/
      fprintf(fp, "1o voo\n");
      (*pista)->inicio->anterior = (*pista)->fim = voo;
      (*pista)->fim->proximo = (*pista)->inicio;
    }
    else
    { /*pista com mais de um elemento*/
      fprintf(fp, "+1 voo\n");
      (*pista)->fim->anterior = voo;
      voo->proximo = (*pista)->fim;
      (*pista)->fim = voo;
    }
    (*pista)->fim->anterior = NULL;
  }

  else
  { /*pista vazia*/
    fprintf(fp, "+1 pista\n");
    (*pista)->inicio = voo;
    (*pista)->inicio->anterior = (*pista)->fim = NULL;
  }

  fprintf(fp, "#Pista parcial\n");
  fmostra((*pista)->inicio, fp);
  fprintf(fp, "#Fim da pista parcial\n");

  return aux;
}

void preenchePistas (No* voos, Fila* pista1, Fila* pista2, Fila* pista3)
{
  int comb = 0;
  int prioridade;
  int decflag;
  No* voo;
  Fila* pista[] = {pista1, pista2, pista3};

  fp = fopen("log.txt", "w");
  fmostra(voos, fp);
  fprintf(fp, "===\n");

  while (voos->anterior != NULL) 
  {
    fprintf(fp, "#COMB = %d\n", comb);
    decflag = 0;
    prioridade = 2;
    voo = voos;

    while (voo != NULL)
    {
      fprintf(fp, "FOR ");
      fflush(fp);
      if (voo->comb == comb)
      { /*Este voo possui este nivel de combustivel*/

        if (voo->proximo == NULL && ) /*altera o comeco da lista*/
          voos = voos->anterior;

        if (voo->estado == 'D' && !decflag)
        { /*Este aviao deseja decolar e a pista de decolagem
          esta disponivel*/
          fprintf(fp, "dec\n");
          voo = inserePista(voo, &pista1);
          decflag++;
        }
        else if (prioridade >= 0)
        { /*Encontrou um voo mas a pista de decolagem
          nao esta disponivel*/
          fprintf(fp, "at\n");
          voo = inserePista(voo, &pista[prioridade]);
          prioridade--;
        }
        else 
        { /*Situacao de emergencia*/
          fprintf(fp, "FAIL\n");
          puts("FAIL");
          voo = (retiraDaLista(voo))->anterior;
        }


        fprintf(fp, "#Lista nova\n");
        fmostra(voos, fp);
        fprintf(fp, "#Fim da lista nova\n");
      }
      else /*Este voo nao possui este nivel de combustivel*/
        voo = voo->anterior;
    }
    comb++;
  }
  if (voos->estado == 'D')
    inserePista(voos, &pista1);
  else
    inserePista(voos, &pista2);


  fclose(fp);
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

