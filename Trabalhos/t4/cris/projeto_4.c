#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define pi (3.1415926535)

#include "./biblioteca.h"

int main(int argc, char const *argv[])
{
  if (argv[1] == NULL)
  {
    printf("Não há arquivos!\n");
    exit(1);
  }
  char* arquivos = argv[1];
  FILE* fp = abre_arquivo(arquivos);
  Arquivo Files[MAX_ARQUIV];
  le_arquivos(Files,fp);
  acessa_arquivos(Files);
  //fecha_arquivos(fp,Files);
  return 0;
}