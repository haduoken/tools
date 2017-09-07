from tkinter import *
class Application(Frame):
    def __init__(self,master=None):
        Frame.__init__(self,master)
        self.pack()
        self.creatWidgets()
    def creatWidgets(self):
        self.SearchButton =Button(self,text="Quit",command=self.show)
        self.SearchButton.pack()
        self.showCanvas=Canvas(width=200,height=100)
        self.showCanvas.pack()
    def show(self):
        self.showCanvas.create_text(80,80,text="hi, i am string", font="time 10 bold underline", tags="string")
app = Application()
app.master.title("hello world")
app.mainloop()
