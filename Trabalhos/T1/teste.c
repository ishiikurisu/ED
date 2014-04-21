#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count.h"

void write (List* word) {
	List* seq = word;

	while (seq != NULL) {
		printf("%s\n", word->nome);
	}
}

void main () {
	FILE *fp; List *word, *punct;
	char* lido;

	word = (List*) malloc(sizeof(List));
	punct = (List*) malloc(sizeof(List));
	fp = fopen("text1.txt", "r");
	while (fp != NULL) {
		lido = salvar(descobrirTamanho(fp), fp);
		adicionar(lido, word, punct);
	}
	write(word);

	getchar();
}