import threading
import time
import math
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy import stats

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
    food_portions = [FoodPortion() for _ in range(num_cannibals)]

    # Create semaphore
    semaphore = threading.Semaphore(num_cannibals - 1)

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

    # Capture synchronization data
    data = []
    for i, cannibal in enumerate(cannibals):
        for j in range(cycles):
            state = 'Eating' if cannibal.eating else 'Waiting'
            data.append({'Cannibal': cannibal.name, 'Cycle': j+1, 'State': state})

    # Create pandas DataFrame
    df = pd.DataFrame(data)

    # Calculate the ideal synchronization pattern
    ideal_pattern = np.repeat([1] + [0] * (num_cannibals - 1), cycles)
    df['Ideal'] = ideal_pattern[:len(df)]

    # Capture mutex usage data
    mutex_usage = []
    for i in range(cycles):
        mutex_usage.extend([1] * num_cannibals)
        mutex_usage.extend([0] * (num_cannibals - 1))

    # Capture semaphore usage data
    semaphore_usage = []
    for i in range(cycles):
        semaphore_usage.extend([1] * (num_cannibals - 1))
        semaphore_usage.append(0)

    # Add mutex and semaphore usage to the DataFrame
    df['Mutex'] = mutex_usage[:len(df)]
    df['Semaphore'] = semaphore_usage[:len(df)]

    # Perform linear regression for observed synchronization
    slope_obs, intercept_obs, r_value_obs, p_value_obs, std_err_obs = stats.linregress(df['Cycle'], df['State'].replace({'Eating': 1, 'Waiting': 0}))

    # Perform linear regression for ideal synchronization
    slope_ideal, intercept_ideal, r_value_ideal, p_value_ideal, std_err_ideal = stats.linregress(df['Cycle'], df['Ideal'])

    # Print linear regression results
    print('Observed Linear Regression Results:')
    print(f'Slope: {slope_obs}')
    print(f'Intercept: {intercept_obs}')
    print(f'R-value: {r_value_obs}')
    print(f'P-value: {p_value_obs}')
    print(f'Standard Error: {std_err_obs}')

    print('\nIdeal Linear Regression Results:')
    print(f'Slope: {slope_ideal}')
    print(f'Intercept: {intercept_ideal}')
    print(f'R-value: {r_value_ideal}')
    print(f'P-value: {p_value_ideal}')
    print(f'Standard Error: {std_err_ideal}')

    # Configure the plot
    fig, (ax1, ax2, ax3, ax4) = plt.subplots(4, 1, sharex=True)

    # Plot the usage of mutex
    ax1.plot(df['Cycle'], df['Mutex'], label='Mutex Usage')
    ax1.set_ylabel('Usage')
    ax1.set_title('Mutex Usage')

    # Plot the usage of semaphore
    ax2.plot(df['Cycle'], df['Semaphore'], label='Semaphore Usage')
    ax2.set_ylabel('Usage')
    ax2.set_title('Semaphore Usage')

    # Plot the state of cannibals
    cannibal_states = df.pivot(index='Cycle', columns='Cannibal', values='State')
    cannibal_colors = plt.cm.get_cmap('tab10', num_cannibals)
    for i, cannibal in enumerate(cannibals):
        ax3.plot(cannibal_states.index, cannibal_states[cannibal.name].replace({'Eating': 1, 'Waiting': 0}), label=cannibal.name, color=cannibal_colors(i))
    ax3.set_ylabel('State')
    ax3.set_title('Cannibal States')
    ax3.legend()

    # Plot the ideal synchronization pattern
    ax4.plot(df['Cycle'], df['Ideal'], label='Ideal')
    ax4.set_xlabel('Cycle')
    ax4.set_ylabel('State')
    ax4.set_title('Ideal Synchronization')

    # Display the plots
    plt.tight_layout()
    plt.show()

# Example usage with n cannibals and n cycles
num_cannibals = 10
cycles = 2
simulate_dinner(num_cannibals, cycles)
