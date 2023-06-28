import numpy as np
import matplotlib.pyplot as plt

def fractal_galaxies(x, y, size, angle, depth):
    if depth == 0:
        return

    x_end = x + size * np.sin(np.deg2rad(angle))
    y_end = y + size * np.cos(np.deg2rad(angle))
    
    # Plotar a galáxia
    plt.scatter(x_end, y_end, color='black', s=size)

    # Calcular os novos parâmetros para as galáxias filhas
    new_size = size * 0.8
    left_angle = angle + 30
    right_angle = angle - 30

    # Chamada recursiva para as galáxias filhas
    fractal_galaxies(x_end, y_end, new_size, left_angle, depth-1)
    fractal_galaxies(x_end, y_end, new_size, right_angle, depth-1)

# Configurações iniciais
depth = 8  # Profundidade da árvore
size = 100  # Tamanho inicial das galáxias
angle = 90  # Ângulo inicial

# Criar a figura
fig, ax = plt.subplots()

# Chamar a função fractal_galaxies para desenhar as galáxias
fractal_galaxies(0, 0, size, angle, depth)

# Configurações do gráfico
ax.set_aspect('equal', adjustable='box')
ax.axis('off')

# Mostrar o gráfico
plt.show()
