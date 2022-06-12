import tkinter as tk
import webbrowser
from tkinter import messagebox, ttk
from leitura_arquivos import leitura_contatos


def getcontact():
    return contactString.get()

def getlist():
    return listString.get()

def getquestion():
    return questionString.get()

def AskPermission():
    #icon = error, info, question, or warning
    MsgBox = tk.messagebox.askquestion ('4health','Permissao para abrir whatsapp',icon = 'question')
    if MsgBox == 'yes':
        webbrowser.open('https://web.whatsapp.com/')
        app.destroy()
    else:
        messagebox.showinfo("Info", "Programa Encerrado")
        app.destroy()
        quit()

def center_window(window,width=300, height=200):
    screen_width = window.winfo_screenwidth()
    screen_height = window.winfo_screenheight()
    
    # calculate x and y coordinates for the Tk root window
    x = (screen_width/2) - (width/2)
    y = (screen_height/2) - (height/2)

    window.geometry('%dx%d+%d+%d' % (width, height, x, y - 50))

def user_interface():     
    global app
    global contactString
    global listString
    global questionString

    app = tk.Tk()
    
    app.title("4health")
    center_window(app,225, 225)
    app.focus_force()
    app.resizable(width=False, height=False)

    logo = tk.PhotoImage(file='./db/logo.png')
    labelLogo = tk.Label(app, image=logo)
    labelLogo.place(x=40,y=0)

    labelContact = tk.Label(app, text = "Contato")
    labelContact.place(x=5,y=100)

    labelList = tk.Label(app, text = "Lista")
    labelList.place(x=5,y=130)

    labelQuestion = tk.Label(app, text = "Pergunta")
    labelQuestion.place(x=5,y=160)

    contactString = tk.StringVar()
    entryContact = ttk.Combobox(app,values = leitura_contatos(),width=17, textvariable=contactString)
    entryContact.place(x=65,y=100)
    entryContact['state'] = 'readonly'

    listString = tk.StringVar()
    entryList = tk.Entry(app, width=20, textvariable=listString)
    entryList.place(x=65,y=130)

    questionString = tk.StringVar()
    entryQuestion = tk.Entry(app, width=20, textvariable=questionString)
    entryQuestion.place(x=65,y=160)

    resultButton = tk.Button(app, text = 'Enviar', command=AskPermission)
    resultButton.place(x=5,y=190)

    app.mainloop()