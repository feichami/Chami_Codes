import tkinter as tk
from tkinter import simpledialog
from tkinter import messagebox

# implementation of Greedy Algorithm

def activity_selection(activities):
    # Urutkan aktivitas berdasarkan waktu berakhir
    activities.sort(key=lambda x: x[1])

    # Pilih aktivitas pertama
    selected_activities = [activities[0]]
    last_end_time = activities[0][1]

    for activity in activities[1:]:
        if activity[0] >= last_end_time:
            selected_activities.append(activity)
            last_end_time = activity[1]

    return selected_activities

def get_activity_input():
    activities = []
    num_activities = simpledialog.askinteger("Input", "Masukkan jumlah aktivitas:")
    for _ in range(num_activities):
        start_time = simpledialog.askinteger("Input", "Masukkan waktu mulai:")
        end_time = simpledialog.askinteger("Input", "Masukkan waktu berakhir:")
        description = simpledialog.askstring("Input", "Masukkan deskripsi aktivitas:")
        activities.append((start_time, end_time, description))
    return activities

def show_selected_activities(selected_activities):
    result = "Aktivitas yang dipilih:\n"
    for activity in selected_activities:
        result += f"Mulai: {activity[0]}, Selesai: {activity[1]}, Deskripsi: {activity[2]}\n"
    messagebox.showinfo("Hasil Seleksi", result)

def main():
    root = tk.Tk()
    root.withdraw()  # Hide the root window

    activities = get_activity_input()
    selected_activities = activity_selection(activities)
    show_selected_activities(selected_activities)

if __name__ == "__main__":
    main()
