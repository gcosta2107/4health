from leitura_arquivos import leitura_frases
from automacao_whatsapp import enviar_pergunta

name = input("Nome do contato: ")
num_file = int(input("Informe a lista: "))
msg = int(input("Informe o numero da pergunta: "))

try:
    if (num_file == 1):
        frases = leitura_frases("arquivos/listapergunta1.txt")
        pergunta_enviada = frases[msg - 1]
        enviar_pergunta(name,pergunta_enviada)
        
    elif (num_file == 2):
        frases = leitura_frases("arquivos/listapergunta1.txt")
        pergunta_enviada = frases[msg - 1]
        enviar_pergunta(name,pergunta_enviada)

    elif (num_file == 3):
        frases = leitura_frases("arquivos/listapergunta1.txt")
        pergunta_enviada = frases[msg - 1]
        enviar_pergunta(name,pergunta_enviada)

    elif (num_file == 4):
        frases = leitura_frases("arquivos/listapergunta1.txt")
        pergunta_enviada = frases[msg - 1]
        enviar_pergunta(name,pergunta_enviada)

except FileNotFoundError:
    print("Lista inexistente")