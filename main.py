from leitura_arquivos import leitura_frases

name = input("Nome do contato: ")
num_file = int(input("Informe a lista: "))
msg = input("Informe o numero da pergunta: ")

try:
    if (num_file == 1):
        frases = leitura_frases("arquivos/listapergunta1.txt")
        print(frases)
        
    elif (num_file == 2):
        frases = leitura_frases("arquivos/listapergunta1.txt")

    elif (num_file == 3):
        frases = leitura_frases("arquivos/listapergunta1.txt")

    elif (num_file == 4):
        frases = leitura_frases("arquivos/listapergunta1.txt")

except FileNotFoundError:
    print("Lista inexistente")