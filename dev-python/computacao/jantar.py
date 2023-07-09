import threading
import time
import math
import tkinter as tk

class Cannibal:
    def __init__(self, name, left_portion, right_portion):
        self.name = name
        self.left_portion = left_portion
        self.right_portion = right_portion
        self.eating = False

    def get_portions(self):
        while True:
            if not self.left_portion.is_eaten() and not self.right_portion.is_eaten():
                self.left_portion.get()
                self.right_portion.get()
                break
            else:
                time.sleep(0.1)

    def release_portions(self):
        self.left_portion.release()
        self.right_portion.release()

class Portion:
    def __init__(self):
        self.eaten = False
        self.lock = threading.Lock()

    def is_eaten(self):
        return self.eaten

    def get(self):
        self.lock.acquire()
        self.eaten = True

    def release(self):
        self.eaten = False
        self.lock.release()

# Creating food portions
portions = [Portion() for _ in range(5)]

# Creating cannibals
cannibals = [
    Cannibal('Cannibal 1', portions[0], portions[1]),
    Cannibal('Cannibal 2', portions[1], portions[2]),
    Cannibal('Cannibal 3', portions[2], portions[3]),
    Cannibal('Cannibal 4', portions[3], portions[4]),
    Cannibal('Cannibal 5', portions[4], portions[0])
]

# Dinner simulation thread
def simulate_dinner():
    while True:
        for cannibal in cannibals:
            cannibal.get_portions()
            cannibal.eating = True
            time.sleep(2)
            cannibal.release_portions()
            cannibal.eating = False
            time.sleep(2)

dinner_thread = threading.Thread(target=simulate_dinner)
dinner_thread.daemon = True
dinner_thread.start()

# GUI using tkinter to visualize the dinner
root = tk.Tk()
root.title("Cannibal Dinner")
canvas_width = 500
canvas_height = 500
canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg='white')
canvas.pack()

def draw_circle(x, y, radius, color):
    canvas.create_oval(x - radius, y - radius, x + radius, y + radius, fill=color)

def draw_kettle(x, y, radius, quantity):
    kettle_color = 'green' if quantity > 0 else 'red'
    canvas.create_oval(x - radius, y - radius, x + radius, y + radius, fill=kettle_color)
    canvas.create_text(x, y, text="Kettle", font=('Arial', 14))

def draw_legend():
    x_legend = canvas_width - 150
    y_legend = 30
    legend_offset = 25

    canvas.create_text(x_legend, y_legend, text="Legend:", font=('Arial', 14, 'bold'))

    for i, cannibal in enumerate(cannibals):
        y_text = y_legend + (i + 1) * legend_offset
        cannibal_color = 'black' if not cannibal.eating else 'green'
        canvas.create_oval(x_legend - 20, y_text - 10, x_legend, y_text + 10, fill=cannibal_color)
        canvas.create_text(x_legend + 15, y_text, text=cannibal.name, anchor=tk.W, font=('Arial', 12))

def update_interface():
    while True:
        canvas.delete('all')
        large_circle_radius = 200
        cannibal_circle_radius = large_circle_radius * 0.1
        kettle_radius = large_circle_radius * 0.4
        center_x = canvas_width // 2
        center_y = canvas_height // 2

        draw_circle(center_x, center_y, large_circle_radius, 'sandybrown')

        for i, cannibal in enumerate(cannibals):
            angle = i * (360 / 5)
            cannibal_x = center_x + large_circle_radius * 0.8 * math.cos(math.radians(angle))
            cannibal_y = center_y - large_circle_radius * 0.8 * math.sin(math.radians(angle))

            cannibal_color = 'black' if not cannibal.eating else 'green'
            draw_circle(cannibal_x, cannibal_y, cannibal_circle_radius, cannibal_color)

        food_quantity = sum(portion.is_eaten() for portion in portions)
        draw_kettle(center_x, center_y, kettle_radius, food_quantity)
        draw_legend()

        root.update()
        time.sleep(0.1)

interface_thread = threading.Thread(target=update_interface)
interface_thread.daemon = True
interface_thread.start()

# Function to start serving the kettle
def start_serving():
    for portion in portions:
        portion.get()

# Function to stop serving the kettle
def stop_serving():
    for portion in portions:
        portion.release()

# Button to start serving the kettle
start_button = tk.Button(root, text="Start Serving", command=start_serving)
start_button.pack()

# Button to stop serving the kettle
stop_button = tk.Button(root, text="Stop Serving", command=stop_serving)
stop_button.pack()

root.mainloop()
