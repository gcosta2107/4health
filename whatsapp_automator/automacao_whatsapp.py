import pyautogui as auto
import time
from tkinter import messagebox
from leitura_arquivos import leitura_frases


def iniciar_automacao(name,num_file,msg):
    try:
        if (num_file == 1):
                frases = leitura_frases("./db/listapergunta1.txt")
                pergunta_enviada = frases[msg - 1]
                enviar_pergunta(name,pergunta_enviada)

        elif (num_file == 2):
            frases = leitura_frases("./db/listapergunta1.txt")
            pergunta_enviada = frases[msg - 1]
            enviar_pergunta(name,pergunta_enviada)

        elif (num_file == 3):
            frases = leitura_frases("./db/listapergunta1.txt")
            pergunta_enviada = frases[msg - 1]
            enviar_pergunta(name,pergunta_enviada)

        elif (num_file == 4):
            frases = leitura_frases("./db/listapergunta1.txt")
            pergunta_enviada = frases[msg - 1]
            enviar_pergunta(name,pergunta_enviada)
        else:
            messagebox.showerror("Error", "Informacao invalida, programa encerrado...")
            print("Lista nao encontrada!")
            quit()

    except IndexError:
        messagebox.showerror("Error", "Informacao invalida, programa encerrado...")
        print("Pergunta invalida!")
        quit()

def enviar_pergunta(name,msg):

    time.sleep(15)
   
    #move para o wpp e clica para buscar
    auto.moveTo(228, 180)
    time.sleep(2)
    auto.click()
    auto.write(name)

    #clica no primerio nome encontrado
    auto.moveTo(312, 261)
    time.sleep(2)
    auto.click()

    #clica na caixa de texto
    auto.moveTo(657, 691)
    time.sleep(2)
    auto.click()
    auto.write(msg)
    auto.press("Enter")

    #apagar os "rastros"
    auto.moveTo(228, 180)
    time.sleep(2)
    auto.doubleClick()
    auto.press("Backspace")