#include <stdlib.h>
#include <stdio.h>

struct List { /*Lista*/
  struct List* next;
  int ocur;
  char* name;
};
typedef struct List list;

struct Arq { /*lista relacionado a um arquivo*/
  FILE* fp;
  list* word;
  list* punct;
  struct Arq* next;
};
typedef struct Arq arq;

/*********
ACESSORIES
*********/

list* newList () {
  list* lst = (list*) malloc(sizeof(list));
  lst->next = NULL;
  lst->ocur = 0;

  return lst;
}

arq* newText () {
  arq* sequence = (arq*) malloc(sizeof(arq));
  char fname[10]; 

  printf("Digite o nome do arquivo: ");
  getchar();
  scanf("%s", fname);
  sequence->fp = fopen(fname, "r");
  sequence->word = newList();
  sequence->punct = newList();
  sequence->next = NULL;

  return sequence;
}

/*
void sort () {
  list* sequence;
  int temp, i, j, flag = 1;
   
  while (flag) {
    flag = 0;
    sequence = head;
    while (sequence->next != NULL) {
      if ((sequence->next)->number < sequence->number) {
        temp = sequence->number;
        sequence->number = (sequence->next)->number;
        (sequence->next)->number = temp;
        flag++;
      }
      sequence = sequence->next;
    }
  }
}*/
  
/*************
MAIN FUNCTIONS
*************/
int findSize(FILE* fp) {
  char c; int size;
  FILE* cp = fp;

  do {
    fscanf(cp, "%c", &c);
    size++;
  } while (c != ' ' || c != '\n');

  return size;
}

void addFreq (int size, arq* head) {
  arq* seq = head;
  char* read; int i = 0;

  seq->word->name = (char*) malloc((size+1)*sizeof(char));
  for (i = 0; i < size; i++)
    fscanf(head->fp, "%c", head->word->name[i]);
  read[i] = '\0';    
  head->word = head->word->next;
}

void write (arq* head) {
  list* sequence = head->word;
  
  while (sequence->next != NULL) {
    printf("%s ", sequence->name);
    sequence = sequence->next;
  }
}

void readFile (arq* head) {
  arq* seq = head;
  list* bkp = seq->word;
   
  do {
    addFreq(findSize(seq->fp), seq);
  } while (seq->fp != NULL);
  fclose(seq->fp);
}

int main () {
  arq *textos, *seq;
  int i = 0;

  seq = textos;
  for (i = 0; i < 2; i++) {
    seq = newText();
    readFile(seq);
    write(seq);
    /*sort(seq);
    seq = seq->next;*/
  }
   
  getchar();
  return 0;
}