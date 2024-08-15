import tkinter as tk
from tkinter import simpledialog, messagebox

class Buku:
    def __init__(self, title, author, year):
        self.title = title
        self.author = author
        self.year = year
        self.is_checked_out = False

    def __str__(self):
        return f"'{self.title}' by {self.author} ({self.year})"

    def check_out(self):
        if not self.is_checked_out:
            self.is_checked_out = True
            messagebox.showinfo("Info", f"'{self.title}' has been checked out.")
        else:
            messagebox.showinfo("Info", f"'{self.title}' is already checked out.")

    def return_book(self):
        if self.is_checked_out:
            self.is_checked_out = False
            messagebox.showinfo("Info", f"'{self.title}' has been returned. ")
        else:
            messagebox.showinfo("Info", f"'{self.title}' was not checked out. ")

class Perpus:
    def __init__(self):
        self.buku = []

    def add_book(self, buku):
        self.buku.append(buku)
        messagebox.showinfo("Info", f"'{self.buku}' has been added to the library.")

    def list_books(self):
        if self.buku:
            messagebox.showinfo("Info", "Books in the Library: ")
            for buku in self.buku:
                status = "Checked out" if buku.is_checked_out else "Available"
                messagebox.showinfo("Info", f" - {buku} ({status}) ")
        else:
            messagebox.showerror("Error", "Kosong bolo")

    def find_book(self, title):
        for book in self.buku:
            if book.title.lower() == title.lower():
                return book
        return None

    def check_out_book(self, title):
        buku = self.find_book(title)
        if buku:
            buku.check_out()
        else:
            messagebox.showerror("Info", f"'{title}' not found in the library.")

    def return_book(self, title):
        book = self.find_book(title)
        if book:
            book.return_book()
        else:
            messagebox.showerror("Info", f"'{title}' not found in the library.")

def add_book(Perpus):
    title = simpledialog.askstring("Tambah Buku", "Masukkan judul buku:")
    author = simpledialog.askstring("Tambah Buku", "Masukkan pengarang buku:")
    year = simpledialog.askstring("Tambah Buku", "Masukkan tahun terbit buku:")
    if title and author and year:
        book = Buku(title, author, year)
        Perpus.add_book(book)

def list_books(Perpus):
    Perpus.list_books()

def check_out_book(Perpus):
    title = simpledialog.askstring("Check out Buku", "Masukkan judul buku yang akan di-check out:")
    if title:
        Perpus.check_out_book(title)

def return_book(Perpus):
    title = simpledialog.askstring("Kembalikan Buku", "Masukkan judul buku yang akan dikembalikan:")
    if title:
        Perpus.return_book(title)

def main():
    library = Perpus()

    root = tk.Tk()
    root.title("Menu Perpus")

    def on_button_click(choice):
        if choice == 1:
            add_book(library)
        elif choice == 2:
            list_books(library)
        elif choice == 3:
            check_out_book(library)
        elif choice == 4:
            return_book(library)
        elif choice == 5:
            root.quit()
        else:
            messagebox.showinfo("Error", "Pilihan tidak valid. Silakan pilih opsi yang valid.")

    options = [
        "1. Tambah Buku",
        "2. Daftar Buku",
        "3. Check out Buku",
        "4. Kembalikan Buku",
        "5. Keluar"
    ]

    for idx, option in enumerate(options, 1):
        button = tk.Button(root, text=option, command=lambda choice=idx: on_button_click(choice))
        button.pack(pady=5)

    root.mainloop()


if __name__ == "__main__":
    main()
