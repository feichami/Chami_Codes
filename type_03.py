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

# Daftar aktivitas (waktu mulai, waktu berakhir, deskripsi)
activities = [
    (1, 4, "Menyapu lantai"),
    (3, 5, "Mencuci piring"),
    (0, 6, "Membersihkan kamar"),
    (5, 7, "Memasak makan malam"),
    (8, 9, "Menyiram tanaman"),
    (5, 9, "Mencuci baju")
]

# Panggil fungsi activity_selection
selected_activities = activity_selection(activities)

# Tampilkan aktivitas yang dipilih
print("Aktivitas yang dipilih:")
for activity in selected_activities:
    print(f"Mulai: {activity[0]}, Selesai: {activity[1]}, Deskripsi: {activity[2]}")
