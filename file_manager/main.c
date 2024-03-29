#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autenticacao.h"
#include "perguntas.h"
#include "pacientes.h"

//funções do perguntas.h
FILE* abrirArquivoLista(FILE *file, int a);
void alterarPerguntaLista(FILE* file, int num_lista);
void criarArquivoListaPerguntas();
void escreverArquivoPerguntasPadrao();

//funções do arquivo autenticacao.h
void menuLogin();
void cadastrar_usuario();
int login();

//funções do pacientes autenticacao.h
void cadastrar_paciente();
void visualizar_pacientes();

void printarMenu(){
    printf("\n========== Mensagem =============\n");
    printf("1 >> Visualizar perguntas Padrao\n");
	printf("2 >> Visualizar lista de Perguntas\n");
	printf("3 >> Editar lista de Perguntas\n");
    printf("4 >> Cadastrar Paciente\n");
    printf("5 >> Visualizar Pacientes\n");
    printf("0 >> Sair\n");
}

int main(){
    int opcao = 0;
    int validador = 0;

    FILE* f = fopen("../db/cadastros.txt","r");

    if(f == NULL){
        f = fopen("../db/cadastros.txt","w");
        fclose(f);
    }
    
    do{
        menuLogin();
        printf("\nOpcao: ");
        scanf("%i",&opcao);
        getchar();
        printf("\n");

        switch (opcao){
            case 1:
                validador = login();

                if(validador == 0){
                    printf("\nUsuario ou senha incorretos !!!");
                }
                else if(validador == 1){
                    printf("\nUsuario logado !!!\n");
                    opcao = -1;
                }

                break;

            case 2:
                cadastrar_usuario();
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Opcao invalida !!!!\n");
                break;
        }

        if(opcao == -1 && validador != 1){
            exit(0);
        }

    }while(opcao != -1);

    opcao = 0;

    int num_lista, opcao_alterar_pergunta;
    int contador_perguntas = 1;
    char perguntas_padrao[1000];
    
    FILE *file1, *file2, *file3, *file4;
    
    criarArquivoListaPerguntas();
    escreverArquivoPerguntasPadrao();

    file1 = fopen("../db/listapergunta1.txt", "r");
    file2 = fopen("../db/listapergunta2.txt", "r");
    file3 = fopen("../db/listapergunta3.txt", "r");
    file4 = fopen("../db/listapergunta4.txt", "r");
    
    FILE *file = fopen("../db/perguntaspadrao.txt", "r");

    do
    {
        printarMenu();
        printf("Opcao: ");
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
            file1 = fopen("../db/listapergunta1.txt", "r");
            file2 = fopen("../db/listapergunta2.txt", "r");
            file3 = fopen("../db/listapergunta3.txt", "r");
            file4 = fopen("../db/listapergunta4.txt", "r");

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
                file1 = fopen("../db/listapergunta1.txt", "r");
                file2 = fopen("../db/listapergunta2.txt", "r");
                file3 = fopen("../db/listapergunta3.txt", "r");
                file4 = fopen("../db/listapergunta4.txt", "r");

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

            case 4:
                cadastrar_paciente();
                break;

            case 5:
                printf("\n");
                visualizar_pacientes();
                break;
        }

    } while (opcao != 0);

    return 0;
}