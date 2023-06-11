#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# LISTA 2: Técnicas Observacionais em Astrofísica -- Questão 1 (b)

import sys
import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.api as sm

def linearfit(X,y):

    # Linear Fit

    # create data
    df = pd.DataFrame({'airmass': X, 'mag': y})

    # fit simple linear regression model
    y = df['mag']
    x = df[['airmass']]
    x = sm.add_constant(x)
    model = sm.OLS(y, x).fit()

    # view model summary
    print('=' * 78)
    print(model.summary())

    # produce residual plots
    fig = plt.figure(figsize=(12, 8))
    fig = sm.graphics.plot_regress_exog(model, 'airmass', fig=fig)

    plt.show()

    # produce Q-Q plot
    # res = model.resid
    # fig = sm.qqplot(res, fit=True, line="45")

    # regression part
    slope, intercept = model.params[1], model.params[0]

    line = slope * x + intercept
    plt.plot(x, line, 'r', label='y = {:.2f}*x + ({:.2f})'.format(slope, intercept))
    plt.legend(fontsize=15)

    # create scatterplot
    plt.scatter(df.airmass, df.mag, color='blue', s=50, alpha=.5)
    plt.title('extinction coefficient')
    plt.xlabel('airmass')
    plt.ylabel('mag')

    # create boxplot
    # df.boxplot(column=['mag'])

    plt.show()

    return slope,intercept

def colorindex(mag_v,mag_b,mag_u):
    ci_bv = mag_b - mag_v
    ci_ub = mag_u - mag_b
    return ci_bv, ci_ub

def magnitude(cte,contagem):
    mag = -2.5 * np.log10(contagem) + cte
    return mag

def airmass(lat,dec,H):
    X = (np.sin(lat) * np.sin(dec) + np.cos(lat) * np.cos(dec) * np.cos(H))**(-1)
    return X

def main(argv=None):

    # Constantes

    cte = 0. # [Magnitude Instrumental]
    latitude = 39.55 # North [deg]
    lat = (0.0174533) * latitude # [rad]

    RA,DEC = (2.12,40.38) # (hour,deg)
    ra,dec = (2.12 * 0.2617995, 40.38 * 0.0174533)  # (hour,deg) --> [rad,rad]

    # Sistema Fotométrico Padrão

    # Dados

    ha = [] # ângulo horário [hours]
    v = []  # contagens [banda V]
    b = []  # contagens [banda B]
    u = []  # contagens [banda U]

    dataset = None
    dataset = open('fotometria1a.dat', 'r')

    for line in dataset:
        HA, V, B, U = line.split(',')

        ha.append(float(HA))
        v.append(float(V))
        b.append(float(B))
        u.append(float(U))

    dataset.close()

    # Matriz: Ângulo horário

    H = np.array(ha) # [hours]
    H = (0.2617995) * H # [rad] # >> Conversão de horas para radianos

    # Matriz: Massa de Ar

    X = airmass(lat,dec,H)
    #print("Airmass [X] = {0}".format(X))

    # Matrizes: Contagens nas bandas V,B e U

    V = np.array(v)
    B = np.array(b)
    U = np.array(u)

    # Magnitudes nas bandas V,B e U

    mag_v = magnitude(cte,V)
    mag_b = magnitude(cte,B)
    mag_u = magnitude(cte,U)

    # Índices de cor

    ci_bv, ci_ub = colorindex(mag_v,mag_b,mag_u)

    yv = mag_v
    ybv = ci_bv
    yub = ci_ub

    # y = yv # input("y = {[yv],[ybv],[yub]} (?): ") # <<<
    # y = m0 + k_v * X # <<-------- Reta a ser ajustada

    slope_v,   intercept_v = linearfit(X,yv)
    slope_bv, intercept_bv = linearfit(X,ybv)
    slope_ub, intercept_ub = linearfit(X,yub)

    print('=' * 78)
    print('Coeficientes')
    print('-' * 78)
    print('slope_v = {0}'.format(slope_v))
    print('intercept_v = {0}'.format(intercept_v))
    print('.' * 78)
    print('slope_bv = {0}'.format(slope_bv))
    print('intercept_bv = {0}'.format(intercept_bv))
    print('.' * 78)
    print('slope_ub = {0}'.format(slope_ub))
    print('intercept_ub = {0}'.format(intercept_ub))
    print('=' * 78)

    return 0

if __name__ == "__main__":
    sys.exit(main())
