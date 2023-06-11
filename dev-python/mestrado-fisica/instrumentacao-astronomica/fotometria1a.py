#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# LISTA 2: Técnicas Observacionais em Astrofísica -- Questão 1 (a)

import sys
import numpy as np
import matplotlib.pyplot as plt

from math import log10

"""
def magSTD(alpha12, maglamb1, maglamb2, alpha1):
    magstd = maglamb1 + alpha12 * (maglamb1 - maglamb2) + alpha1
    return magstd

def colorcoef(lambda1,lambda2,lambdaS):
    alpha12 = (lambda1 - lambdaS)/(lambda2 - lambda1)
    return alpha12

def bouguer(k1,k2,X):
    bva = bv + k1 * X + k2 * bv * X
    return bva

def constants(m,X):
    k1 = (m - m0)/X
    k2 = (m - m0)/X
    return k1,k2

def maglamb(F):
    maglamb = -2.5 * log10(F)
    return maglmab

def colorindex(u,b,v):
    bv = b-v
    bu = b-u
    return bv,bu
    
def magitude(C):
    mag = -2.5 * log10(C) + cst
    return mag
"""

def airmass(lat,dec,H):
    X = (np.sin(lat) * np.sin(dec) + np.cos(lat) * np.cos(dec) * np.cos(H))**(-1)
    return X

def main(argv=None):

    # Constants

    latitude = 39.55 # North [deg]
    lat = (0.0174533) * latitude # [rad]

    RA,DEC = (2.12,40.38) # (hour,deg)
    ra, dec = (2.12 * 0.2617995, 40.38 * 0.0174533)  # [rad]

    # Sistema Fotométrico Padrão

    cst = 0.
    #C = V,B,U ?
    # mag = magnitude(V)

    alpha1 = 1.
    lambda1 = 1.
    lambda2 = 1.
    lambdaS = 1.

    F1 = 1.
    F2 = 1.

    # Tupla 1

    ha = []
    v = []
    b = []
    u = []

    dataset = None
    dataset = open('fotometria1a.dat', 'r')

    for line in dataset:
        HA, V, B, U = line.split(',')

        ha.append(float(HA))
        v.append(float(V))
        b.append(float(B))
        u.append(float(U))

    dataset.close()

    H1 = np.array(ha) # [hours]
    H = (0.2617995) * H1 # [rad]

    X = airmass(lat,dec,H)
    print("Airmass [X] = {0}".format(X))

    # Gráfico

    fig, ax = plt.subplots()

    #plt.plot(H1, X, 'b--', label='airmass X H [hours]')
    plt.plot(H, X, 'r--', label='airmass X H [rad]')
    plt.legend()

    ax.set_ylabel("X")
    ax.set_xlabel("H")

    #plt.grid(True)

    #ax.set_title("Title")

    plt.show()

    return 0

if __name__ == "__main__":
    sys.exit(main())
