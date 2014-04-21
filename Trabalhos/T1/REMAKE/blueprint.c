#include <stdlib.h>
#include <stdio.h>

struct seq {
   int number;
   struct seq* next;
};
typedef struct seq Seq;

Seq* head;

Seq* newSeq () {
 Seq* sequence = malloc(sizeof(Seq));
   
  sequence->next = NULL;

  return sequence;
}

void readFile () {
  FILE* fp; Seq* sequence = head;
  char c;
   
  fp = fopen("sequence.txt", "r");
   
  do {
    fscanf(fp,"%c", &c);
    if (c != ' ' && c != '\n') {
      sequence->number = c - 48;
      sequence->next = newSeq();
      sequence = sequence->next;
    }
  } while (c != '\n');
   
  fclose(fp);
}

void sort () {
  Seq* sequence;
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
}

void show () {
  Seq* sequence = head;
  
  while (sequence->next != NULL) {
    printf("%d ", sequence->number);
    sequence = sequence->next;
  }
}

int main () {
  head = newSeq();
  readFile();
  sort();
  show();
   
  getchar();
  return 0;
}