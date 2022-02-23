import socket
import tkinter as tk
from tkinter import messagebox
from tkinter.ttk import *
from tkinter import *

HOST = "192.168.237.1"
PORT = 65432
FORMAT = "utf8"

LARGE_FONT = ("verdana", 13, "bold")

LOGIN = 'login'
LOGOUT = 'logout'
SIGNUP = 'signup'
SEARCHDAY = 'searchday'
SEARCHGOLD = 'searchgold'
SEARCHCOMPANY = 'searchcompany'

GoldData = []


class GoldClient_App(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        self.title("Gold Client")
        self.geometry("500x200")
        self.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.resizable(width=False, height=False)

        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)

        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}
        for F in (ConnectPage, StartPage, SearchGold, SearchDay, SearchCompany):
            frame = F(container, self)

            self.frames[F] = frame

            frame.grid(row=0, column=0, sticky="nsew")

        self.showFrames(ConnectPage)

    def showFrames(self, container):
        frame = self.frames[container]
        if container == StartPage:
            self.geometry("500x200")
        elif container == ConnectPage:
            self.geometry("300x150")
        else:
            self.geometry("900x500")
        frame.tkraise()

    def on_closing(self):
        if messagebox.askokcancel("quit", "Do you want to quit?"):
            self.destroy()
            try:
                option = LOGOUT
                client.sendall(option.encode(FORMAT))

            except:
                pass

    def connect(self, curFrame, sck):
        try:
            global HOST
            HOST = curFrame.entry_ip.get()
            if HOST == "":
                curFrame.label_notice["text"] = "Ip cannot be empty"
                return
            try:
                sck.connect((HOST, PORT))
                # print("connect")
                self.showFrames(StartPage)
            except:
                curFrame.label_notice["text"] = "Server is not responding"

        except:
            pass

    def logIn(self, curFrame, sck):
        try:
            user = curFrame.entry_user.get()
            pswd = curFrame.entry_pswd.get()

            if user == "" or pswd == "":
                curFrame.label_notice["text"] = "fields cannot be empty"
                return

            option = LOGIN
            sck.sendall(option.encode(FORMAT))

            # print(user, pswd)
            sck.sendall(user.encode(FORMAT))
            sck.recv(1024)

            sck.sendall(pswd.encode(FORMAT))

            accepted = sck.recv(1024).decode(FORMAT)

            if accepted == "1":
                self.showFrames(SearchGold)

                curFrame.label_notice["text"] = ""
            elif accepted == "2":
                curFrame.label_notice["text"] = "invalid username or password"
            elif accepted == "0":
                curFrame.label_notice["text"] = "user already logged in"

        except:
            curFrame.label_notice["text"] = "Server is not responding"

    def signUp(self, curFrame, sck):

        # try:

        user = curFrame.entry_user.get()
        pswd = curFrame.entry_pswd.get()

        if pswd == "" or user == "":
            curFrame.label_notice["text"] = "flied cannot be empty"
            return

        option = SIGNUP
        sck.sendall(option.encode(FORMAT))

        sck.sendall(user.encode(FORMAT))
        sck.recv(1024)

        sck.sendall(pswd.encode(FORMAT))

        accepted = sck.recv(1024).decode(FORMAT)

        if accepted == "True":
            self.showFrames(SearchGold)
            curFrame.label_notice["text"] = ""
        else:
            curFrame.label_notice["text"] = "username already exists"

        # except:
        #     curFrame.label_notice["text"] = "Server is not responding"


class ConnectPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")

        label_title = tk.Label(self, text="CONNECT",
                               font=LARGE_FONT, fg="#20639b", bg="bisque2")

        label_ip = tk.Label(self, text="Ipaddress", fg="#20639b",
                            bg="bisque2", font="verdana 10 ")
        self.entry_ip = tk.Entry(self, width=20, bg="light yellow")
        self.label_notice = tk.Label(self, text="", bg="bisque2")

        button_conn = tk.Button(self, text="CONNECT", bg="#20639b",
                                fg="floral white", command=lambda: controller.connect(self, client))

        label_title.pack()
        label_ip.pack()
        self.entry_ip.pack()
        self.label_notice.pack()
        button_conn.pack()


class StartPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")

        label_title = tk.Label(self, text="LOG IN",
                               font=LARGE_FONT, fg="#20639b", bg="bisque2")
        label_user = tk.Label(self, text="username ",
                              fg="#20639b", bg="bisque2", font="verdana 10 ")
        label_pswd = tk.Label(self, text="password ",
                              fg="#20639b", bg="bisque2", font="verdana 10 ")

        self.label_notice = tk.Label(self, text="", bg="bisque2")
        self.entry_user = tk.Entry(self, width=20, bg="light yellow")
        self.entry_pswd = tk.Entry(self, width=20, bg="light yellow")

        button_log = tk.Button(self, text="LOG IN", bg="#20639b",
                               fg="floral white", command=lambda: controller.logIn(self, client))
        button_log.configure(width=10)
        button_sign = tk.Button(self, text="SIGN UP", bg="#20639b",
                                fg="floral white", command=lambda: controller.signUp(self, client))
        button_sign.configure(width=10)

        label_title.pack()
        label_user.pack()
        self.entry_user.pack()
        label_pswd.pack()
        self.entry_pswd.pack()
        self.label_notice.pack()

        button_log.pack()
        button_sign.pack()


class SearchGold(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")
        label_title = tk.Label(
            self, text="SEARCH GOLD", font=LARGE_FONT, fg="#20639b", bg="bisque2").pack()

        self.conent = tk.Frame(self)
        self.entry_search = tk.Entry(self, width=30, bg="light yellow")
        self.data = tk.Listbox(self.conent, height=15, width=75, bg="floral white",
                               activestyle="dotbox", font="Helvetical", fg="#20639b")
        self.label_notice = tk.Label(self, text="", bg="bisque2")

        button_search = tk.Button(self, text="SEARCH", bg="#20639b",
                                  fg="floral white", command=lambda: self.UpdateData(client))

        button_search_day = tk.Button(self, text="SEARCH DAY", bg="#20639b",
                                      fg="floral white", command=lambda: self.clearData(controller, SearchDay))
        button_search_company = tk.Button(self, text="SEARCH COMPANY", bg="#20639b",
                                          fg="floral white", command=lambda: self.clearData(controller, SearchCompany))

        self.entry_search.pack()
        self.label_notice.pack()
        button_search.pack()
        button_search_day.pack(side=BOTTOM)
        button_search_day.configure(width=15)
        button_search_company.pack(side=BOTTOM)
        button_search_company.configure(width=15)

        self.conent.pack_configure()
        self.scroll = tk.Scrollbar(self.conent)
        self.scroll.pack(side=RIGHT, fill=BOTH)
        self.data.config(yscrollcommand=self.scroll.set)

        self.scroll.config(command=self.data.yview)
        self.data.pack()

    def UpdateData(self, sck):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()

            option = SEARCHGOLD
            sck.sendall(option.encode(FORMAT))

            code = self.entry_search.get()
            if code == "":
                self.label_notice["text"] = "Flieds cannot be empty"
                return

            self.label_notice["text"] = ""
            sck.sendall(code.encode(FORMAT))

            n = int(sck.recv(1024).decode(FORMAT))
            sck.sendall(str(n).encode(FORMAT))
            # print(n)

            if n == 0:
                self.label_notice["text"] = "Not exists"
                return

            for i in range(n):
                x = str(sck.recv(1024).decode(FORMAT))
                sck.sendall(x.encode(FORMAT))
                GoldData.append(x)
                # print(x)
            # print(len(GoldData))
            for i in range(len(GoldData)):
                # print(GoldData[i])
                self.data.insert(i, GoldData[i])

        except:
            self.label_notice["text"] = "Server is not responding"

    def clearData(self, controller, frame):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()
            self.label_notice["text"] = ""
        except:
            pass

        controller.showFrames(frame)


class SearchDay(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")
        label_title = tk.Label(
            self, text="SEARCH DAY", font=LARGE_FONT, fg="#20639b", bg="bisque2").pack()

        self.conent = tk.Frame(self)
        self.entry_search = tk.Entry(self, width=30, bg="light yellow")
        self.data = tk.Listbox(self.conent, height=15, width=75, bg="floral white",
                               activestyle="dotbox", font="Helvetical", fg="#20639b")
        self.label_notice = tk.Label(self, text="", bg="bisque2")

        button_search = tk.Button(self, text="SEARCH", bg="#20639b",
                                  fg="floral white", command=lambda: self.UpdateData(client))

        button_search_gold = tk. Button(self, text="SEARCH GOLD", bg="#20639b",
                                        fg="floral white", command=lambda: self.clearData(controller, SearchGold))
        button_search_company = tk.Button(self, text="SEARCH COMPANY", bg="#20639b",
                                          fg="floral white", command=lambda: self.clearData(controller, SearchCompany))

        self.entry_search.pack()
        self.label_notice.pack()
        button_search.pack()
        button_search_gold.pack(side=BOTTOM)
        button_search_gold.configure(width=15)
        button_search_company.pack(side=BOTTOM)
        button_search_company.configure(width=15)

        self.conent.pack_configure()
        self.scroll = tk.Scrollbar(self.conent)
        self.scroll.pack(side=RIGHT, fill=BOTH)
        self.data.config(yscrollcommand=self.scroll.set)

        self.scroll.config(command=self.data.yview)
        self.data.pack()

    def UpdateData(self, sck):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()

            option = SEARCHDAY
            sck.sendall(option.encode(FORMAT))

            code = self.entry_search.get()
            if code == "":
                self.label_notice["text"] = "Flieds cannot be empty"
                return

            self.label_notice["text"] = ""
            sck.sendall(code.encode(FORMAT))

            n = int(sck.recv(1024).decode(FORMAT))
            sck.sendall(str(n).encode(FORMAT))
            # print(n)

            if n == 0:
                self.label_notice["text"] = "Not exists"
                return

            for i in range(n):
                x = str(sck.recv(1024).decode(FORMAT))
                sck.sendall(x.encode(FORMAT))
                GoldData.append(x)
                # print(x)
            # print(len(GoldData))
            for i in range(len(GoldData)):
                # print(GoldData[i])
                self.data.insert(i, GoldData[i])

        except:
            self.label_notice["text"] = "Server is not responding"

    def clearData(self, controller, frame):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()
            self.label_notice["text"] = ""
        except:
            pass

        controller.showFrames(frame)


class SearchCompany(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="bisque2")
        label_title = tk.Label(
            self, text="SEARCH COMPANY", font=LARGE_FONT, fg="#20639b", bg="bisque2").pack()

        self.conent = tk.Frame(self)
        self.entry_search = tk.Entry(self, width=30, bg="light yellow")
        self.data = tk.Listbox(self.conent, height=15, width=75, bg="floral white",
                               activestyle="dotbox", font="Helvetical", fg="#20639b")
        self.label_notice = tk.Label(self, text="", bg="bisque2")

        button_search = tk.Button(self, text="SEARCH", bg="#20639b",
                                  fg="floral white", command=lambda: self.UpdateData(client))

        button_search_gold = tk. Button(self, text="SEARCH GOLD", bg="#20639b",
                                        fg="floral white", command=lambda: self.clearData(controller, SearchGold))
        button_search_day = tk.Button(self, text="SEARCH DAY", bg="#20639b",
                                      fg="floral white", command=lambda: self.clearData(controller, SearchDay))

        self.entry_search.pack()
        self.label_notice.pack()
        button_search.pack()
        button_search_gold.pack(side=BOTTOM)
        button_search_gold.configure(width=15)
        button_search_day.pack(side=BOTTOM)
        button_search_day.configure(width=15)

        self.conent.pack_configure()
        self.scroll = tk.Scrollbar(self.conent)
        self.scroll.pack(side=RIGHT, fill=BOTH)
        self.data.config(yscrollcommand=self.scroll.set)

        self.scroll.config(command=self.data.yview)
        self.data.pack()

    def UpdateData(self, sck):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()

            option = SEARCHCOMPANY
            sck.sendall(option.encode(FORMAT))

            code = self.entry_search.get()
            if code == "":
                self.label_notice["text"] = "Flieds cannot be empty"
                return

            self.label_notice["text"] = ""
            sck.sendall(code.encode(FORMAT))

            n = int(sck.recv(1024).decode(FORMAT))
            sck.sendall(str(n).encode(FORMAT))
            # print(n)

            if n == 0:
                self.label_notice["text"] = "Not exists"
                return

            for i in range(n):
                x = str(sck.recv(1024).decode(FORMAT))
                sck.sendall(x.encode(FORMAT))
                GoldData.append(x)
                # print(x)
            # print(len(GoldData))
            for i in range(len(GoldData)):
                # print(GoldData[i])
                self.data.insert(i, GoldData[i])

        except:
            self.label_notice["text"] = "Server is not responding"

    def clearData(self, controller, frame):
        try:
            self.data.delete(0, len(GoldData))
            GoldData.clear()
            self.label_notice["text"] = ""
        except:
            pass

        controller.showFrames(frame)


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

app = GoldClient_App()

try:
    app.mainloop()

except:
    pass

finally:
    client.close()
