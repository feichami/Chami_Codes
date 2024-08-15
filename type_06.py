import tkinter as tk
import random


class CatchTheBallGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Catch the Ball")
        self.root.resizable(False, False)

        self.canvas = tk.Canvas(self.root, width=600, height=400, bg="white")
        self.canvas.pack()

        self.score = 0
        self.speed = 1000
        self.ball = self.canvas.create_oval(50, 50, 100, 100, fill="red", outline="red")

        self.root.after(self.speed, self.update_ball_position)

        self.canvas.tag_bind(self.ball, "<Button-1>", self.catch_ball)

        self.score_label = tk.Label(self.root, text=f"Score: {self.score}", font=("Helvetica", 16))
        self.score_label.pack(pady=20)

    def update_ball_position(self):
        x = random.randint(50, 550)
        y = random.randint(50, 350)
        self.canvas.coords(self.ball, x, y, x + 50, y + 50)

        self.root.after(self.speed, self.update_ball_position)

    def catch_ball(self, event):
        self.score += 1
        self.speed = max(200, self.speed - 50)  # Kurangi waktu delay untuk meningkatkan kecepatan
        self.score_label.config(text=f"Score: {self.score}")


if __name__ == "__main__":
    root = tk.Tk()
    game = CatchTheBallGame(root)
    root.mainloop()
