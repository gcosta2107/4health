def leitura_frases(arquivo):
    try:
        file = open(arquivo,"r",encoding = "utf-8")
        lines = file.readlines()
        file.close()

        for i in range(len(lines)):
            lines[i] = lines[i].strip()

        return lines

    except FileNotFoundError:
        print("Arquivo inexistente!")

def leitura_contatos():

    var1 = open("./db/Contatos.txt", "r").readlines()

    data = []

    for line in var1:
        data.append(line)

    return data

def view_file(view_file):
    if (view_file == 1):
        frases = leitura_frases("./db/listapergunta1.txt")

        for i in range(len(frases)):
            print(f"{i+1}. {frases[i]}")
        
    elif (view_file == 2):
        frases = leitura_frases("./db/listapergunta2.txt")

        for i in range(len(frases)):
            print(f"{i+1}. {frases[i]}")

    elif (view_file == 3):
        frases = leitura_frases("./db/listapergunta3.txt")

        for i in range(len(frases)):
            print(f"{i+1}. {frases[i]}")

    elif (view_file == 4):
        frases = leitura_frases("./db/listapergunta4.txt")

        for i in range(len(frases)):
            print(f"{i+1}. {frases[i]}")