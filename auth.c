#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuLogin(){
	printf("\n======== MENU ========\n");
	printf("1 >> Login\n");
	printf("2 >> Criar conta\n");
	printf("3 >> Sair\n");
}

void cadastrar_usuario(){

    char user[100];
    char password[100];

    printf("\n========== CADASTRO =============\n");

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

    printf("\n========== LOGIN =============\n");

    printf("Login: ");
    fflush(stdin);
    gets(user);

    printf("Senha: ");
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

    int opcao = 0;
    int validador;

    FILE* file = fopen("pessoas.txt","r");

    if(file == NULL){
        file = fopen("pessoas.txt","w");
        fclose(file);
    }
    
    do{
        menuLogin();
        printf("Opcao: "); 
        scanf("%i",&opcao);
        getchar();

        switch (opcao){
            case 1:
                validador = login();
                

                if(validador == 0){
                    printf("\nUsuario ou senha incorretos !!!");
                }
                else if(validador == 1){
                    printf("\nUsuario logado !!!");
                    opcao = 3;
                }

                break;

            case 2:
                cadastrar_usuario();
                break;
        }

    }while(opcao != 3);

    return 0;
}