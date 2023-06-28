import pandas as pd
import matplotlib.pyplot as plt

# Carregar dados do arquivo CSV
data = pd.read_csv('sort_usages.csv')

# Extrair colunas relevantes
sizes = data['Array Size']
randomBubbleUsages = data['Random Bubble Sort Usage']
increasingBubbleUsages = data['Increasing Bubble Sort Usage']
decreasingBubbleUsages = data['Decreasing Bubble Sort Usage']
randomInsertionUsages = data['Random Insertion Sort Usage']
increasingInsertionUsages = data['Increasing Insertion Sort Usage']
decreasingInsertionUsages = data['Decreasing Insertion Sort Usage']
randomSelectionUsages = data['Random Selection Sort Usage']
increasingSelectionUsages = data['Increasing Selection Sort Usage']
decreasingSelectionUsages = data['Decreasing Selection Sort Usage']

# Plotar gráfico de dispersão para Bubble Sort
plt.scatter(sizes, randomBubbleUsages, label='Random Bubble Sort')
plt.scatter(sizes, increasingBubbleUsages, label='Increasing Bubble Sort')
plt.scatter(sizes, decreasingBubbleUsages, label='Decreasing Bubble Sort')
plt.xlabel('Array Size')
plt.ylabel('Number of Usages')
plt.title('Bubble Sort Usages')
plt.legend()
plt.show()

# Plotar gráfico de dispersão para Insertion Sort
plt.scatter(sizes, randomInsertionUsages, label='Random Insertion Sort')
plt.scatter(sizes, increasingInsertionUsages, label='Increasing Insertion Sort')
plt.scatter(sizes, decreasingInsertionUsages, label='Decreasing Insertion Sort')
plt.xlabel('Array Size')
plt.ylabel('Number of Usages')
plt.title('Insertion Sort Usages')
plt.legend()
plt.show()

# Plotar gráfico de dispersão para Selection Sort
plt.scatter(sizes, randomSelectionUsages, label='Random Selection Sort')
plt.scatter(sizes, increasingSelectionUsages, label='Increasing Selection Sort')
plt.scatter(sizes, decreasingSelectionUsages, label='Decreasing Selection Sort')
plt.xlabel('Array Size')
plt.ylabel('Number of Usages')
plt.title('Selection Sort Usages')
plt.legend()
plt.show()
