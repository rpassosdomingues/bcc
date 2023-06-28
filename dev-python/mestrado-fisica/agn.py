import pandas as pd
import matplotlib.pyplot as plt

# File path for your dataset
#file_path = "<path_to_your_file>/your_file.csv"
file_path = "agn.csv"

# Read the CSV file
data = pd.read_csv(file_path, delimiter='\t')

# Extract relevant columns
black_hole_masses = data['logMBH[solMass]']
eddington_ratios = data['Column8']

# Perform any desired analysis or plotting using the extracted columns
# For example, let's plot the black hole masses against the eddington ratios
plt.scatter(black_hole_masses, eddington_ratios)
plt.xlabel('Black Hole Masses')
plt.ylabel('Eddington Ratios')
plt.title('Black Hole Masses vs. Eddington Ratios')
plt.show()
