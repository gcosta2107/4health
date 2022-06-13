#include <stdio.h>
#include <stdlib.h>

void cadastrar_paciente(){
    char paciente[40];

    FILE* file = fopen("../db/Contatos.txt","a");

    printf("Inserir paciente: ");
    fflush(stdin);
    gets(paciente);

    fprintf(file,paciente);
    fprintf(file,"\n");

    fclose(file);
}

void visualizar_pacientes(){
    char paciente[40];
    int contador_linhas = 1;

    FILE* file = fopen("../db/Contatos.txt","r");

    printf("\n========== PACIENTES =============\n");

    while (fscanf(file, "%[^\n] ", paciente) != EOF) {
                
        printf("%d - %s\n", contador_linhas, paciente);
        contador_linhas++;

    }

    fclose(file);
}