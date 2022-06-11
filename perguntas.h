#include <stdio.h>
#include <string.h>
#include <stdlib.h>


FILE* abrirArquivoLista(FILE *file, int a){
    if (a == 1)
    {
        file = fopen("arquivos/listapergunta1.txt", "w");
    }
    else if (a == 2)
    {
        file = fopen("arquivos/listapergunta2.txt", "w");
    }
    else if (a == 3)
    {
        file = fopen("arquivos/listapergunta3.txt", "w");
    }
    else if (a == 4)
    {
        file = fopen("arquivos/listapergunta4.txt", "w");
    }
    
    return file;
}  
    
    
void alterarPerguntaLista(FILE* file, int num_lista){
    char pergunta1[100], pergunta2[100], pergunta3[100], pergunta4[100];
    int opcao_pergunta;
    fscanf(file, "%[^\n] ", pergunta1);
    fscanf(file, "%[^\n] ", pergunta2);
    fscanf(file, "%[^\n] ", pergunta3);
    fscanf(file, "%[^\n] ", pergunta4);

    printf("Numero da pergunta: ");
    scanf("%d", &opcao_pergunta);

    if (opcao_pergunta == 1)
    {
        printf("Editar a pergunta: ");
        fflush(stdin);
        gets(pergunta1);
        FILE* file = abrirArquivoLista(file, num_lista);
        fprintf(file,"%s\n%s\n%s\n%s", pergunta1, pergunta2, pergunta3, pergunta4);
        fclose(file);
    }
    else if (opcao_pergunta == 2)
    {
        printf("Editar a pergunta: ");
        fflush(stdin);
        gets(pergunta2);
        FILE* file = abrirArquivoLista(file, num_lista);
        fprintf(file,"%s\n%s\n%s\n%s", pergunta1, pergunta2, pergunta3, pergunta4);
        fclose(file);
    }
    else if (opcao_pergunta == 3)
    {
        printf("Editar a pergunta: ");
        fflush(stdin);
        gets(pergunta3);
        FILE* file = abrirArquivoLista(file, num_lista);
        fprintf(file,"%s\n%s\n%s\n%s", pergunta1, pergunta2, pergunta3, pergunta4);
        fclose(file);
    }
    else if (opcao_pergunta == 4)
    {
        printf("Editar a pergunta: ");
        fflush(stdin);
        gets(pergunta4);
        FILE* file = abrirArquivoLista(file, num_lista);
        fprintf(file,"%s\n%s\n%s\n%s", pergunta1, pergunta2, pergunta3, pergunta4);
        fclose(file);
    }
    
}


void criarArquivoListaPerguntas(){
        
        FILE *file1, *file2, *file3, *file4;
        file1 = fopen("arquivos/listapergunta1.txt", "r");
        if (file1 == NULL)
        {
            file1 = fopen("arquivos/listapergunta1.txt", "w");
            fprintf(file1, "Nada\nNada\nNada\nNada");
            fclose(file1);
        }
        file2 = fopen("arquivos/listapergunta2.txt", "r");
        if (file2 == NULL)
        {
            file2 = fopen("arquivos/listapergunta2.txt", "w");
            fprintf(file2, "Nada\nNada\nNada\nNada");
            fclose(file2);
        }
        file3 = fopen("arquivos/listapergunta3.txt", "r");
        if (file3 == NULL)
        {
            file3 = fopen("arquivos/listapergunta3.txt", "w");
            fprintf(file3, "Nada\nNada\nNada\nNada");
            fclose(file3);
        }
        file4 = fopen("arquivos/listapergunta4.txt", "r");
        if (file4 == NULL)
        {
            file4 = fopen("arquivos/listapergunta4.txt", "w");
            fprintf(file4, "Nada\nNada\nNada\nNada");
            fclose(file4);
        }
    
}


void printarMenuPerguntas(){
    printf("========== Mensagem =============\n");
    printf("1 >> Visualizar perguntas Padrao\n");
	printf("2 >> Visualizar lista de Perguntas\n");
	printf("3 >> Editar lista de Perguntas\n");
    printf("4 >> Cadastrar Paciente\n");
    printf("5 >> Visualizar Pacientes\n");
    printf("0 >> Sair\n");
}


void escreverArquivoPerguntasPadrao(){
    FILE *file = fopen("arquivos/perguntaspadrao.txt", "w");

    // Editar com as perguntas retiradas do médico

    fprintf(file, "Pergunta Padrao\nPergunta Padrao\nPergunta Padrao\nPergunta Padrao");
    fclose(file);
}
