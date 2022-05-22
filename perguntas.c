#include <stdio.h>
#include <string.h>
#include <stdlib.h>


FILE* abrirArquivoLista(FILE *file, int a){
    if (a == 1)
    {
        file = fopen("perguntas/listapergunta1.txt", "w");
    }
    else if (a == 2)
    {
        file = fopen("perguntas/listapergunta2.txt", "w");
    }
    else if (a == 3)
    {
        file = fopen("perguntas/listapergunta3.txt", "w");
    }
    else if (a == 4)
    {
        file = fopen("perguntas/listapergunta4.txt", "w");
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
        file1 = fopen("perguntas/listapergunta1.txt", "r");
        if (file1 == NULL)
        {
            file1 = fopen("perguntas/listapergunta1.txt", "w");
            fprintf(file1, "Nada\nNada\nNada\nNada");
            fclose(file1);
        }
        file2 = fopen("perguntas/listapergunta2.txt", "r");
        if (file2 == NULL)
        {
            file2 = fopen("perguntas/listapergunta2.txt", "w");
            fprintf(file2, "Nada\nNada\nNada\nNada");
            fclose(file2);
        }
        file3 = fopen("perguntas/listapergunta3.txt", "r");
        if (file3 == NULL)
        {
            file3 = fopen("perguntas/listapergunta3.txt", "w");
            fprintf(file3, "Nada\nNada\nNada\nNada");
            fclose(file3);
        }
        file4 = fopen("perguntas/listapergunta4.txt", "r");
        if (file4 == NULL)
        {
            file4 = fopen("perguntas/listapergunta4.txt", "w");
            fprintf(file4, "Nada\nNada\nNada\nNada");
            fclose(file4);
        }
    
}


void printarMenuPerguntas(){
    printf("========== Mensagem =============\n");
    printf("1 >> Visualizar perguntas Padrao\n");
	printf("2 >> Visualizar lista de Perguntas\n");
	printf("3 >> Editar lista de Perguntas\n");
    printf("0 >> Sair\n");
}


void escreverArquivoPerguntasPadrao(){
    FILE *file = fopen("perguntas/perguntaspadrao.txt", "w");

    // Editar com as perguntas retiradas do médico

    fprintf(file, "Pergunta Padrao\nPergunta Padrao\nPergunta Padrao\nPergunta Padrao");
    fclose(file);
}
int main()
{
    int opcao, num_lista, opcao_alterar_pergunta;
    int contador_perguntas = 1;
    char perguntas_padrao[1000];
    
    FILE *file1, *file2, *file3, *file4;
    
    criarArquivoListaPerguntas();
    escreverArquivoPerguntasPadrao();

    file1 = fopen("perguntas/listapergunta1.txt", "r");
    file2 = fopen("perguntas/listapergunta2.txt", "r");
    file3 = fopen("perguntas/listapergunta3.txt", "r");
    file4 = fopen("perguntas/listapergunta4.txt", "r");
    
    FILE *file = fopen("perguntas/perguntaspadrao.txt", "r");

    do
    {
        printarMenuPerguntas();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("==== PERGUNTAS PADRAO ====\n");
            
            while (fscanf(file, "%[^\n] ", perguntas_padrao) != EOF) {
                
                printf("%d - %s\n", contador_perguntas, perguntas_padrao);
                contador_perguntas++;

            }
            
            break;
        
        case 2:
            file1 = fopen("perguntas/listapergunta1.txt", "r");
            file2 = fopen("perguntas/listapergunta2.txt", "r");
            file3 = fopen("perguntas/listapergunta3.txt", "r");
            file4 = fopen("perguntas/listapergunta4.txt", "r");

            printf("Numero da lista: ");
            scanf("%d", &num_lista);

            if (num_lista == 1)
            {
                char saida_lista_pergunta[100];
                int contador_perguntas_lista = 1;

                printf("==== LISTA 1 ====\n");
                while (fscanf(file1, "%[^\n] ", saida_lista_pergunta) != EOF) {
                    printf("%d - %s\n", contador_perguntas_lista, saida_lista_pergunta);
                    contador_perguntas_lista++;
                
                }
            }
            if (num_lista == 2)
            {
                char saida_lista_pergunta[100];
                int contador_perguntas_lista = 1;

                printf("==== LISTA 2 ====\n");
                while (fscanf(file2, "%[^\n] ", saida_lista_pergunta) != EOF) {
                    printf("%d - %s\n", contador_perguntas_lista, saida_lista_pergunta);
                    contador_perguntas_lista++;
                
                }
            }
            if (num_lista == 3)
            {
                char saida_lista_pergunta[100];
                int contador_perguntas_lista = 1;

                printf("==== LISTA 3 ====\n");
                while (fscanf(file3, "%[^\n] ", saida_lista_pergunta) != EOF) {
                    printf("%d - %s\n", contador_perguntas_lista, saida_lista_pergunta);
                    contador_perguntas_lista++;
                
                }
            }
            if (num_lista == 4)
            {
                char saida_lista_pergunta[100];
                int contador_perguntas_lista = 1;

                printf("==== LISTA 4 ====\n");
                while (fscanf(file4, "%[^\n] ", saida_lista_pergunta) != EOF) {
                    printf("%d - %s\n", contador_perguntas_lista, saida_lista_pergunta);
                    contador_perguntas_lista++;
                
                }
            }
            
            break;
            
        case 3:
            do
            {
                file1 = fopen("perguntas/listapergunta1.txt", "r");
                file2 = fopen("perguntas/listapergunta2.txt", "r");
                file3 = fopen("perguntas/listapergunta3.txt", "r");
                file4 = fopen("perguntas/listapergunta4.txt", "r");

                printf("Numero da lista: ");
                scanf("%d", &num_lista);
                if (num_lista == 1)
                {
                    alterarPerguntaLista(file1, num_lista);
                    
                }
                else if (num_lista == 2)
                {
                    alterarPerguntaLista(file2, num_lista);
                    
                }
                else if (num_lista == 3)
                {
                    alterarPerguntaLista(file3, num_lista);
                    
                }
                else if (num_lista == 4)
                {
                    alterarPerguntaLista(file4, num_lista);
                    
                }

                do
                {
                    printf("Finalizar operacao \n[1] Continuar\n[0] Sair\n");
                    scanf("%d", &opcao_alterar_pergunta);
                    if (opcao_alterar_pergunta == 0 || opcao_alterar_pergunta == 1)
                    {
                        break;
                    }
                    else
                    {
                        printf("Digite um numero valido.\n");
                        continue;
                    }
                    
                } while (1);
                
            } while (opcao_alterar_pergunta != 0);
            
            break;
        }

    } while (opcao != 0);
    
    
    return 0;
}
