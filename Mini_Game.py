import tkinter as tk
from tkinter import simpledialog
from tkinter import messagebox
import random
import string
import time


def clear_screen():
    for widget in root.winfo_children():
        widget.destroy()

def start_game():
    clear_screen()

    while True:
        try:
            D = simpledialog.askinteger("Input", "How Difficult? ")
            if D is None:
                return
            if 4 <= D <= 10:
                break
            else:
                messagebox.showerror("Error", "Please enter a valid number between 4 and 10.")
        except ValueError:
            messagebox.showerror("Error", "Please enter a valid number between 4 and 10.")

    M = ''.join(random.choice(string.ascii_uppercase) for i in range(D))
    messagebox.showinfo("Vital Message", f"SEND MESSAGE: \n\n{M}")

    time.sleep(0.3 * D)
    clear_screen()

    N = simpledialog.askstring("Input", "Type the message you saw: ")
    if N == M:
        messagebox.showinfo("Result", "Message Correct\nThe war is over")
    else:
        messagebox.showinfo("Result", f"Wrong! \nShould've Input: \n{M}")

def quit_game():
    root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Message Game")
    root.geometry("400x300")

    start_button = tk.Button(root, text="Mulai game", command=start_game, font=("Helvetica", 16), width=15)
    start_button.pack(pady=20)

    quit_button = tk.Button(root, text="Quit Game", command=quit_game, font=("Helvetica", 16), width=15)
    quit_button.pack(pady=20)

    root.mainloop()
