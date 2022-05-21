#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrar_usuario(){

    char user[100];
    char password[100];

    printf("Informe o usuario: ");
    fflush(stdin);
    gets(user);

    printf("Informe a senha: ");
    fflush(stdin);
    gets(password);

    FILE* file = fopen("pessoas.txt","w");

    fprintf(file, "%s\n", user);
    fprintf(file, "%s", password);
    fprintf(file, "\n");
 
    fclose(file);
}

int login(){
    char user[100];
    char password[100];

    char user_confirm[100];
    char password_confirm[100];

    printf("Informe o login: ");
    fflush(stdin);
    gets(user);

    printf("Informe a senha: ");
    fflush(stdin);
    gets(password);

    FILE* file = fopen("pessoas.txt","r");

    fscanf(file,"%s\n", user_confirm);
    fscanf(file,"%s", password_confirm);

    if(strcmp(user,user_confirm)==0 && strcmp(password,password_confirm) == 0){
        return 1;
    }
    else{
        return 0;
    }

    fclose(file);
}

int main(){

    FILE* file = fopen("pessoas.txt","r");

    if(file == NULL){
        file = fopen("pessoas.txt","w");
        fclose(file);
    }

    cadastrar_usuario();
    int validador = login();

    if(validador == 0){
        printf("Usuario ou senha incorretos");
    }
    else if(validador == 1){
        printf("Usuario logado");
    }

    return 0;
}