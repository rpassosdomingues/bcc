import csv
import pandas as pd
import matplotlib.pyplot as plt

def main():
    
    sizes = []

    randomBubbleUsages = []
    increasingBubbleUsages = []
    decreasingBubbleUsages = []
    
    randomInsertionUsages = []
    increasingInsertionUsages = []
    decreasingInsertionUsages = []
    
    randomSelectionUsages = []
    increasingSelectionUsages = []
    decreasingSelectionUsages = []

    # Read the CSV File
    #file_path = "<path_to_your_file>/your_file.csv"
    #data = pd.read_csv(file_path)
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
    plt.scatter(sizes, randomBubbleUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingBubbleUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingBubbleUsages, marker='^', label="Decreasing")
    plt.title("Bubble Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Insertion Sort Graph
    plt.subplot(3, 1, 2)
    plt.scatter(sizes, randomInsertionUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingInsertionUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingInsertionUsages, marker='^', label="Decreasing")
    plt.title("Insertion Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Selection Sort Graph
    plt.subplot(3, 1, 3)
    plt.scatter(sizes, randomSelectionUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingSelectionUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingSelectionUsages, marker='^', label="Decreasing")
    plt.title("Selection Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Adjust subplots spacing
    plt.tight_layout()
   
    
    # Plot the graphics
    plt.figure(figsize=(10, 9))

    # Bubble Sort Graph
    plt.scatter(sizes, randomBubbleUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingBubbleUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingBubbleUsages, marker='^', label="Decreasing")
    plt.title("Bubble Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Adjust subplots spacing
    plt.tight_layout()

    # Show the first graph
    plt.show()

    # Plot the second graph
    plt.figure(figsize=(10, 9))

    # Insertion Sort Graph
    plt.scatter(sizes, randomInsertionUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingInsertionUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingInsertionUsages, marker='^', label="Decreasing")
    plt.title("Insertion Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Adjust subplots spacing
    plt.tight_layout()

    # Show the second graph
    plt.show()

    # Plot the third graph
    plt.figure(figsize=(10, 9))

    # Selection Sort Graph
    plt.scatter(sizes, randomSelectionUsages, marker='o', label="Random")
    plt.scatter(sizes, increasingSelectionUsages, marker='x', label="Increasing")
    plt.scatter(sizes, decreasingSelectionUsages, marker='^', label="Decreasing")
    plt.title("Selection Sort")
    plt.xlabel("Array Size")
    plt.ylabel("Number of Iterations")
    plt.legend()

    # Adjust subplots spacing
    plt.tight_layout()

    # Show the third graph
    plt.show()

# Run the main function
if __name__ == "__main__":
    main()
