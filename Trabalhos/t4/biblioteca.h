#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define pi (3.1415926535)
/*Célula contendo um ponteiro para a palavra, sua quantidade e 
ponteiro para o proximo elemento*/
#define MAX_ARQUIV 10
/*proximo == filho direita
anterior == filho esquerda*/
struct lista
{
    char* palavra;
    unsigned int quantidade;
    struct lista *proximo;
    struct lista *anterior;
};
typedef struct lista tipo_lista;
struct arvore
{
    char* palavra;
    unsigned int quantidade;
    struct arvore *proximo;
    struct arvore *anterior;
    int arquivo_origem[MAX_ARQUIV];
};
typedef struct arvore Arvore;
typedef struct arquivo Arquivo;
struct arquivo
{
    char* nome_arquivo;
    FILE* ponteiro_arquivo;
    tipo_lista* lista;
};
tipo_lista* inclui_na_lista(char* aux,tipo_lista* palavr)
{
    if (palavr==NULL)
    {
        tipo_lista* no = (tipo_lista*) malloc(sizeof(tipo_lista));
        if (no==NULL)
        {
            printf("No memory!\n");
            exit(1);
        }
        no->quantidade=1;
        no->proximo=NULL;
        no->anterior=NULL;
        no->palavra=(char*)malloc(sizeof(aux));
        strcpy(no->palavra,aux);
        return no;
    }
    if (strcmp(aux,palavr->palavra)==0)
    {
        ++palavr->quantidade;
        return palavr;
    }
    if (strcmp(aux,palavr->palavra)<0)
    {
        palavr->anterior = inclui_na_lista(aux,palavr->anterior);
        return palavr;
    }
    else
    {
        palavr->proximo = inclui_na_lista(aux,palavr->proximo);
        return palavr;
    }
}
void imprime_lista(tipo_lista* arvore)
{
    if (arvore!=NULL)
    {
        imprime_lista(arvore->anterior);
        printf("%s\n", arvore->palavra);
        printf("%d\n", arvore->quantidade);
        imprime_lista(arvore->proximo);
    }
}
void gera_lista (Arquivo* file)
{
    FILE* fp = file->ponteiro_arquivo;
    tipo_lista* palavr = file->lista;
    char teste;
    char* aux;
    unsigned int i=1;
    while((teste=fgetc(fp))!=EOF)
    {
        if (isalnum(teste))
        {
            if ((aux=(char*)malloc(2*sizeof(char)))==NULL)
            {
                printf("Memória insuficiente\n");
                exit(1);
            }
            aux[0]=teste;
            while(((aux[i]=fgetc(fp))!= EOF) && isalnum(aux[i]))
            {
                if ((aux=(char*)realloc(aux,(2+i)*sizeof(char)))==NULL)
                {
                    printf("Memória insuficiente\n");
                    exit(1);
                }
                ++i;
            }
            aux[i]='\0';
            file->lista = inclui_na_lista(aux,file->lista);
            free(aux);
            i=1;
        }
    }
}
FILE* abre_arquivo (char* nome_arquivo)
{
    FILE *fp;
    fp = fopen(nome_arquivo,"r");
    if (fp==NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        system("echo '1'");
        exit(1);
    }
    return fp;
}
void le_arquivos (Arquivo* Files,FILE* fp)
{
    char* nome_arquivo_temp = (char*)malloc(sizeof(char));
    int indice_arquivo=0;
    while((nome_arquivo_temp[0]=fgetc(fp))!=EOF && indice_arquivo<MAX_ARQUIV)
    {
        nome_arquivo_temp = (char*)realloc(nome_arquivo_temp,2*sizeof(char));
        int i=1;
        while((nome_arquivo_temp[i]=fgetc(fp))!=EOF && nome_arquivo_temp[i]!='\n')
        {
            nome_arquivo_temp = (char*)realloc(nome_arquivo_temp,(i+2)*sizeof(char));
            ++i;
        }
        nome_arquivo_temp[i]='\0';
        Files[indice_arquivo].nome_arquivo=(char*)malloc(sizeof(nome_arquivo_temp));
        strcpy(Files[indice_arquivo].nome_arquivo,nome_arquivo_temp);
        free(nome_arquivo_temp);
        nome_arquivo_temp = (char*)malloc(sizeof(char));
        ++indice_arquivo;
    }
}
int global_quant=0;
void quantidade_palavras (tipo_lista* lista)
{
    if (lista!=NULL)
    {
        quantidade_palavras(lista->anterior);
        ++global_quant;
        quantidade_palavras(lista->proximo);
    }
}
int acessa_arquivos (Arquivo* Files)
{
    int i;
    uint menor = -1;
    for (i = 0; i < MAX_ARQUIV; ++i)
    {
        Files[i].ponteiro_arquivo = fopen(Files[i].nome_arquivo,"r");
        if (Files[i].ponteiro_arquivo==NULL)
        {
            printf("Erro na abertura do arquivo %s!\n",Files[i].nome_arquivo);
            system("echo '2'");
            exit(2);
        }
        Files[i].lista=NULL;
        gera_lista(&Files[i]);
        int quant_palavr = 0;
        global_quant = 0;
        quantidade_palavras(Files[i].lista);
        int quant = global_quant;
        if (quant < menor)
        {
            menor = quant;
        }
    }
    return menor;
}
unsigned long
hash(unsigned char *str)
{
    /*5381*/
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
void fecha_arquivos(FILE* fp, Arquivo* Files)
{

    fclose(fp);
    int i;
    for (i = 0; i < MAX_ARQUIV; ++i)
    {
        fclose(Files[i].ponteiro_arquivo);
    }
}
/*gerar indice invertido*/
Arvore* inclui_na_arvore (Arvore* tree,tipo_lista* lista,int num_arquiv)
{
    if (tree==NULL)
    {
        Arvore* No = (Arvore*)malloc(sizeof(Arvore));
        if (No==NULL)
        {
            printf("No memory!\n");
            exit(1);
        }
        (*No).palavra = (char*) malloc(sizeof(lista->palavra));
        if (No->palavra==NULL)
        {
            printf("No memory\n");
            exit(1);
        }
        strcpy(No->palavra,lista->palavra);
        int i;
        for (i = 0; i < MAX_ARQUIV; ++i)
        {
            No->arquivo_origem[i]=0;
        }
        No->arquivo_origem[num_arquiv] = 1;
        No->quantidade = lista->quantidade;
        No->anterior = NULL;
        No->proximo = NULL;
        return No;
    }
    if (strcmp(lista->palavra,tree->palavra)==0)
    {
        tree->quantidade+=lista->quantidade;
        tree->arquivo_origem[num_arquiv]=1;
        return tree;
    }
    if (strcmp(lista->palavra,tree->palavra)<0)
    {
        tree->anterior = inclui_na_arvore(tree->anterior,lista,num_arquiv);
        return tree;
    }
    else
    {
        tree->proximo = inclui_na_arvore(tree->proximo,lista,num_arquiv);
        return tree;
    }
}
Arvore* gera_arvore_geral (Arvore* tree,tipo_lista* lista,int num_arquiv)
{
    if (lista!=NULL)
    {
        tree = inclui_na_arvore(tree,lista,num_arquiv);
        tree = gera_arvore_geral(tree,lista->anterior,num_arquiv);
        tree = gera_arvore_geral(tree,lista->proximo,num_arquiv);
    }
    return tree;
}
FILE* imprime_arvore (Arvore* tree, FILE* fp)
{
    if (tree!=NULL)
    {
        imprime_arvore(tree->anterior,fp);
        //printf("%s\t", tree->palavra);
        fprintf(fp, "%s\t", tree->palavra);
        int i;
        for (i = 0; i < MAX_ARQUIV; ++i)
        {
            if (tree->arquivo_origem[i])
            {
                //printf("\tArquivo origem: %d", i+1);
                fprintf(fp, "\tArquivo origem: %d", i+1);
            }
        }
        //printf("\tFrequencia: %d\n", tree->quantidade);
        fprintf(fp, "\tFrequencia: %d\n", tree->quantidade);
        imprime_arvore(tree->proximo,fp);
    }
    return fp;
}
Arvore* gera_indice_invertido(Arquivo* Files)
{
    Arvore* tree=NULL;
    int i;
    //printf("Começo arvore\n");
    for (i = 0; i < MAX_ARQUIV; ++i)
    {
        tree = gera_arvore_geral(tree,Files[i].lista,i);
    }
    FILE* fp = fopen("IndInvert.txt", "w");
    rewind(fp);
    imprime_arvore(tree,fp);
    fclose(fp);
    return tree;
}

/*Hashing*/
Arvore** incluir_hashing(Arvore** vetor,Arvore* tree,int maior)
{
    if (tree!=NULL)
    {
        vetor=incluir_hashing(vetor,tree->anterior,maior);
        int index = (hash(tree->palavra) % maior);
        //printf("%d\n", index);
        Arvore* No = (Arvore*)malloc(sizeof(Arvore));
        if (No==NULL)
        {
            printf("No memory!\n");
            exit(1);
        }
        (*No).palavra = (char*) malloc(sizeof(tree->palavra));
        if (No->palavra==NULL)
        {
            printf("No memory\n");
            exit(1);
        }
        strcpy(No->palavra,tree->palavra);
        int i;
        for (i = 0; i < MAX_ARQUIV; ++i)
        {
            No->arquivo_origem[i]=tree->arquivo_origem[i];
        }
        No->quantidade = tree->quantidade;
        No->anterior = NULL;
        No->proximo = NULL;
        if (vetor[index]==NULL)
        {
            vetor[index]=No;
        }
        else
        {
            Arvore* desbravador = vetor[index];
            while(desbravador->proximo!=NULL)
            {
                desbravador=desbravador->proximo;
            }
            desbravador->proximo=No;
        }
        vetor=incluir_hashing(vetor,tree->proximo,maior);
    }
    return vetor;
}
Arvore** hashing (Arvore* tree,int maior)
{
    Arvore** vetor;
    vetor = (Arvore**) malloc(maior*sizeof(Arvore*));
    int i=0;
    for (i = 0; i < maior; ++i)
    {
        vetor[i]=NULL;
    }
    vetor = incluir_hashing(vetor,tree,maior);
    return vetor;
}
void imprime_hash (Arvore* tree)
{
    if (tree!=NULL)
    {
        imprime_hash(tree->anterior);
        printf("%s\t", tree->palavra);
        int i;
        for (i = 0; i < MAX_ARQUIV; ++i)
        {
            if (tree->arquivo_origem[i])
            {
                printf("\tArquivo origem: %d", i+1);
            }
        }
        printf("\tFrequencia: %d\n", tree->quantidade);
        imprime_hash(tree->proximo);
    }
}
/*estatistica*/
void imprime_hash_doc (Arvore* tree,int menor,FILE* fp)
{
    if (tree!=NULL)
    {
        imprime_hash_doc(tree->anterior,menor,fp);
        fprintf(fp,"%s\t", tree->palavra);
        fprintf(fp,"%lu\t", hash(tree->palavra));
        fprintf(fp,"%d\n", (int)    (hash(tree->palavra) % menor));
        imprime_hash_doc(tree->proximo,menor,fp);
    }
}
void estatistica (Arvore** vetor,int menor)
{
    FILE* fp = fopen("HashDocs.txt","w");
    int total_palavr=0;
    int n_colisoes=0;
    int maior_colisao=0;
    int i;
    for (i = 0; i < menor; ++i)
    {
        int colisao_parcial=0;
        if (vetor[i]!=NULL)
        {
            Arvore* desbravador=vetor[i];
            total_palavr+=desbravador->quantidade;
            while(desbravador->proximo!=NULL)
            {
                desbravador=desbravador->proximo;
                total_palavr+=desbravador->quantidade;
                ++colisao_parcial;
                ++n_colisoes;
            }
        }
        if (colisao_parcial > maior_colisao)
        {
            maior_colisao = colisao_parcial;
        }
        imprime_hash_doc(vetor[i],menor,fp);
    }
    printf("Olá\n");
    fprintf(fp, "Número total de colisões:%d\n", n_colisoes);
    fprintf(fp, "Número de elementos da maior lista de colisões:%d\n", maior_colisao+1);
    fprintf(fp, "Número total de palavras:%d\n", total_palavr);
    fprintf(fp, "Número máximo do índice:%d\n", menor);
    fclose(fp);
}
/*Interagir com usuario*/
void interagir_com_usuario (Arvore** vetor,int menor)
{
    char decisao;
    do
    {
        printf("Informe a palavra\n");
        char* palavra;
        scanf("%s",palavra);
        //printf("%s\n", palavra);
        int flag = 0;
        Arvore* desbravador = vetor[(hash(palavra)%menor)];
        while(desbravador!=NULL)
        {
            if (strcmp(desbravador->palavra,palavra)==0)
            {
                flag=1;
                break;
            }
            desbravador=desbravador->proximo;
        }
        if (flag==0)
        {
            printf("Palavra não encontrada\n");
        }
        else
        {
            printf("Palavra encontrada nos arquivos:\n");
            int i;
            for ( i = 0; i < MAX_ARQUIV; ++i)
            {
                if (desbravador->arquivo_origem[i])
                {
                    printf("%d\t", i+1);
                }
            }
            printf("\n");
        }
        printf("Deseja continua? (s/n)\n");
        scanf(" %c",&decisao);
    }
    while(decisao=='s');
}