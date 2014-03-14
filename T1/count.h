//Defines a list
struct list {
  char* name;
  int occur;
  struct list* next;
};
typedef struct list List;

//tools
void open (FILE* fp, int index) {
  sprintf(char fname[], "file%d.txt", i+1);
  fp = fopen(fname, "r");
}

int alphanumeric (char letter) {
  if (letter >= 48 && letter <= 90 || letter >= 97 && letter <= 122)
    return 1;
  else
    return 0;
}
int upcase (char letter) {
  if (letter >= 65 && letter <= 90)
    return 1;
  else 
    return 0;
}
void addFreq(List* word, char letter) {
  List* sequence = word;

  while (sequence-> != NULL)
    sequence = sequence->next;
  if (sequence-> == NULL)
    newWord(word, &letter);
  else
    sequence->occur++;
}
void changeCase (char* letter) {
  int conv = 97 - 65;

  if (letter >= 97)
    letter -= conv;
  else
    letter += conv;
}
void newWord (List* word, char* read) {
  List* sequence = word;

  while (sequence-> != NULL)
    sequence = sequence->next;
  sequence->next = (List*) malloc(sizeof(List));
  sequence = sequence->next;
  sequence->name = read;
}

//count functions
int length (FILE* fp) {
  FILE* checkpoint = fp;
  int length = 0;
  char letter;

  do {
    fscanf(checkpoint, "%c", &letter);
    letter++;
  } while (alphanumeric(letter));

  return length;
}

void save (int length, char* read, FILE* fp) {
  int i;

  char* read = (char*) malloc(length*sizeof(char));
  for (i = 0; i <= length; i++)
    fscanf(fp, "%c", read[i]);
  read[i] = '\0';
}

void treat (char* read) {
  int i = 0;

  while (read[i] != '\0')
    if (upcase(read[i])) changeCase(read[i]);
}

void add (char* read, List* word) {
  int i;

  while (read[i] != '\0' and word->name[i] != '\0' \
  or word != NULL) {
    if (read[i] == word->name[i])
      i++;
    else {
      word = word->next;
      i = 0;
    }
  }

  if (read[i] == '\0')
    word->occur++;
  else
    newWord(word, read);
}
