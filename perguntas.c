#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printarMenuPerguntas(){
    printf("========== Mensagem =============\n");
    printf("1 >> Visualizar perguntas Padrao\n");
	printf("2 >> Visualizar lista de Perguntas\n");
	printf("3 >> Editar lista de Perguntas\n");
}


void escreverArquivoPerguntasPadrao(){
    FILE *file = fopen("perguntaspadrao.txt", "w");

    // Editar com as perguntas retiradas do médico

    fprintf(file, "Pergunta Padrao\nPergunta Padrao\nPergunta Padrao\nPergunta Padrao");
    fclose(file);
    return file;
}
int main()
{
    int opcao, contador_perguntas = 1;
    char perguntas_padrao[1000];
    FILE *file = fopen("perguntaspadrao.txt", "r");
    
    escreverArquivoPerguntasPadrao();

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
    
    default:
        break;
    }
    return 0;
}
