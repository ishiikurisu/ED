#include <stdlib.h>
#include <stdio.h>
#include "count.h"
#include "result.h"

/*
#ifdef unix
#include <>
#else
#include <conio.h>
#endif
*/

void count (List** word, FILE** fp) {
  //char* read;

  while ((*word)->next != NULL) {
    save(length((*fp)), read, (*fp));
    treat(read);
    add(read, (*word));
  }
}

int test () {
  int i = 0;
  List* word[2];
  FILE* fp[2];
  
  for (i = 0; i < 2; i++) {
    open(fp[i]);
    count(word[i]);
    sort();
  }
  result();
  return again();
}

int menu() {
  int answer;

  printf("COMPARANDO ARQUIVOS\n\n");
  printf("1. COMPARAR ARQUIVOS\n");
  printf("2. SAIR\n\nOPCAO: ");
  scanf("%d", &answer);
  
  if (answer) answer = test();
  else answer = 0;
  
  return answer;
}

int main () {
  while(menu()){NILL};
  return 0;
}
