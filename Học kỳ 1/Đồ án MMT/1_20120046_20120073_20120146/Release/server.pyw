import tkinter as tk
from tkinter import messagebox
from tkinter import *
from tkinter.ttk import *

import socket
import threading
import pyodbc
import json
import urllib.request
import time

LARGE_FONT = ("verdana", 13, "bold")

SERVER_NAME = "LAPTOP-U5PSRTAI\XUANCHIEN"
DATABASE_NAME = "SocketMmt"
USERNAME = "XUANCHIEN"
PASSWORD = "123456"

HOST = socket.gethostbyname(socket.gethostname())
PORT = 65432
FORMAT = 'utf8'

LOGIN = 'login'
LOGOUT = 'logout'
SIGNUP = 'signup'
SEARCHDAY = 'searchday'
SEARCHGOLD = 'searchgold'
SEARCHCOMPANY = 'searchcompany'

socketConnect = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketConnect.bind((HOST, PORT))
socketConnect.listen()

Live_Account = {}
DataList = []


def RequestData():
    while True:
        try:
            data = urllib.request.urlopen(
                "https://tygia.com/json.php?ran=0&rate=0&gold=1&bank=VIETCOM&date=now").read()
            output = json.loads(data)
        except:
            pass

        with open("data.json", "w", encoding=FORMAT) as outfile:
            json.dump(output["golds"][0]["value"], outfile,
                      indent=4, sort_keys=True, ensure_ascii=False)

        time.sleep(1800)


def ConnectToDB():
    server = SERVER_NAME
    database = DATABASE_NAME
    username = USERNAME
    password = PASSWORD
    cnxn = pyodbc.connect(
        "DRIVER={ODBC Driver 17 for SQL Server}; SERVER= " + server + "; Database=" + database + "; UID=" + username + "; PWD=" + password)
    cursor = cnxn.cursor()
    return cursor


def checkLiveAccount(username):

    for x in Live_Account:
        if Live_Account[x] == username:
            return False
    return True


def checkClientLogin(username, password):
    if checkLiveAccount(username) == False:
        return 0

    cursor = ConnectToDB()
    cursor.execute("SELECT pass FROM Account WHERE username = ?", username)
    pswd = cursor.fetchone()

    data_pswd = pswd[0]
    # print(data_pswd, password)
    if pswd != None:
        if data_pswd == password:
            return 1
    return 2


def clientLogin(sck, addr):

    user = sck.recv(1024).decode(FORMAT)

    sck.sendall(user.encode(FORMAT))

    pswd = sck.recv(1024).decode(FORMAT)

    accepted = checkClientLogin(user, pswd)
    if accepted == 1:

        Live_Account.update({str(addr): user})

    sck.sendall(str(accepted).encode(FORMAT))


def InsertNewAccount(username, password):
    cursor = ConnectToDB()
    cursor.execute("INSERT Account VALUES (?, ?)", (username, password))
    cursor.commit()


def checkClientSignUp(username):
    cursor = ConnectToDB()
    cursor.execute("SELECT pass FROM Account WHERE username = ?", username)
    password = cursor.fetchone()

    if password != None:
        return False
    return True


def clientSignUp(sck, addr):
    user = sck.recv(1024).decode(FORMAT)
    sck.sendall(user.encode(FORMAT))
    pswd = sck.recv(1024).decode(FORMAT)

    accepted = checkClientSignUp(user)
    sck.sendall(str(accepted).encode(FORMAT))

    # print(accepted)

    if accepted:
        InsertNewAccount(user, pswd)

        Live_Account.update({str(addr): user})


def Remove_LiveAccount(conn, addr):
    # print("closed")
    Live_Account.pop(str(addr))
    conn.sendall("True".encode(FORMAT))
    conn.close()


def sendList(Data, conn, addr):
    # print(len(Data))
    conn.sendall(str(len(Data)).encode(FORMAT))
    conn.recv(1024)
    # print(Data)

    x = {}
    for x in Data:
        # print(x)
        dat = x["code"] + " " + x["company"] + " --- buy: " + \
            x["buy"] + " --- sell: " + x["sell"] + \
            " --- Updated: " + x["updated"] + "  " + x["brand1"]
        # print(dat)
        conn.sendall(dat.encode(FORMAT))
        conn.recv(1024)
    # print("hi")


def SearchData(conn, addr):
    code = conn.recv(1024).decode(FORMAT)

    with open("data.json", "r", encoding=FORMAT) as infile:
        input = json.load(infile)

    for x in input:
        if x["code"] == code:
            DataList.append(x)

    sendList(DataList, conn, addr)
    DataList.clear()


def SearchDay(conn, addr):
    day = conn.recv(1024).decode(FORMAT)

    with open("data.json", "r", encoding=FORMAT) as infile:
        input = json.load(infile)

    for x in input:
        if x["day"] == day:
            DataList.append(x)

    sendList(DataList, conn, addr)
    DataList.clear()


def SearchCompany(conn, addr):
    company = conn.recv(1024).decode(FORMAT)

    with open("data.json", "r", encoding=FORMAT) as infile:
        input = json.load(infile)

    for x in input:
        if x["company"] == company:
            DataList.append(x)

    sendList(DataList, conn, addr)
    DataList.clear()


def handleClient(conn, addr):
    try:
        while True:
            option = conn.recv(1024).decode(FORMAT)
            # print(option)

            if option == LOGIN:
                clientLogin(conn, addr)

            elif option == SIGNUP:
                clientSignUp(conn, addr)

            elif option == LOGOUT:
                Remove_LiveAccount(conn, addr)
                return

            elif option == SEARCHGOLD:
                SearchData(conn, addr)

            elif option == SEARCHDAY:
                SearchDay(conn, addr)

            elif option == SEARCHCOMPANY:
                SearchCompany(conn, addr)

            option = ""

    except:
        try:
            Live_Account.pop(str(addr))
        except:
            pass
        conn.close()


def runServer():
    try:

        while True:
            conn, addr = socketConnect.accept()
            # print("conn", addr)

            clientThread = threading.Thread(
                target=handleClient, args=(conn, addr))
            clientThread.daemon = True
            clientThread.start()

    except:
        # print("Error")
        pass


class StartPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        self.configure(bg="bisque2")

        label_title = tk.Label(
            self, text="\nLOG IN FOR SERVER\n", font=LARGE_FONT, fg="#20639b", bg="bisque2").grid(row=0, column=1)

        laber_server = tk.Label(self, text="\tSERVER", fg="#20639b",
                                bg="bisque2", font="verdana 10 bold").grid(row=1, column=0)
        label_user = tk.Label(self, text="\tUSERNAME", fg="#20639b",
                              bg="bisque2", font="verdana 10 bold").grid(row=2, column=0)
        label_pswd = tk.Label(self, text="\tPASSWORD", fg="#20639b",
                              bg="bisque2", font="verdana 10 bold").grid(row=3, column=0)

        self.label_notice = tk.Label(self, text="", bg="bisque2", fg="red")
        self.entry_server = tk.Entry(self, width=30, bg="light yellow")
        self.entry_user = tk.Entry(self, width=30, bg="light yellow")
        self.entry_pswd = tk.Entry(self, width=30, bg="light yellow")

        button_log = tk.Button(self, text="LOG IN", bg="#20639b",
                               fg="floral white", command=lambda: controller.LogIn(self))

        button_log.grid(row=5, column=1)
        button_log.configure(width=10)
        self.label_notice.grid(row=4, column=1)
        self.entry_pswd.grid(row=3, column=1)
        self.entry_user.grid(row=2, column=1)
        self.entry_server.grid(row=1, column=1)


class HomePage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")
        label_title = tk.Label(self, text="\nACTIVE ACCOUNT ON SERVER\n",
                               font=LARGE_FONT, fg="#20639b", bg="bisque2").pack()
        label_host = tk.Label(self, text="HOST: " + str(
            HOST), fg="#20639b", bg="bisque2").pack()

        self.conent = tk.Frame(self)
        self.data = tk.Listbox(self.conent, height=10, width=40, bg='floral white',
                               activestyle='dotbox', font="Helvetical", fg="#20639b")

        button_back = tk.Button(self, text="BACK", bg="#20639b",
                                fg="floral white", command=lambda: controller.showFrame(StartPage))

        button_back.pack(side=BOTTOM)
        button_back.configure(width=10)

        self.conent.pack_configure()
        self.scroll = tk.Scrollbar(self.conent)
        self.scroll.pack(side=RIGHT, fill=BOTH)
        self.data.config(yscrollcommand=self.scroll.set)

        self.scroll.config(command=self.data.yview)
        self.data.pack()

        thr = threading.Thread(target=self.Update_Client)
        thr.daemon = True
        thr.start()

    def Update_Client(self):
        # try:
        while True:
            self.data.delete(0, len(Live_Account))
            for x in Live_Account:
                self.data.insert(END, x + "     " + Live_Account[x])

            time.sleep(5)
        # except:
        #     pass


class Gold_App(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        self.title("Gold Server")
        self.geometry("500x200")
        self.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.resizable(width=False, height=False)

        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)

        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}
        for F in (StartPage, HomePage):
            frame = F(container, self)

            self.frames[F] = frame

            frame.grid(row=0, column=0, sticky="nsew")

        self.showFrame(StartPage)

    def showFrame(self, container):

        frame = self.frames[container]
        if container == HomePage:
            self.geometry("500x350")
        else:
            self.geometry("500x200")
        frame.tkraise()

    def on_closing(self):
        if messagebox.askokcancel("Quit", "Do you want to quit"):
            self.destroy()

    def LogIn(self, curFrame):

        global SERVER_NAME, USERNAME, PASSWORD

        SERVER_NAME = curFrame.entry_server.get()
        USERNAME = curFrame.entry_user.get()
        PASSWORD = curFrame.entry_pswd.get()

        if PASSWORD == "":
            curFrame.label_notice["text"] = "password cannot be empty"
            return

        if USERNAME == "":
            curFrame.label_notice["text"] = "username cannot be empty"
            return

        if SERVER_NAME == "":
            curFrame.label_notice["text"] = "servername cannot be empty"
            return

        try:
            ConnectToDB()
            self.showFrame(HomePage)
            curFrame.label_notice["text"] = ""

        except:
            curFrame.label_notice["text"] = "invalid servername or username or password"


thre = threading.Thread(target=RequestData)
thre.daemon = True
thre.start()

thr = threading.Thread(target=runServer)
thr.daemon = True
thr.start()

app = Gold_App()
app.mainloop()
