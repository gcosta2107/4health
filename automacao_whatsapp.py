import pyautogui as auto
import time

#name = input("Nome do contato ")
#msg = input("\nMensagem a ser passada ")

def enviar_pergunta(name,msg):
    time.sleep(5)
    
    #move para o wpp e clica para buscar
    auto.moveTo(310, 267)
    time.sleep(2)
    auto.click()
    auto.write(name)

    #clica no primerio nome encontrado
    auto.moveTo(310, 370)
    time.sleep(2)
    auto.click()

    #clica na caixa de texto
    auto.moveTo(970, 1035)
    time.sleep(2)
    auto.click()
    auto.write(msg)
    auto.press("Enter")

    #apagar os "rastros"
    auto.moveTo(310, 267)
    time.sleep(2)
    auto.doubleClick()
    auto.press("Backspace")