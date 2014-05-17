#include "./biblioteca.h"

void main(int argc, char const *argv[])
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
	Arvore *arvore_geral=NULL;
	arvore_geral = gera_indice_invertido(Files);
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
	//return 0;
}