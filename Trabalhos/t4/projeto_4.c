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
#include "./biblioteca.h"
int main(int argc, char const *argv[])
{
	if (argv[1]==NULL)
	{
		printf("Não há arquivos!\n");
		exit(1);
	}
	char* arquivos = argv[1];
	FILE* fp = abre_arquivo(arquivos);
	Arquivo Files[MAX_ARQUIV];
	le_arquivos(Files,fp);
	int menor = acessa_arquivos(Files);
	//menor = 129;
	Arvore *arvore_geral=NULL;
	gera_indice_invertido(Files);
	arvore_geral = le_indice_invertido();
	Arvore** vetor_de_hash = hashing(arvore_geral,menor);
	int i;
	//printf("Inicio hash\n");
	/*for (i = 0; i < menor; ++i)
	{
		printf("%d\n", i);
		imprime_hash(vetor_de_hash[i]);
		printf("\n");
	}*/
	estatistica(vetor_de_hash,menor);
	interagir_com_usuario(vetor_de_hash,menor);
	fecha_arquivos(fp,Files);
	return 0;
}