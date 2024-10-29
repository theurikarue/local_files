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

    def peek(self):
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
        self.master.title("Minion PEZ Dispenser Stack")
        self.master.geometry("300x700")

        self.stack = TabletStack()
        self.dispenser_height = 450
        self.dispenser_width = 120
        self.tablet_height = 30
        self.tablet_width = 100

        self.create_widgets()

    def create_widgets(self):
        # Single button frame at the top
        button_frame = tk.Frame(self.master, padx=10, pady=10)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        # Left side buttons
        left_frame = tk.Frame(button_frame)
        left_frame.pack(side=tk.LEFT, expand=True)
        
        push_btn = tk.Button(left_frame, text="Push", command=self.push_tablet, 
                           bg="lime green", fg="white")
        push_btn.pack(side=tk.LEFT, padx=10)
        
        peek_btn = tk.Button(left_frame, text="Peek", command=self.show_peek, 
                           bg="deep sky blue", fg="white")
        peek_btn.pack(side=tk.LEFT, padx=10)

        # Right side buttons
        right_frame = tk.Frame(button_frame)
        right_frame.pack(side=tk.RIGHT, expand=True)
        
        pop_btn = tk.Button(right_frame, text="Pop", command=self.pop_tablet, 
                          bg="orange red", fg="white")
        pop_btn.pack(side=tk.RIGHT, padx=10)
        
        empty_btn = tk.Button(right_frame, text="Is Empty", command=self.check_empty, 
                            bg="purple", fg="white")
        empty_btn.pack(side=tk.RIGHT, padx=10)

        self.canvas = tk.Canvas(self.master, width=300, height=650, bg="lightblue")
        self.canvas.pack(pady=20)

        self.draw_dispenser()

    def draw_dispenser(self):
        self.canvas.delete("all")
        
        # Draw Minion head
        self.canvas.create_oval(75, 50, 225, 200, fill="yellow", outline="black")
        
        # Draw goggle
        self.canvas.create_oval(120, 90, 180, 150, fill="light gray", outline="black")
        self.canvas.create_oval(135, 105, 165, 135, fill="white", outline="black")
        self.canvas.create_oval(145, 115, 155, 125, fill="black")
        
        # Draw goggle strap
        self.canvas.create_rectangle(75, 115, 225, 125, fill="gray", outline="black")
        
        # Draw dispenser body
        x1, y1 = 90, 180
        x2, y2 = x1 + self.dispenser_width, y1 + self.dispenser_height
        self.canvas.create_rectangle(x1, y1, x2, y2, fill="blue", outline="black")
        
        # Calculate spring and tablets positions
        tablets_height = len(self.stack) * self.tablet_height
        spring_height = self.dispenser_height - tablets_height
        spring_top = y2 - spring_height
        spring_bottom = y2
        
        # Draw spring
        wave_height = 10
        num_waves = max(5, int(spring_height / (wave_height * 2)))
        for i in range(num_waves):
            y1_wave = spring_top + i * (spring_height / num_waves)
            y2_wave = y1_wave + wave_height
            self.canvas.create_arc(x1, y1_wave, x2, y2_wave, start=0, extent=180, style="arc", outline="red", width=2)
            if i < num_waves - 1:  # Don't draw the bottom part of the last wave
                self.canvas.create_arc(x1, y2_wave, x2, y2_wave + wave_height, start=180, extent=180, style="arc", outline="red", width=2)

        # Draw tablets (oval shape) from the bottom of the stack, just above the spring
        for i, tablet in enumerate(self.stack.items):
            y = spring_top - (i + 1) * self.tablet_height
            self.canvas.create_oval(x1 + 10, y, x1 + 10 + self.tablet_width, y + self.tablet_height, fill="white", outline="black")
            self.canvas.create_text(x1 + 60, y + self.tablet_height / 2, text=tablet, font=("Arial", 16, "bold"))
    
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

    def show_peek(self):
        try:
            top_tablet = self.stack.peek()
            messagebox.showinfo("Peek", f"Top tablet is {top_tablet}")
        except IndexError as e:
            messagebox.showerror("Error", str(e))

    def check_empty(self):
        if self.stack.is_empty():
            messagebox.showinfo("Stack Status", "Stack is empty")
        else:
            messagebox.showinfo("Stack Status", "Stack is not empty")

if __name__ == "__main__":
    root = tk.Tk()
    app = PEZDispenserGUI(root)
    root.mainloop()
