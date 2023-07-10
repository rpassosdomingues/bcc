import threading
import time
import math
import matplotlib.pyplot as plt
import numpy as np

class Cannibal:
    def __init__(self, name, left_portion, right_portion, semaphore, mutex):
        self.name = name
        self.left_portion = left_portion
        self.right_portion = right_portion
        self.eating = False
        self.semaphore = semaphore
        self.mutex = mutex

    def get_portions(self):
        while True:
            if not self.left_portion.is_eaten() and not self.right_portion.is_eaten():
                self.mutex.acquire()
                self.left_portion.take()
                self.right_portion.take()
                self.mutex.release()
                self.semaphore.acquire()
                break
            else:
                time.sleep(0.1)

    def release_portions(self):
        self.mutex.acquire()
        self.left_portion.release()
        self.right_portion.release()
        self.mutex.release()

class FoodPortion:
    def __init__(self):
        self.eaten = False

    def is_eaten(self):
        return self.eaten

    def take(self):
        self.eaten = True

    def release(self):
        self.eaten = False

def simulate_dinner(num_cannibals, cycles):
    # Create food portions
    food_portions = [FoodPortion() for _ in range(5)]

    # Create semaphore
    semaphore = threading.Semaphore(2)

    # Create mutex
    mutex = threading.Lock()

    # Create cannibals
    cannibals = []
    for i in range(num_cannibals):
        name = f'Cannibal {i+1}'
        left_portion = food_portions[i]
        right_portion = food_portions[(i+1) % num_cannibals]
        cannibal = Cannibal(name, left_portion, right_portion, semaphore, mutex)
        cannibals.append(cannibal)

    # Simulate cycles
    for _ in range(cycles):
        for cannibal in cannibals:
            cannibal.eating = True
            time.sleep(1)
            cannibal.eating = False
            time.sleep(1)

    # Configure the plot
    fig, (ax1, ax2) = plt.subplots(2, 1)

    # Plot the mutex and semaphore usage
    time_wave = np.linspace(0, 2 * np.pi * cycles, 1000)
    mutex_waveform = np.ones_like(time_wave)
    mutex_waveform[np.sin(3 * time_wave) < 0] = 0
    semaphore_waveform = np.ones_like(time_wave)
    semaphore_waveform[np.sin(2 * time_wave) < 0] = 0
    ax1.plot(time_wave, mutex_waveform, label='Mutex')
    ax1.plot(time_wave, semaphore_waveform, label='Semaphore')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Usage')
    ax1.set_title('Mutex and Semaphore Usage')
    ax1.legend()

    # Generate square waves for each cannibal
    waveforms = []
    for i in range(num_cannibals):
        waveform = np.zeros_like(time_wave)
        waveform[np.sin((i + 0.5) * time_wave) >= 0] = 1
        waveforms.append(waveform)

    # Plot the cannibals' eating/waiting states
    eating_waveform = np.zeros_like(time_wave)
    for waveform in waveforms:
        eating_waveform += waveform
    for i, waveform in enumerate(waveforms):
        ax2.plot(time_wave, waveform, label=f'Cannibal {i+1}')
    ax2.set_xlabel('Time')
    ax2.set_ylabel('State')
    ax2.set_title('Cannibals Eating/Waiting State')
    ax2.legend()

    # Display the plots
    plt.tight_layout()
    plt.show()

# Example usage with n cannibals and n cycles
num_cannibals = 3
cycles = 3
simulate_dinner(num_cannibals, cycles)
