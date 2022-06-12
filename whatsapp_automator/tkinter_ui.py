import tkinter as tk
import webbrowser
from tkinter import *
from tkinter import messagebox, ttk
from tkinter.ttk import Progressbar
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

def update_progressbar():

    theme_color='#249794'

    l4=Label(w,text='Loading...',fg='white',bg=theme_color)
    lst4=('Calibri (Body)',10)
    l4.config(font=lst4)
    l4.place(x=18,y=210)
    
    import time
    r=0
    for i in range(100):
        progress['value']=r
        w.update_idletasks()
        time.sleep(0.03)
        r=r+1
    
    w.destroy()
    user_interface()

def splash_screen():
    global w
    global progress
    
    w=Tk()
    w.resizable(False,False)
    w.focus_force()
    center_window(w,427,250)

    #customize progressbar
    s = ttk.Style()
    s.theme_use('clam')
    s.configure("red.Horizontal.TProgressbar", foreground='red', background='#4f4f4f')

    #place progressbar
    progress=Progressbar(w,style="red.Horizontal.TProgressbar",orient=HORIZONTAL,length=500,mode='determinate')  
    progress.place(x=-10,y=235)

    #theme color
    theme_color='#249794'

    Frame(w,width=427,height=241,bg=theme_color).place(x=0,y=0)
    b1=Button(w,width=10,height=1,text='Iniciar',command=update_progressbar,border=0,fg=theme_color,bg='white')
    b1.place(x=170,y=200)

    l1=Label(w,text='4HEALTH',fg='white',bg=theme_color)
    lst1=('Calibri (Body)',18,'bold')
    l1.config(font=lst1)
    l1.place(x=50,y=80)

    l3=Label(w,text='By group 4',fg='white',bg=theme_color)
    lst3=('Calibri (Body)',7)
    l3.config(font=lst3)
    l3.place(x=50,y=110)


    w.mainloop()

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

    logo = tk.PhotoImage(file='../db/logo.png')
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