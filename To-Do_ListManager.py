import tkinter as tk
from tkinter import messagebox

def tambah_tugas():
    task = task_entry.get()
    if task:
        task_listbox.insert(tk.END, task)
        task_entry.delete(0, tk.END)
    else:
        messagebox.showwarning("Warning", "You must enter a task.")

def del_task():
    try:
        task_index = task_listbox.curselection()[0]
        task_listbox.delete(task_index)
    except:
        messagebox.showwarning("Warning", "You must enter a task to delete.")

def clear_task():
    task_listbox.delete(0, tk.END)


root = tk.Tk()
root.title("To-Do List Manager")

frame = tk.Frame(root)
frame.pack(pady = 10)

task_entry = tk.Entry(frame, width= 40)
task_entry.pack(side=tk.LEFT, padx=10)

add_task_button = tk.Button(frame, text="Add Task", command= tambah_tugas)
add_task_button.pack(side=tk.LEFT)
task_listbox = tk.Listbox(root, width=50, height=10)
task_listbox.pack(pady=20)

button_frame = tk.Frame(root)
button_frame.pack(pady=10)

delete_task_button = tk.Button(button_frame, text="Delete Task", command=del_task)
delete_task_button.pack(side=tk.LEFT, padx=10)

clear_tasks_button = tk.Button(button_frame, text="Clear All Tasks", command=clear_task)
clear_tasks_button.pack(side=tk.LEFT)

root.mainloop()

