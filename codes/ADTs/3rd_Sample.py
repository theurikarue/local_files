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
        button_frame = tk.Frame(self.master, padx=10, pady=10)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        # First row of buttons
        push_btn = tk.Button(button_frame, text="Push", command=self.push_tablet,
                           bg="lime green", fg="white", activebackground="green", activeforeground="white")
        push_btn.pack(side=tk.LEFT, expand=True, padx=2)

        pop_btn = tk.Button(button_frame, text="Pop", command=self.pop_tablet,
                          bg="orange red", fg="white", activebackground="red", activeforeground="white")
        pop_btn.pack(side=tk.LEFT, expand=True, padx=2)

        # Create a second frame for the second row of buttons
        button_frame2 = tk.Frame(self.master, padx=10, pady=5)
        button_frame2.pack(side=tk.TOP, fill=tk.X)

        peek_btn = tk.Button(button_frame2, text="Peek", command=self.peek_tablet,
                           bg="deep sky blue", fg="white", activebackground="blue", activeforeground="white")
        peek_btn.pack(side=tk.LEFT, expand=True, padx=2)

        empty_btn = tk.Button(button_frame2, text="Is Empty", command=self.check_empty,
                            bg="purple", fg="white", activebackground="darkviolet", activeforeground="white")
        empty_btn.pack(side=tk.LEFT, expand=True, padx=2)

        self.canvas = tk.Canvas(self.master, width=300, height=650, bg="lightblue")
        self.canvas.pack(pady=20)

        self.draw_dispenser()

    def draw_dispenser(self):
        # Clear previous drawings
        self.canvas.delete("all")
        
        # Calculate center position for dispenser
        center_x = 150
        start_y = 100
        
        # Draw dispenser body
        self.canvas.create_rectangle(
            center_x - self.dispenser_width//2,
            start_y,
            center_x + self.dispenser_width//2,
            start_y + self.dispenser_height,
            fill="yellow",
            outline="black",
            width=2
        )
        
        # Draw tablets in the dispenser
        for i, tablet in enumerate(self.stack.items):
            tablet_y = start_y + self.dispenser_height - (i + 1) * self.tablet_height - 10
            self.canvas.create_rectangle(
                center_x - self.tablet_width//2,
                tablet_y,
                center_x + self.tablet_width//2,
                tablet_y + self.tablet_height - 5,
                fill="white",
                outline="black"
            )
            # Add letter label
            self.canvas.create_text(
                center_x,
                tablet_y + self.tablet_height//2 - 2,
                text=tablet,
                font=("Arial", 14, "bold")
            )
        
        # Draw dispenser head (top part)
        head_height = 80
        self.canvas.create_rectangle(
            center_x - self.dispenser_width//2 - 10,
            start_y - head_height,
            center_x + self.dispenser_width//2 + 10,
            start_y,
            fill="yellow",
            outline="black",
            width=2
        )
        
        # Draw Minion eyes
        eye_radius = 15
        eye_y = start_y - head_height//2
        # Left eye
        self.canvas.create_oval(
            center_x - 30 - eye_radius,
            eye_y - eye_radius,
            center_x - 30 + eye_radius,
            eye_y + eye_radius,
            fill="white",
            outline="black"
        )
        self.canvas.create_oval(
            center_x - 30 - 5,
            eye_y - 5,
            center_x - 30 + 5,
            eye_y + 5,
            fill="black"
        )
        # Right eye
        self.canvas.create_oval(
            center_x + 30 - eye_radius,
            eye_y - eye_radius,
            center_x + 30 + eye_radius,
            eye_y + eye_radius,
            fill="white",
            outline="black"
        )
        self.canvas.create_oval(
            center_x + 30 - 5,
            eye_y - 5,
            center_x + 30 + 5,
            eye_y + 5,
            fill="black"
        )

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

    def peek_tablet(self):
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
