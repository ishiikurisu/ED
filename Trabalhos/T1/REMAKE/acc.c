/*********
 ACESSORIES
 *********/
 int compareStrings (char* string1, char* string2) {
  int i = 0;

  while (string1[i] != '\0' || string2[i] != '\0')
    i++;

  return (string1[i] != '\0' && string2[i] != '\0')? 1: 0;
 }

 int alphabetic (char letra) {
  if ((letra >= 48 && letra <= 90) || (letra >= 97 && letra <= 122))
    return 1;
  else
    return 0;
}

/*************
MAIN FUNCTIONS
*************/
int findSize(arq* head) {
  char c; int size;
  FILE* cp = head->fp;

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