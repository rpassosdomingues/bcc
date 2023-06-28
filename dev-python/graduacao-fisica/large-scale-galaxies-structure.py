import matplotlib.pyplot as plt

class SimulatedDensityField:
    def __init__(self, cdm_data, wdm_data):
        self.cdm_data = cdm_data
        self.wdm_data = wdm_data
        self.fig, self.ax = plt.subplots(1, 2, figsize=(10, 5))

    def plot_density_field(self):
        # Left panel: Cold Dark Matter
        ax1 = self.ax[0]
        ax1.imshow(self.cdm_data, cmap='viridis', origin='lower')
        ax1.set_title("Cold Dark Matter")
        ax1.set_xlabel("X-axis")
        ax1.set_ylabel("Y-axis")
        ax1.text(0.5, 1.1, "Simulated Density Field of Cold Dark Matter", ha="center", va="center", fontsize=12)
        ax1.text(0.5, 1.0, "Image adapted from [Reference]", ha="center", va="center", fontsize=10)

        # Right panel: Warm Dark Matter
        ax2 = self.ax[1]
        ax2.imshow(self.wdm_data, cmap='viridis', origin='lower')
        ax2.set_title("Warm Dark Matter")
        ax2.set_xlabel("X-axis")
        ax2.set_ylabel("Y-axis")
        ax2.text(0.5, 1.1, "Simulated Density Field of Warm Dark Matter", ha="center", va="center", fontsize=12)
        ax2.text(0.5, 1.0, "Image adapted from [Reference]", ha="center", va="center", fontsize=10)

        plt.tight_layout()
        plt.show()


# Define the simulated density field data for Cold Dark Matter (cdm) and Warm Dark Matter (wdm)
cdm_data = [[0.1, 0.2, 0.3],
            [0.4, 0.5, 0.6],
            [0.7, 0.8, 0.9]]

wdm_data = [[0.9, 0.8, 0.7],
            [0.6, 0.5, 0.4],
            [0.3, 0.2, 0.1]]

# Create an instance of the SimulatedDensityField class
sim_density_field = SimulatedDensityField(cdm_data, wdm_data)

# Plot the simulated density field of Cold Dark Matter and Warm Dark Matter
sim_density_field.plot_density_field()
