import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

class KerrHorizon:
    def __init__(self, a, M, R_disco):
        self.a = a
        self.M = M
        self.R_disco = R_disco

    def calculate_horizon(self):
        theta = np.linspace(0, 2 * np.pi, 100)
        phi = np.linspace(0, np.pi, 100)
        theta, phi = np.meshgrid(theta, phi)
        r = 2 * self.M + np.sqrt((2 * self.M) ** 2 - self.a ** 2 * np.cos(theta) ** 2)
        x = r * np.sin(phi) * np.cos(theta)
        y = r * np.sin(phi) * np.sin(theta)
        z = r * np.cos(phi)
        return x, y, z

    def generate_accretion_disk(self):
        theta = np.linspace(0, 2 * np.pi, 100)
        r = np.linspace(0, self.R_disco, 100)
        theta, r = np.meshgrid(theta, r)
        x = r * np.sin(theta)
        y = r * np.cos(theta)
        z = np.zeros_like(x)
        return x, y, z

# Parâmetros do buraco negro de Kerr
a = 0.5  # Rotação
M = 1.0  # Massa
R_disco = 5.0  # Raio do disco de acreção

# Criar objeto do horizonte de eventos de Kerr
horizon = KerrHorizon(a, M, R_disco)

# Calcular coordenadas do horizonte de eventos e do disco de acreção
x_horizon, y_horizon, z_horizon = horizon.calculate_horizon()
x_disco, y_disco, z_disco = horizon.generate_accretion_disk()

# Plotar gráfico 3D com horizonte de eventos e disco de acreção
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot_surface(x_horizon, y_horizon, z_horizon, color='black', alpha=0.8)
ax.plot_surface(x_disco, y_disco, z_disco, color='red', alpha=0.5)

ax.set_xlabel('Eixo x')
ax.set_ylabel('Eixo y')
ax.set_zlabel('Eixo z')
ax.set_title('Horizonte de Eventos e Disco de Acreção de um Buraco Negro de Kerr')

plt.show()
