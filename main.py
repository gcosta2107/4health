from leitura_arquivos import leitura_frases
from leitura_arquivos import view_file
from automacao_whatsapp import enviar_pergunta
from automacao_whatsapp import selecionar_arquivo
from tkinter_ui import user_interface
from tkinter_ui import getcontact
from tkinter_ui import getlist
from tkinter_ui import getquestion
import webbrowser
import tkinter
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

            selecionar_arquivo(contact_label,int(lista_label),int(question_label))

            quit()
                
        except FileNotFoundError:
            print("Lista inexistente")