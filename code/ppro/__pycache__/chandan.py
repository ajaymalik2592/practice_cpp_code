import tkinter as tk

root = tk.Tk()
o = 0
s = ""
# file_name ki jangah apni file ka naam likhna
with open("file_name.txt", "r") as fil:
    for f in fil:
        o += 1
        s += f
T = tk.Text(root, height=o, width=100)
T.pack()
T.insert(tk.END, s)
tk.mainloop()
