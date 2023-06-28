import pandas as pd
import matplotlib.pyplot as plt

# Ler o arquivo CSV
data = pd.read_csv("sort_usages.csv")

# Extrair os dados das colunas
sizes = data["Array Size"]
randomBubbleUsages = data["Random Bubble Sort Usage"]
increasingBubbleUsages = data["Increasing Bubble Sort Usage"]
decreasingBubbleUsages = data["Decreasing Bubble Sort Usage"]
randomInsertionUsages = data["Random Insertion Sort Usage"]
increasingInsertionUsages = data["Increasing Insertion Sort Usage"]
decreasingInsertionUsages = data["Decreasing Insertion Sort Usage"]
randomSelectionUsages = data["Random Selection Sort Usage"]
increasingSelectionUsages = data["Increasing Selection Sort Usage"]
decreasingSelectionUsages = data["Decreasing Selection Sort Usage"]

# Plotar os gráficos
plt.figure(figsize=(10, 6))

# Gráfico Bubble Sort
plt.subplot(2, 1, 1)
plt.plot(sizes, randomBubbleUsages, label="Random")
plt.plot(sizes, increasingBubbleUsages, label="Increasing")
plt.plot(sizes, decreasingBubbleUsages, label="Decreasing")
plt.title("Bubble Sort")
plt.xlabel("Array Size")
plt.ylabel("Number of Iterations")
plt.legend()

# Gráfico Insertion Sort
plt.subplot(2, 1, 2)
plt.plot(sizes, randomInsertionUsages, label="Random")
plt.plot(sizes, increasingInsertionUsages, label="Increasing")
plt.plot(sizes, decreasingInsertionUsages, label="Decreasing")
plt.title("Insertion Sort")
plt.xlabel("Array Size")
plt.ylabel("Number of Iterations")
plt.legend()

# Ajustar espaçamento entre os subplots
plt.tight_layout()

# Exibir os gráficos
plt.show()
