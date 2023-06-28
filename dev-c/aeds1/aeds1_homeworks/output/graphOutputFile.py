import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV File
data = pd.read_csv("sort_usages.csv")

# Extract the data of columns
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

# Plot the graphics
plt.figure(figsize=(10, 9))

# Bubble Sort Graph
plt.subplot(3, 1, 1)
plt.plot(sizes, randomBubbleUsages, label="Random")
plt.plot(sizes, increasingBubbleUsages, label="Increasing")
plt.plot(sizes, decreasingBubbleUsages, label="Decreasing")
plt.title("Bubble Sort")
plt.xlabel("Array Size")
plt.ylabel("Number of Iterations")
plt.legend()

# Insertion Sort Graph
plt.subplot(3, 1, 2)
plt.plot(sizes, randomInsertionUsages, label="Random")
plt.plot(sizes, increasingInsertionUsages, label="Increasing")
plt.plot(sizes, decreasingInsertionUsages, label="Decreasing")
plt.title("Insertion Sort")
plt.xlabel("Array Size")
plt.ylabel("Number of Iterations")
plt.legend()

# Selection Sort Graph
plt.subplot(3, 1, 3)
plt.plot(sizes, randomSelectionUsages, label="Random")
plt.plot(sizes, increasingSelectionUsages, label="Increasing")
plt.plot(sizes, decreasingSelectionUsages, label="Decreasing")
plt.title("Selection Sort")
plt.xlabel("Array Size")
plt.ylabel("Number of Iterations")
plt.legend()

# space fit subplots
plt.tight_layout()

# Show the graphs
plt.show()
