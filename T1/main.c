#include <stdlib.h>
#include <stdio.h>
#include "count.h"
#include "result.h"

void count (List** word, FILE** fp) {
  char* read; int size;

  while ((*word)->next != NULL) {
    size = length(fp);
    save (size, read, fp);
    addFreq ((*word), read[size]);
    treat (read);
    add (read, (*word));
    (*word) = (*word)->next;
  }
}

int test () {
  int i = 0;
  List* word[2];
  FILE* fp[2];
  
  for (i = 0; i < 2; i++) {
    open (fp[i], i);
    count (word[i]);
    sort (word[i]);
    fclose(fp[i]);
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
