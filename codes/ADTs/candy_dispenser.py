import tkinter as tk
from tkinter import ttk, messagebox
import random
import math

class CandyDispenserStack:
    def __init__(self, master):
        self.master = master
        self.master.title("Candy Dispenser Stack")
        self.master.geometry("500x700")
        self.master.resizable(False, False)
        self.master.configure(bg="#F0E6F6")

        self.stack = []
        self.max_candies = 10

        self.canvas = tk.Canvas(self.master, width=500, height=600, bg="#F0E6F6", highlightthickness=0)
        self.canvas.pack(pady=20)

        self.draw_dispenser()
        self.draw_spring()

        style = ttk.Style()
        style.theme_use('clam')
        style.configure('TButton', font=('Arial', 12), background="#9B59B6", foreground="white")

        self.button_frame = ttk.Frame(self.master, style="TFrame")
        self.button_frame.pack(pady=10)

        self.push_button = ttk.Button(self.button_frame, text="Push", command=self.push, style="TButton")
        self.push_button.grid(row=0, column=0, padx=10)

        self.pop_button = ttk.Button(self.button_frame, text="Pop", command=self.pop, style="TButton")
        self.pop_button.grid(row=0, column=1, padx=10)

        self.candy_colors = ["#FF69B4", "#FF6347", "#FF4500", "#FF8C00", "#FFD700", "#7CFC00", "#00FA9A", "#00CED1", "#1E90FF", "#8A2BE2"]

    def draw_dispenser(self):
        self.dispenser = self.canvas.create_rectangle(150, 50, 350, 550, fill="#E6E6FA", outline="#9B59B6", width=3)
        self.opening = self.canvas.create_arc(150, 20, 350, 100, start=0, extent=180, fill="#E6E6FA", outline="#9B59B6", width=3, style=tk.ARC)

    def draw_spring(self):
        self.spring_height = 100
        self.spring_width = 80
        self.spring_x = 250
        self.spring_y = 550
        self.spring = self.canvas.create_line(self.spring_x, self.spring_y, self.spring_x, self.spring_y - self.spring_height, smooth=True, width=3, fill="#9B59B6")
        self.update_spring()

    def update_spring(self):
        points = []
        coils = 40  # Increased number of coils for smoother appearance
        compressed = len(self.stack) / self.max_candies
        height = self.spring_height * (1 - 0.5 * compressed)

        for i in range(coils * 2 + 1):
            x = self.spring_x + self.spring_width / 2 * math.sin(math.pi * i / coils)
            y = self.spring_y - height * i / (coils * 2)
            points.extend([x, y])

        self.canvas.coords(self.spring, *points)

    def push(self):
        if len(self.stack) >= self.max_candies:
            messagebox.showerror("Error", "Stack is full! Cannot push more candies.")
            return

        candy_color = random.choice(self.candy_colors)
        candy = self.canvas.create_oval(200, 30, 300, 70, fill=candy_color, outline="black", width=2)
        self.stack.append(candy)
        self.animate_push(candy)

    def animate_push(self, candy):
        target_y = 530 - len(self.stack) * 40
        self.animate(candy, target_y)
        self.animate_spring_compress()

    def pop(self):
        if not self.stack:
            messagebox.showerror("Error", "Stack is empty! Cannot pop any candies.")
            return

        candy = self.stack.pop()
        self.animate_pop(candy)

    def animate_pop(self, candy):
        self.animate(candy, 0, delete=True)
        self.animate_spring_decompress()

    def animate(self, item, target_y, delete=False):
        current_y = self.canvas.coords(item)[1]
        if abs(current_y - target_y) > 1:
            dy = (target_y - current_y) / 10
            self.canvas.move(item, 0, dy)
            self.master.after(20, lambda: self.animate(item, target_y, delete))
        elif delete:
            self.canvas.delete(item)
        else:
            # Ensure candy is above the spring
            spring_top = self.spring_y - self.spring_height
            if current_y + 20 > spring_top:  # 20 is half the height of a candy
                self.canvas.move(item, 0, spring_top - (current_y + 20))

    def animate_spring_compress(self):
        current_height = self.spring_height
        target_height = max(50, 100 - len(self.stack) * 5)
        self.animate_spring(current_height, target_height)

    def animate_spring_decompress(self):
        current_height = self.spring_height
        target_height = max(50, 100 - (len(self.stack) - 1) * 5)
        self.animate_spring(current_height, target_height)

    def animate_spring(self, current_height, target_height):
        if abs(current_height - target_height) > 1:
            self.spring_height += (target_height - current_height) / 10
            self.update_spring()
            self.master.after(20, lambda: self.animate_spring(self.spring_height, target_height))
        else:
            self.spring_height = target_height
            self.update_spring()

if __name__ == "__main__":
    root = tk.Tk()
    app = CandyDispenserStack(root)
    root.mainloop()