import numpy as np
import matplotlib.pyplot as plt

def simulate_black_hole(mass, initial_position, initial_velocity, num_steps, time_step):
    G = 6.67430e-7  # Constante gravitacional

    positions = np.zeros((num_steps, 2))
    velocities = np.zeros((num_steps, 2))

    positions[0] = initial_position
    velocities[0] = initial_velocity

    for i in range(1, num_steps):
        acceleration = -G * mass * positions[i-1] / np.linalg.norm(positions[i-1])**3
        velocities[i] = velocities[i-1] + acceleration * time_step
        positions[i] = positions[i-1] + velocities[i] * time_step

    return positions

# Parâmetros da simulação
mass = 1e7  # Massa do buraco negro
initial_position = np.array([1.0, 0.0])  # Posição inicial do objeto
initial_velocity = np.array([0.0, 1.0])  # Velocidade inicial do objeto
num_steps = 1000  # Número de passos de simulação
time_step = 0.01  # Intervalo de tempo entre os passos

# Executar a simulação
positions = simulate_black_hole(mass, initial_position, initial_velocity, num_steps, time_step)

# Plotar o resultado
plt.plot(positions[:, 0], positions[:, 1])
plt.xlabel('Posição X')
plt.ylabel('Posição Y')
plt.title('Órbita em torno de um buraco negro')
plt.show()