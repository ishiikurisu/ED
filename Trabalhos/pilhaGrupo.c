#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{/*determina a o tipo pilha*/
  
  int info;/*guarda a informacao*/
  struct pilha *proximo;/*guarda o endereco do proximo*/
  
}Pilha;

void cria(Pilha *top);/*declaracao das funcoes a serem usadas*/
void push(Pilha *top, int inf);
int pop(Pilha *top);
int vazia(Pilha *top);
void mostra(Pilha *top);
void esvazia(Pilha *top);
void opcao();

int main(){
  
  opcao();
  return 0;
}/*termina a main*/

void opcao(){
  
  int opcao;/*controla a acao na pilha*/
  int inf;/*guarda a informacao que sera passada*/
  
  Pilha *cabeca;
  
  cabeca = malloc(sizeof(Pilha));
  
  printf("informe 1 para criar a pilha\n");
  printf("informe 2 para inserir na pilha\n");
  printf("informe 3 para para retirar da pilha\n");
  printf("informe 4 para testar se esta vazia \n");
  printf("informe 5 para mostrar\n");
  printf("informe 6 para esvaziar\n");
  printf("informe 7 para sair\n\n");  
  scanf("%d",&opcao);
  while(opcao != 7){
    
    switch(opcao){
      case 1:
	  cria(cabeca);/*cria a pilha*/
	break;
	
      case 2:	
	  printf("informe o elemento a ser i0nserido \n");
	  scanf("%d",&inf);
	  push(cabeca, inf);
	break;
	
      case 3:
	if(vazia(cabeca) == 0){/*testa se esta vazia*/		  
	  printf("o valor retirado foi %d\n",pop(cabeca));  
	}/*fecha o if*/
	else{
	  printf("pilha vazia\n");
	  
	}/*fecha o if*/
	
	break;
	
      case 4:
	if(vazia(cabeca) == 1){
	  printf("pilha vazia\n");
	}/*fecha o if*/
	else{
	  printf("pilha nao esta vazia\n");
	}/*fecha o else*/
	
	break;
	
      case 5:
	if(vazia(cabeca) == 0){/*testa se esta vazia*/		
	  mostra(cabeca);
	}/*fecha o if*/
	else{
	  printf("pilha vazia\n");
	}/*fecha o if*/
	break;
	
      case 6:
	if(vazia(cabeca) == 0){/*testa se esta vazia*/	
	  esvazia(cabeca);
	}/*fecha o if*/
	else{
	  printf("pilha vazia\n");
	  
	}/*fecha o else*/
	break;
	
      case 7:
	free(cabeca);
	exit(1);
      
    }/*fecha o switch*/
    
  printf("informe 1 para criar a pilha\n");
  printf("informe 2 para inserir na pilha\n");
  printf("informe 3 para para retirar da pilha\n");
  printf("informe 4 para testar se esta vazia \n");
  printf("informe 5 para mostrar\n");
  printf("informe 6 para esvaziar\n");
  printf("informe 7 para sair\n\n");  
  scanf("%d",&opcao);

  }/*fecha o while*/
  
}/*decha a funcao opcao*/

void cria(Pilha *cabeca){
  
    cabeca -> info = 0;
    cabeca -> proximo = NULL;
}/*fecha a funcao de criacao*/

void push(Pilha *top, int inf){
  
  Pilha *temp;/*declara um ponteiro do tipo pilha*/
  temp = malloc(sizeof(Pilha));/*aloca memoria para o ponteiro*/  
  temp -> info = inf;/*guarda a informacao*/
  temp -> proximo = top -> proximo;/*aponta para NULL*/
  top -> proximo = temp;/*agora o topo eo temp*/
  
}/*fecha a funcao*/

int pop(Pilha *top){
  
  Pilha *aux;/*auxiliar*/
  int r;/*informacao contida*/
  aux = top->proximo;
  top -> proximo = aux->proximo;
  r = aux -> info;
  free(aux);/*libera aquele endereco*/
  return r;
  
}/*fecha a funcao*/

int vazia(Pilha *top){
  
  if(top->proximo == NULL)
    return 1;
  else
    return 0;
    
}/*fecha a funcao*/

void mostra(Pilha *top){
  
  Pilha *p;
  for(p = top->proximo; p != NULL; p = p -> proximo){
    
    printf("%d\n", p -> info);
    
  }/*fecha o for*/
  
}/*fecha a funcao*/

void esvazia(Pilha *top){
  
  Pilha *p;
  Pilha *aux;
  p = top->proximo;
  while(p != NULL){
    aux = p;
    p = p -> proximo;
    free(aux);
  }/*fecha o while*/
  
}/*fecha a funcao*/
