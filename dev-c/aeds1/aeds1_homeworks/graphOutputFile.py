import matplotlib.pyplot as plt

def load_data(filename):
    sizes = []
    bubble_usages = []
    insertion_usages = []
    selection_usages = []

    with open(filename, 'r') as file:
        lines = file.readlines()

        for line in lines[1:]:
            values = line.strip().split(',')
            sizes.append(int(values[0]))
            bubble_usages.append(int(values[1]))
            insertion_usages.append(int(values[2]))
            selection_usages.append(int(values[3]))

    return sizes, bubble_usages, insertion_usages, selection_usages

def plot_scatter(sizes, bubble_usages, insertion_usages, selection_usages):
    plt.scatter(sizes, bubble_usages, color='red', label='Bubble Sort')
    plt.scatter(sizes, insertion_usages, color='green', label='Insertion Sort')
    plt.scatter(sizes, selection_usages, color='blue', label='Selection Sort')

    plt.xlabel('Tamanho do Vetor')
    plt.ylabel('Utilização')
    plt.title('Utilização dos Métodos de Ordenação')
    plt.legend()
    plt.grid(True)
    plt.show()

filename = 'sort_usages.csv'
sizes, bubble_usages, insertion_usages, selection_usages = load_data(filename)
plot_scatter(sizes, bubble_usages, insertion_usages, selection_usages)
