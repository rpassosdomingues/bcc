import random
import csv
import pandas as pd
import matplotlib.pyplot as plt

# Function to perform Bubble Sort
def bubbleSort(array):
    length = len(array)
    bubbleUsage = 0
    for i in range(length - 1):
        for j in range(length - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
            bubbleUsage += 1
    return bubbleUsage

# Function to perform Insertion Sort
def insertionSort(array):
    length = len(array)
    insertionUsage = 0
    for i in range(1, length):
        handle = array[i]
        j = i - 1
        while j >= 0 and array[j] > handle:
            array[j + 1] = array[j]
            j -= 1
            insertionUsage += 1
        array[j + 1] = handle
    return insertionUsage

# Function to perform Selection Sort
def selectionSort(array):
    length = len(array)
    selectionUsage = 0
    for i in range(length - 1):
        minIndex = i
        for j in range(i + 1, length):
            if array[j] < array[minIndex]:
                minIndex = j
            selectionUsage += 1
        array[i], array[minIndex] = array[minIndex], array[i]
    return selectionUsage

# Function to generate random array
def randomArrayGenerator(start, length):
    array = list(range(start, start + length))
    random.shuffle(array)
    return array

# Function to save results to a CSV file
def saveResultsToFile(filename, sizes, randomBubbleUsages, increasingBubbleUsages, decreasingBubbleUsages, randomInsertionUsages, increasingInsertionUsages, decreasingInsertionUsages, randomSelectionUsages, increasingSelectionUsages, decreasingSelectionUsages):
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Array Size", "Random Bubble Sort Usage", "Increasing Bubble Sort Usage", "Decreasing Bubble Sort Usage",
                         "Random Insertion Sort Usage", "Increasing Insertion Sort Usage", "Decreasing Insertion Sort Usage",
                         "Random Selection Sort Usage", "Increasing Selection Sort Usage", "Decreasing Selection Sort Usage"])
        for i in range(len(sizes)):
            writer.writerow([sizes[i], randomBubbleUsages[i], increasingBubbleUsages[i], decreasingBubbleUsages[i],
                             randomInsertionUsages[i], increasingInsertionUsages[i], decreasingInsertionUsages[i],
                             randomSelectionUsages[i], increasingSelectionUsages[i], decreasingSelectionUsages[i]])

# Main function
def main():
    start = 10
    end = 1000
    step = 10
    numSizes = int((end - start) / step) + 1

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

    currentSize = start
    for i in range(numSizes):
        sizes.append(currentSize)
        currentSize += step

    for i in range(numSizes):
        length = sizes[i]

        # Random Array
        randomArray = randomArrayGenerator(1, length)

        sortArray = randomArray[:]
        bubbleUsage = bubbleSort(sortArray)
        randomBubbleUsages.append(bubbleUsage)

        sortArray = randomArray[:]
        insertionUsage = insertionSort(sortArray)
        randomInsertionUsages.append(insertionUsage)

        sortArray = randomArray[:]
        selectionUsage = selectionSort(sortArray)
        randomSelectionUsages.append(selectionUsage)

        # Increasing Array
        increasingArray = list(range(length))

        sortArray = increasingArray[:]
        bubbleUsage = bubbleSort(sortArray)
        increasingBubbleUsages.append(bubbleUsage)

        sortArray = increasingArray[:]
        insertionUsage = insertionSort(sortArray)
        increasingInsertionUsages.append(insertionUsage)

        sortArray = increasingArray[:]
        selectionUsage = selectionSort(sortArray)
        increasingSelectionUsages.append(selectionUsage)

        # Decreasing Array
        decreasingArray = list(range(length, 0, -1))

        sortArray = decreasingArray[:]
        bubbleUsage = bubbleSort(sortArray)
        decreasingBubbleUsages.append(bubbleUsage)

        sortArray = decreasingArray[:]
        insertionUsage = insertionSort(sortArray)
        decreasingInsertionUsages.append(insertionUsage)

        sortArray = decreasingArray[:]
        selectionUsage = selectionSort(sortArray)
        decreasingSelectionUsages.append(selectionUsage)

    # Save results to a file
    saveResultsToFile("sort_usages.csv", sizes, randomBubbleUsages, increasingBubbleUsages, decreasingBubbleUsages,
                      randomInsertionUsages, increasingInsertionUsages, decreasingInsertionUsages,
                      randomSelectionUsages, increasingSelectionUsages, decreasingSelectionUsages)

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
    
    """
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

    # Adjust subplots spacing
    plt.tight_layout()

    # Plot the graphics
    plt.figure(figsize=(10, 9))
    """

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
