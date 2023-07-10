import threading
import time
import numpy as np
import math
import pandas as pd
import matplotlib.pyplot as plt

class Caldeirao:
    def __init__(self):
        self.porcoes = 0
        self.mutex = threading.Lock()
        self.encher_caldeirao_sem = threading.Semaphore(0)
        self.servir_sem = threading.Semaphore(1)

    def servir_porcao(self):
        self.servir_sem.acquire()
        self.mutex.acquire()
        if self.porcoes > 0:
            self.porcoes -= 1
            print(f"Canibal {threading.currentThread().getName()} se serviu do caldeirão. Restam {self.porcoes} porção(es).")
        self.mutex.release()

        if self.porcoes == 0:
            self.encher_caldeirao_sem.release()

        time.sleep(1)  # Simula o tempo de comer

        self.servir_sem.release()

    def encher_caldeirao(self):
        self.encher_caldeirao_sem.acquire()
        self.mutex.acquire()
        self.porcoes = 5
        print(f"Cozinheiro encheu o caldeirão com {self.porcoes} porção(es).")
        self.mutex.release()

class Canibal(threading.Thread):
    def __init__(self, caldeirao, mutex_counter, semaphore_counter, time_waiting):
        super().__init__()
        self.caldeirao = caldeirao
        self.mutex_counter = mutex_counter
        self.semaphore_counter = semaphore_counter
        self.time_waiting = time_waiting

    def run(self):
        while True:
            self.caldeirao.servir_porcao()
            self.mutex_counter[self.getName()] += 1
            time.sleep(1)  # Tempo de atividades qualquer

            # Contabiliza o tempo de espera dos n-1 canibais
            start_time = time.time()
            self.time_waiting[self.getName()].wait()
            end_time = time.time()
            self.time_waiting[self.getName()].clear()
            elapsed_time = end_time - start_time

            print(f"Canibal {self.getName()} esperou {elapsed_time:.2f} segundos.")

class Cozinheiro(threading.Thread):
    def __init__(self, caldeirao):
        super().__init__()
        self.caldeirao = caldeirao

    def run(self):
        while True:
            self.caldeirao.encher_caldeirao()
            # Fazer outras atividades qualquer
            # ...

def main():
    num_canibal = 10  # Número máximo de canibais
    step_canibal = 1  # Incremento no número de canibais
    num_cycles = 3  # Número de ciclos

    mutex_counter = {}  # Contador de uso do mutex por canibal
    semaphore_counter = {}  # Contador de uso do semáforo por canibal
    time_waiting = {}  # Dicionário para armazenar o tempo de espera dos n-1 canibais

    caldeirao = Caldeirao()

    for i in range(1, num_canibal + 1):
        mutex_counter[f"Canibal {i}"] = 0
        semaphore_counter[f"Canibal {i}"] = 0
        time_waiting[f"Canibal {i}"] = threading.Event()

    data = []

    for num in range(1, num_canibal + 1, step_canibal):
        print(f"\n----- {num} canibais -----\n")

        canibais = []
        for i in range(num):
            canibal_thread = Canibal(caldeirao, mutex_counter, semaphore_counter, time_waiting)
            canibais.append(canibal_thread)

        cozinheiro_thread = Cozinheiro(caldeirao)

        for canibal_thread in canibais:
            canibal_thread.start()

        cozinheiro_thread.start()

        # Realiza o número de ciclos especificado
        for _ in range(num_cycles):
            time.sleep(2)  # Tempo de atividades qualquer

            # Atualiza o contador de uso do semáforo
            for canibal_thread in canibais:
                if canibal_thread.is_alive():
                    semaphore_counter[canibal_thread.getName()] += 1

            # Libera o tempo de espera dos n-1 canibais
            for canibal_thread in canibais:
                if canibal_thread.is_alive():
                    time_waiting[canibal_thread.getName()].set()

        # Aguardar as threads terminarem
        for canibal_thread in canibais:
            canibal_thread.join()

        cozinheiro_thread.join()

        # Imprime os resultados
        print("Resultados:")
        for canibal_thread in canibais:
            if canibal_thread.is_alive():
                print(f"{canibal_thread.getName()} ainda está executando.")
            else:
                print(f"{canibal_thread.getName()}: MutexUsage = {mutex_counter[canibal_thread.getName()]}, SemaphoreUsage = {semaphore_counter[canibal_thread.getName()]}")
                data.append([num, mutex_counter[canibal_thread.getName()], semaphore_counter[canibal_thread.getName()]])

        # Gera os gráficos
        if len(data) > 0:
            df = pd.DataFrame(data, columns=['Número de Canibais', 'Uso do Mutex', 'Uso do Semáforo'])

            # Scatter plot: Número de canibais vs. Uso do Mutex
            plt.figure(figsize=(8, 6))
            plt.scatter(df['Número de Canibais'], df['Uso do Mutex'])
            plt.xlabel('Número de Canibais')
            plt.ylabel('Uso do Mutex')
            plt.title('Número de Canibais vs. Uso do Mutex')
            plt.show()

            # Scatter plot: Número de canibais vs. Uso do Semáforo
            plt.figure(figsize=(8, 6))
            plt.scatter(df['Número de Canibais'], df['Uso do Semáforo'])
            plt.xlabel('Número de Canibais')
            plt.ylabel('Uso do Semáforo')
            plt.title('Número de Canibais vs. Uso do Semáforo')
            plt.show()

            # Histograma: Uso do Mutex para cada caso
            plt.figure(figsize=(8, 6))
            plt.hist(df['Uso do Mutex'], bins=range(df['Uso do Mutex'].max() + 2))
            plt.xlabel('Uso do Mutex')
            plt.ylabel('Frequência')
            plt.title('Histograma do Uso do Mutex')
            plt.show()

            # Histograma: Uso do Semáforo para cada caso
            plt.figure(figsize=(8, 6))
            plt.hist(df['Uso do Semáforo'], bins=range(df['Uso do Semáforo'].max() + 2))
            plt.xlabel('Uso do Semáforo')
            plt.ylabel('Frequência')
            plt.title('Histograma do Uso do Semáforo')
            plt.show()

if __name__ == '__main__':
    main()
