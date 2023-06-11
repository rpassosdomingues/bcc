#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# SLOAN DIGITAL SKY SURVEY
# SkyServer: http://skyserver.sdss.org/dr16/en/proj/advanced/spectraltypes/spectraltypeshome.aspx

import sys
import math
import numpy as np
import matplotlib.pyplot as plt

from math import exp, pi, sqrt, log10

def escaladeplaca(F):
    p = 1/F
    return p

def tamanhoimagem(F,theta):
    s = F * np.tan(theta)
    return s

def distanciafocal(f,D):
    F = f*D
    return F

def main(argv=None):

    # Constants

    f = np.arange(.1,10.,.1)
    theta = np.arange(.1,10.,.1)
    D = np.arange(.1,10.,.1)

    F = distanciafocal(f,D)
    s = tamanhoimagem(F,theta)
    p = escaladeplaca(F)

    fig, ax = plt.subplots()

    plt.plot(D, F, 'r-', label='focal-dist_diameter')
    plt.plot(f, F, 'g-', label='focal-ratio_focal-dist')
    plt.plot(F, p, 'b-', label='focal-dist_plaque-scale')
    plt.plot(f, p, 'r-', label='focal-ratio_plaque-scale')
    plt.plot(F, s, 'k-', label='size-image_dist-focal')
    plt.legend()

    ax.set_ylabel("y")
    ax.set_xlabel("x")

    plt.grid(True)

    ax.set_title("title")

    plt.show()

    return 0

if __name__ == "__main__":
    sys.exit(main())
