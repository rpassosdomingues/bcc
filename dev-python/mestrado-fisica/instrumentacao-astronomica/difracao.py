#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

import sys
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def main(argv=None):

    # Constantes

    m = 1.
    N = 1.

    I0 = 1.
    d = .5

    theta = np.arange(0.,2*np.pi,.01*np.pi)

    D = m/d*np.cos(theta)

    # Difração

    co = (1/m) * d * np.sin(theta)

    alpha = ((np.pi * D) / co) * np.sin(theta)
    beta = ((np.pi * d) / co) * np.sin(theta)

    I = I0 * (( np.sin(alpha)/alpha )**2) * (( np.sin(N*beta)/(N*beta) )**2)

    # Graph
    fig = plt.figure()

    #plt.scatter(theta, co, color='k')
    plt.scatter(theta, I, color='k')

    plt.xlabel('angle')
    plt.ylabel('wavelenght')

    plt.show()

    return 0

if __name__ == "__main__":
    sys.exit(main())
