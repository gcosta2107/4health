from leitura_arquivos import leitura_frases
from leitura_arquivos import view_file
from automacao_whatsapp import enviar_pergunta
from automacao_whatsapp import selecionar_pergunta
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

            contact = getcontact()
            lista = getlist()
            question = getquestion()

            selecionar_pergunta(contact,int(lista),int(question))

            quit()
                
        except FileNotFoundError:
            print("Lista inexistente")