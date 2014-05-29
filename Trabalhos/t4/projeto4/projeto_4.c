/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados  1/2014
Aluno(a): < Luís Alberto Martins Sales >
Matricula: < 130013579 >
Aluno(a): < Cristiano Silva Jr >
Matricula: < 130070629 > 
Turma: E
Versão do compilador: < gcc version 4.7.3  >
Descricao: < Algoritmo de pesquisa/espalhamento  >
*/

/*DETALHAMENTO
Este alogoritmo consiste em 3 partes basicas:

+ Inicialmente ele cria as estruturas de dados 
necessarias para que o algoritmo possa gerar um 
possivel hashing para as palavras presentes nos 
arquivos de texto.

+ Em seguida, o programa abre cada um dos arquivos e
adiciona as palavras em uma lista preliminar. Caso a
palavra nao exista na lista, um novo no e criado; caso
contrario, sua frequencia e aumentada. Apos a leitura
de todos os arquivos, o programa reorganiza esta lista
na forma de uma arvore, onde a pesquisa sera feita 
usando uma funcao de hashing que ira espalhar as
palavras pela lista de indice invertido. Esta lista
sera impressa pelo programa para ser usada mais tarde

+ Finalmente, o programa lera esta nova lista e gerara
uma nova lista, de onde se podera procurar as palavras
e interagir com o usuario, permitindo-o procurar por 
palavras e estatisticas.

*/

#include "./biblioteca.h"

int main (int argc, char const *argv[])
{
  int i;
  int menor;
  FILE* fp;
  Arvore* arvore_geral;
  Arvore** vetor_de_hash;

  if (argv[1] == NULL)
  {
    printf("Não há arquivos!\n");
    exit(1);
  }
  char* arquivos = argv[1];
  fp = abre_arquivo(arquivos);
  Arquivo Files[MAX_ARQUIV];
  le_arquivos(Files, fp);
  menor = acessa_arquivos(Files);
  arvore_geral = NULL;
  gera_indice_invertido(Files);
  arvore_geral = le_indice_invertido();
  vetor_de_hash = hashing(arvore_geral, menor);
  estatistica(vetor_de_hash, menor);
  interagir_com_usuario(vetor_de_hash, menor);
  fecha_arquivos(fp, Files);

  return 0;
}