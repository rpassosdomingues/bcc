import pandas as pd
import matplotlib.pyplot as plt

# Read the output file
data = pd.read_csv('ideal_semaphores.txt')

# Get the column names dynamically
column_names = data.columns.tolist()

# Scatter plot: Number of cannibals vs. Wait time of (n-1) cannibals
plt.figure(figsize=(8, 6))
plt.scatter(data[column_names[0]], data[column_names[3]])
plt.xlabel('Number of Cannibals')
plt.ylabel('Wait Time of (n-1) Cannibals')
plt.title('Number of Cannibals vs. Wait Time of (n-1) Cannibals')
plt.show()

# Scatter plot: Number of cannibals vs. Mutex usage
plt.figure(figsize=(8, 6))
plt.scatter(data[column_names[0]], data[column_names[1]])
plt.xlabel('Number of Cannibals')
plt.ylabel('Mutex Usage')
plt.title('Number of Cannibals vs. Mutex Usage')
plt.show()

# Scatter plot: Number of cannibals vs. Semaphore usage
plt.figure(figsize=(8, 6))
plt.scatter(data[column_names[0]], data[column_names[2]])
plt.xlabel('Number of Cannibals')
plt.ylabel('Semaphore Usage')
plt.title('Number of Cannibals vs. Semaphore Usage')
plt.show()

# Histograms: Mutex and Semaphore usage for each case
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.hist(data[column_names[1]], bins=range(data[column_names[1]].max() + 2))
plt.xlabel('Mutex Usage')
plt.ylabel('Frequency')
plt.title('Mutex Usage Histogram')

plt.subplot(1, 2, 2)
plt.hist(data[column_names[2]], bins=range(data[column_names[2]].max() + 2))
plt.xlabel('Semaphore Usage')
plt.ylabel('Frequency')
plt.title('Semaphore Usage Histogram')

plt.tight_layout()
plt.show()
