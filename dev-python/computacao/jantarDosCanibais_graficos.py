import threading
import time
import math
import matplotlib.pyplot as plt
import numpy as np

class Canibal:
    def __init__(self, nome, porcao_esquerda, porcao_direita, semaforo, mutex):
        self.nome = nome
        self.porcao_esquerda = porcao_esquerda
        self.porcao_direita = porcao_direita
        self.comendo = False
        self.semaforo = semaforo
        self.mutex = mutex

    def pegar_porcoes(self):
        while True:
            if not self.porcao_esquerda.is_comida() and not self.porcao_direita.is_comida():
                self.mutex.acquire()
                self.porcao_esquerda.pegar()
                self.porcao_direita.pegar()
                self.mutex.release()
                self.semaforo.acquire()
                break
            else:
                time.sleep(0.1)

    def liberar_porcoes(self):
        self.mutex.acquire()
        self.porcao_esquerda.liberar()
        self.porcao_direita.liberar()
        self.mutex.release()
        self.semaforo.release()

class PorcaoComida:
    def __init__(self):
        self.comida = False

    def is_comida(self):
        return self.comida

    def pegar(self):
        self.comida = True

    def liberar(self):
        self.comida = False

# Criação das porções de comida
porcoes_comida = [PorcaoComida() for _ in range(5)]

# Criação do semáforo
semaforo = threading.Semaphore(2)

# Criação do mutex
mutex = threading.Lock()

# Criação dos canibais
canibais = [
    Canibal('Canibal 1', porcoes_comida[0], porcoes_comida[1], semaforo, mutex),
    Canibal('Canibal 2', porcoes_comida[1], porcoes_comida[2], semaforo, mutex),
    Canibal('Canibal 3', porcoes_comida[2], porcoes_comida[3], semaforo, mutex)
]

ciclos = 1

# Simulação de ciclos
for _ in range(ciclos):
    for canibal in canibais:
        canibal.comendo = True
        time.sleep(1)
        canibal.comendo = False
        time.sleep(1)

# Configuração do gráfico
fig, (ax1, ax2) = plt.subplots(2, 1)

# Gráfico do uso do mutex e semáforo
time_wave = np.linspace(0, 2 * np.pi * ciclos, 1000)
waveform_mutex = np.ones_like(time_wave)
waveform_mutex[np.sin(3 * time_wave) < 0] = 0
waveform_semaforo = np.ones_like(time_wave)
waveform_semaforo[np.sin(2 * time_wave) < 0] = 0
ax1.plot(time_wave, waveform_mutex, label='Mutex')
ax1.plot(time_wave, waveform_semaforo, label='Semáforo')
ax1.set_xlabel('Tempo')
ax1.set_ylabel('Uso')
ax1.set_title('Uso do Mutex e Semáforo')
ax1.legend()

# Generate square waves for each cannibal
waveform1 = np.zeros_like(time_wave)
waveform1[np.sin(0.5 * time_wave) >= 0] = 1

waveform2 = np.zeros_like(time_wave)
waveform2[np.sin(1 * time_wave) >= 0] = 1

waveform3 = np.zeros_like(time_wave)
waveform3[np.sin(1.5 * time_wave) >= 0] = 1

# Gráfico dos canibais comendo/esperando
waveform_comendo = np.zeros_like(time_wave)
for i, canibal in enumerate(canibais):
    waveform = np.zeros_like(time_wave)
    waveform[np.sin((i + 1) * time_wave) >= 0] = 1
    waveform_comendo += waveform
ax2.plot(time_wave, waveform1, color='red', label='Canibal 1')
ax2.plot(time_wave, waveform2, color='green', label='Canibal 2')
ax2.plot(time_wave, waveform3, color='blue', label='Canibal 3')
ax2.set_xlabel('Tempo')
ax2.set_ylabel('Estado')
ax2.set_title('Estado dos Canibais')
ax2.legend()

# Exibição dos gráficos
plt.tight_layout()
plt.show()
