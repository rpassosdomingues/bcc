import threading
import time
import math
import tkinter as tk

class Filosofo:
    def __init__(self, nome, garfo_esquerda, garfo_direita):
        self.nome = nome
        self.garfo_esquerda = garfo_esquerda
        self.garfo_direita = garfo_direita
        self.comendo = False

    def pegar_garfos(self):
        while True:
            if not self.garfo_esquerda.is_usado() and not self.garfo_direita.is_usado():
                self.garfo_esquerda.pegar()
                self.garfo_direita.pegar()
                break
            else:
                time.sleep(0.1)

    def liberar_garfos(self):
        self.garfo_esquerda.liberar()
        self.garfo_direita.liberar()

class Garfo:
    def __init__(self):
        self.usado = False

    def is_usado(self):
        return self.usado

    def pegar(self):
        self.usado = True

    def liberar(self):
        self.usado = False

# Criação dos garfos
garfos = [Garfo() for _ in range(5)]

# Criação dos filósofos
filosofos = [
    Filosofo('Filósofo 1', garfos[0], garfos[1]),
    Filosofo('Filósofo 2', garfos[1], garfos[2]),
    Filosofo('Filósofo 3', garfos[2], garfos[3]),
    Filosofo('Filósofo 4', garfos[3], garfos[4]),
    Filosofo('Filósofo 5', garfos[4], garfos[0])
]

# Criação e início da thread de simulação do jantar
def simular_jantar():
    while True:
        for filosofo in filosofos:
            filosofo.pegar_garfos()
            filosofo.comendo = True
            time.sleep(2)
            filosofo.liberar_garfos()
            filosofo.comendo = False
            time.sleep(2)

thread_jantar = threading.Thread(target=simular_jantar)
thread_jantar.daemon = True
thread_jantar.start()

# Interface gráfica (usando tkinter) para visualização do jantar
root = tk.Tk()
root.title("Jantar dos Filósofos")
canvas_width = 500
canvas_height = 500
canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg='white')
canvas.pack()

def desenhar_circulo(x, y, raio, cor):
    canvas.create_oval(x - raio, y - raio, x + raio, y + raio, fill=cor)

def atualizar_interface():
    while True:
        canvas.delete('all')
        raio_circulo_grande = 200
        raio_circulo_filosofo = raio_circulo_grande * 0.1
        centro_x = canvas_width // 2
        centro_y = canvas_height // 2

        desenhar_circulo(centro_x, centro_y, raio_circulo_grande, 'gray')

        for i, filosofo in enumerate(filosofos):
            angulo = i * (360 / 5)
            x_filosofo = centro_x + raio_circulo_grande * 0.8 * math.cos(math.radians(angulo))
            y_filosofo = centro_y - raio_circulo_grande * 0.8 * math.sin(math.radians(angulo))

            cor_filosofo = 'green' if not filosofo.comendo else 'red'
            desenhar_circulo(x_filosofo, y_filosofo, raio_circulo_filosofo, cor_filosofo)

            x_garfo = centro_x + raio_circulo_grande * 0.9 * math.cos(math.radians(angulo))
            y_garfo = centro_y - raio_circulo_grande * 0.9 * math.sin(math.radians(angulo))

            if filosofo.garfo_esquerda.is_usado() and filosofo.garfo_direita.is_usado():
                canvas.create_text(x_garfo, y_garfo, text='X', font=('Arial', 14))
            elif filosofo.garfo_esquerda.is_usado() or filosofo.garfo_direita.is_usado():
                canvas.create_text(x_garfo, y_garfo, text='I', font=('Arial', 14))

        root.update()
        time.sleep(0.1)

thread_interface = threading.Thread(target=atualizar_interface)
thread_interface.daemon = True
thread_interface.start()

root.mainloop()
