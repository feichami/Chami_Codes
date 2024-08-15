
import tkinter as tk
from tkinter import simpledialog
from tkinter import messagebox

# using selection sort


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # menemukan elemen terkecil pada subarray yg belum urut
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # menukar elemen terkecuil dengan elemen pertama yg belum di urut
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def get_input():
    act = []
    root = tk.Tk()
    root.withdraw()

    angka_diurut = simpledialog.askinteger("Input", "Masukkan Banyak Angka yang Ingin di Urut:")
    for _ in range(angka_diurut):
        number = simpledialog.askinteger("Input", "masukkan angka yang ingin diurut: ")
        act.append(number)

    return act

    # arr = list(map(int, start_time.split()))
    # return arr


def display_output(sorted_activities):
    # print("Daftar angka yang sudah diurut: ", arr)
    hasil = "angka yang telah diurutkan: \n"
    for number in sorted_activities:
        hasil += f"{number} "
    messagebox.showinfo("Hasil Pengurutan", hasil)


def main():

    numbers = get_input()

    sorted_arr = selection_sort(numbers)

    display_output(sorted_arr)


if __name__ == "__main__":
    main()
