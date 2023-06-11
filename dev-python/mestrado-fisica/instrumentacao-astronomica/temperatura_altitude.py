#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

import numpy as np
import matplotlib.pyplot as plt

# Diagrama de temperatura na atmofera da Terra

# Constantes

r = 6.371 * 10**(6) # [m] -- Raio da Terra
g0 = 9.8 # [m/s**2]
lat = 0. # Aproximação: Linha do Equador
beta = 5.3 * 10**(-3) # Parâmetro que leva em conta a rotação terrestre em função do seu achatamento polar.

N0 = 6.023 * 10**(23) # [mol**-1] -- Número de Avogadro
kb = (1.381/(-272.15)) * 10**(-23) # [J/°C] -- Constante de Boltzmann
R = N0 * kb # Constante do Gás ideal [n=1]
Tm = 0.1 #273.15 # [K]
M0 = 4.8 * 10**(-26) # [kg] # 0.029 # [kg]
P0 = 101325 # 1 [atm]

# Aumentando a altitude
z = np.arange(0., 9000., 1000.) # altitude [metros]

# aceleração gravitacional em função da latitude, correção da rotação terrestre
g = g0 * ( 1 + beta * (np.sin(lat))**2 ) * (1 - ((2*z)/(r)))

# Parâmetro de escala de altura
H = ( (R*Tm)/(M0*g) )

# Modelo de Pressão Atmosférica
P = P0 * np.exp(-z/H)

# Volume atmosférico
V = (z)**(2) * 10**(-14) #(4/3) * np.pi * (r+z)**(3)

# P V = N0 kb T --> P V = R T
T = (V/R) * P

# Gráfico

fig, ax = plt.subplots()

ax.scatter(T, z, c='navy', s=10, alpha=1, label='Temperatura')
ax.legend()

ax.set_xlabel("T [°C]")
ax.set_ylabel("z [m]")

plt.grid()
#plt.title("title")

plt.show()
