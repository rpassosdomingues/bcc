import threading
import time
import math
import tkinter as tk

class Canibal:
    def __init__(self, nome, porcao_esquerda, porcao_direita):
        self.nome = nome
        self.porcao_esquerda = porcao_esquerda
        self.porcao_direita = porcao_direita
        self.comendo = False

    def pegar_porcoes(self):
        while True:
            if not self.porcao_esquerda.is_comida() and not self.porcao_direita.is_comida():
                self.porcao_esquerda.pegar()
                self.porcao_direita.pegar()
                break
            else:
                time.sleep(0.1)

    def liberar_porcoes(self):
        self.porcao_esquerda.liberar()
        self.porcao_direita.liberar()

class PorcaoComida:
    def __init__(self):
        self.comida = False
        self.lock = threading.Lock()

    def is_comida(self):
        return self.comida

    def pegar(self):
        self.lock.acquire()
        self.comida = True

    def liberar(self):
        self.comida = False
        self.lock.release()

# Criação das porções de comida
porcoes_comida = [PorcaoComida() for _ in range(5)]

# Criação dos canibais
canibais = [
    Canibal('Canibal 1', porcoes_comida[0], porcoes_comida[1]),
    Canibal('Canibal 2', porcoes_comida[1], porcoes_comida[2]),
    Canibal('Canibal 3', porcoes_comida[2], porcoes_comida[3]),
    Canibal('Canibal 4', porcoes_comida[3], porcoes_comida[4]),
    Canibal('Canibal 5', porcoes_comida[4], porcoes_comida[0])
]

# Criação e início da thread de simulação do jantar
def simular_jantar():
    while True:
        for canibal in canibais:
            canibal.pegar_porcoes()
            canibal.comendo = True
            time.sleep(2)
            canibal.liberar_porcoes()
            canibal.comendo = False
            time.sleep(2)

thread_jantar = threading.Thread(target=simular_jantar)
thread_jantar.daemon = True
thread_jantar.start()

# Interface gráfica (usando tkinter) para visualização do jantar
root = tk.Tk()
root.title("Jantar dos Canibais")
canvas_width = 500
canvas_height = 500
canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg='white')
canvas.pack()

def desenhar_circulo(x, y, raio, cor):
    canvas.create_oval(x - raio, y - raio, x + raio, y + raio, fill=cor)

def desenhar_caldeirao(x, y, raio, quantidade):
    cor_caldeirao = 'green' if quantidade > 0 else 'red'
    canvas.create_oval(x - raio, y - raio, x + raio, y + raio, fill=cor_caldeirao)
    canvas.create_text(x, y, text="Caldeirão", font=('Arial', 14))

def desenhar_legenda():
    x_legenda = canvas_width - 150
    y_legenda = 30
    legenda_offset = 25

    canvas.create_text(x_legenda, y_legenda, text="Legenda:", font=('Arial', 14, 'bold'))

    for i, canibal in enumerate(canibais):
        y_text = y_legenda + (i + 1) * legenda_offset
        cor_canibal = 'black' if not canibal.comendo else 'green'
        canvas.create_oval(x_legenda - 20, y_text - 10, x_legenda, y_text + 10, fill=cor_canibal)
        canvas.create_text(x_legenda + 15, y_text, text=canibal.nome, anchor=tk.W, font=('Arial', 12))

def atualizar_interface():
    while True:
        canvas.delete('all')
        raio_circulo_grande = 200
        raio_circulo_canibal = raio_circulo_grande * 0.1
        raio_caldeirao = raio_circulo_grande * 0.4
        centro_x = canvas_width // 2
        centro_y = canvas_height // 2

        desenhar_circulo(centro_x, centro_y, raio_circulo_grande, 'sandybrown')

        for i, canibal in enumerate(canibais):
            angulo = i * (360 / 5)
            x_canibal = centro_x + raio_circulo_grande * 0.8 * math.cos(math.radians(angulo))
            y_canibal = centro_y - raio_circulo_grande * 0.8 * math.sin(math.radians(angulo))

            cor_canibal = 'black' if not canibal.comendo else 'green'
            desenhar_circulo(x_canibal, y_canibal, raio_circulo_canibal, cor_canibal)

        quantidade_comida = sum(porcao.is_comida() for porcao in porcoes_comida)
        desenhar_caldeirao(centro_x, centro_y, raio_caldeirao, quantidade_comida)
        desenhar_legenda()

        root.update()
        time.sleep(0.1)

thread_interface = threading.Thread(target=atualizar_interface)
thread_interface.daemon = True
thread_interface.start()

# Função para induzir o deadlock
def induzir_deadlock():
    for i in range(len(canibais)):
        canibal_atual = canibais[i]
        canibal_proximo = canibais[(i + 1) % len(canibais)]
        canibal_atual.porcao_direita.pegar()  # Tenta adquirir a porção de comida à direita
        time.sleep(0.1)  # Pequena espera para aumentar a chance de deadlock
        canibal_proximo.porcao_esquerda.pegar()  # Tenta adquirir a porção de comida à esquerda

# Botão para induzir o deadlock
botao_deadlock = tk.Button(root, text="Induzir Deadlock", command=induzir_deadlock)
botao_deadlock.pack()

root.mainloop()
