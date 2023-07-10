import pandas as pd
import matplotlib.pyplot as plt

# Read the output file
data = pd.read_csv('ideal_semaphores.txt', header=None, names=['Número de canibais', 'Quantidade de mutex', 'Quantidade de semáforos'] + [f'Tempo de espera {i}' for i in range(1, 11)])

# Scatter plot: Number of cannibals vs. Wait time of (n-1) cannibals
plt.figure(figsize=(8, 6))
for i in range(2, data.shape[1]):
    plt.scatter(data['Número de canibais'], data[f'Tempo de espera {i-1}'], label=f'Canibal {i}')
plt.xlabel('Number of Cannibals')
plt.ylabel('Wait Time of (n-1) Cannibals')
plt.title('Number of Cannibals vs. Wait Time of (n-1) Cannibals')
plt.legend()
plt.show()

# Scatter plot: Number of cannibals vs. Mutex usage
plt.figure(figsize=(8, 6))
plt.scatter(data['Número de canibais'], data['Quantidade de mutex'])
plt.xlabel('Number of Cannibals')
plt.ylabel('Mutex Usage')
plt.title('Number of Cannibals vs. Mutex Usage')
plt.show()

# Scatter plot: Number of cannibals vs. Semaphore usage
plt.figure(figsize=(8, 6))
plt.scatter(data['Número de canibais'], data['Quantidade de semáforos'])
plt.xlabel('Number of Cannibals')
plt.ylabel('Semaphore Usage')
plt.title('Number of Cannibals vs. Semaphore Usage')
plt.show()

# Histograms: Mutex and Semaphore usage for each case
for i in range(2, data.shape[1]):
    plt.figure(figsize=(6, 4))
    plt.hist(data[f'Tempo de espera {i-1}'], bins=10)
    plt.xlabel('Wait Time')
    plt.ylabel('Frequency')
    plt.title(f'Wait Time Histogram for {i} Cannibals')
    plt.show()
