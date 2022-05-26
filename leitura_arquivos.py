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