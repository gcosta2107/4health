#include <stdio.h>

void cadastrar_paciente(){
    char paciente[40];

    FILE* file = fopen("arquivos/Contatos.txt","a");

    printf("Inserir paciente: ");
    scanf("%s", paciente);

    fprintf(file,paciente);
    fprintf(file,"\n");

    fclose(file);
}

void visualizar_pacientes(){
    char paciente[40];
    int contador_linhas = 1;

    FILE* file = fopen("arquivos/Contatos.txt","r");

    printf("\n========== PACIENTES =============\n");

    while (fscanf(file, "%[^\n] ", paciente) != EOF) {
                
        printf("%d - %s\n", contador_linhas, paciente);
        contador_linhas++;

    }

    fclose(file);
}