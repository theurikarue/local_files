import tkinter as tk
from tkinter import messagebox

class TabletStack:
    def __init__(self):
        self.items = []
        self.max_size = 7
        self.next_label = 'A'

    def push(self):
        if len(self.items) < self.max_size:
            self.items.append(self.next_label)
            current_label = self.next_label
            self.next_label = chr(ord(self.next_label) + 1)
            if self.next_label > 'Z':
                self.next_label = 'A'
            return current_label
        else:
            raise IndexError("Stack is full")

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("Stack is empty")

    def top(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            raise IndexError("Stack is empty")

    def is_empty(self):
        return len(self.items) == 0

    def __len__(self):
        return len(self.items)

class PEZDispenserGUI:
    def __init__(self, master):
        self.master = master
        self.master.title("PEZ Dispenser Stack")
        self.master.geometry("300x600")

        self.stack = TabletStack()
        self.dispenser_height = 300
        self.dispenser_width = 100
        self.tablet_height = 30
        self.tablet_width = 80
        self.max_spring_height = 250
        self.min_spring_height = 50

        self.create_widgets()

    def create_widgets(self):
        button_frame = tk.Frame(self.master, padx=10, pady=10)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        push_btn = tk.Button(button_frame, text="Push", command=self.push_tablet)
        push_btn.pack(side=tk.LEFT, expand=True)

        pop_btn = tk.Button(button_frame, text="Pop", command=self.pop_tablet)
        pop_btn.pack(side=tk.LEFT, expand=True)

        top_btn = tk.Button(button_frame, text="Top", command=self.show_top)
        top_btn.pack(side=tk.LEFT, expand=True)

        self.canvas = tk.Canvas(self.master, width=300, height=500, bg="lightgray")
        self.canvas.pack(pady=20)

        self.draw_dispenser()

    def draw_dispenser(self):
        self.canvas.delete("all")
        
        # Draw dispenser body
        x1, y1 = 100, 50
        x2, y2 = x1 + self.dispenser_width, y1 + self.dispenser_height
        self.canvas.create_rectangle(x1, y1, x2, y2, fill="white", outline="black")
        
        # Calculate spring height based on number of tablets
        available_height = self.dispenser_height - (len(self.stack) * self.tablet_height)
        spring_height = max(self.min_spring_height, min(available_height, self.max_spring_height))
        
        # Draw spring
        spring_y = y2 - spring_height
        wave_height = 10
        wave_width = self.dispenser_width / 5
        for i in range(5):
            x1_wave = x1
            y1_wave = spring_y + i * wave_height * 2
            x2_wave = x2
            y2_wave = y1_wave + wave_height
            self.canvas.create_arc(x1_wave, y1_wave, x2_wave, y2_wave, start=0, extent=180, style="arc")
            if i < 4:  # Don't draw the bottom part of the last wave
                self.canvas.create_arc(x1_wave, y2_wave, x2_wave, y2_wave + wave_height, start=180, extent=180, style="arc")

        # Draw tablets (oval shape)
        for i, tablet in enumerate(reversed(self.stack.items)):
            y = spring_y - (i + 1) * self.tablet_height
            self.canvas.create_oval(110, y, 110 + self.tablet_width, y + self.tablet_height, fill="white", outline="black")
            self.canvas.create_text(150, y + self.tablet_height/2, text=tablet, font=("Arial", 16, "bold"))

    def push_tablet(self):
        try:
            label = self.stack.push()
            self.draw_dispenser()
            messagebox.showinfo("Push", f"Pushed tablet {label}")
        except IndexError as e:
            messagebox.showerror("Error", str(e))

    def pop_tablet(self):
        try:
            tablet = self.stack.pop()
            self.draw_dispenser()
            messagebox.showinfo("Pop", f"Popped {tablet}")
        except IndexError as e:
            messagebox.showerror("Error", str(e))

    def show_top(self):
        try:
            top_tablet = self.stack.top()
            messagebox.showinfo("Top", f"Top tablet is {top_tablet}")
        except IndexError as e:
            messagebox.showerror("Error", str(e))

if __name__ == "__main__":
    root = tk.Tk()
    app = PEZDispenserGUI(root)
    root.mainloop()
