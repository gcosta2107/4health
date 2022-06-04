from leitura_arquivos import leitura_frases
from leitura_arquivos import view_file
from automacao_whatsapp import enviar_pergunta
from automacao_whatsapp import selecionar_pergunta
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

        name = input("Nome do contato: ")
        num_file = int(input("Informe a lista: "))
        msg = int(input("Informe o numero da pergunta: "))

        messagebox.showinfo("Info", "Permissao para abrir whatsapp")

        try:
            chrome = webbrowser.get('C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s')
            chrome.open('https://web.whatsapp.com/')

            selecionar_pergunta(name,num_file,msg)

            quit()
                
        except FileNotFoundError:
            print("Lista inexistente")