from leitura_arquivos import leitura_frases,view_file
from automacao_whatsapp import enviar_pergunta,iniciar_automacao
from tkinter_ui import user_interface,getcontact,getlist,getquestion
import webbrowser
import tkinter as tk
from tkinter import messagebox


def menu():
    print("========== Menu =============")
    print("1 >> Visualizar perguntas")
    print("2 >> Enviar pergunta")
    print("0 >> Sair")


while True:
    menu()
    opcao_menu = int(input("Opcao: "))

    if(opcao_menu == 0):
        quit()

    if opcao_menu == 1:
        num_view_file = int(input("Informe a lista: "))

        view_file(num_view_file)


    if opcao_menu == 2:

        try:
            user_interface()

            contact_label = getcontact()
            lista_label = getlist()
            question_label = getquestion()

            contact_label = contact_label.strip("\n")
            lista_label = int(lista_label)
            question_label = int(question_label)
            
            iniciar_automacao(contact_label,lista_label,question_label)

            quit()
                
        except ValueError:
            messagebox.showerror("Error", "Informacao invalida, programa encerrado...")

            print("\nErro de execucao")
            quit()