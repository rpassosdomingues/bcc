#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# LISTA 2: Técnicas Observacionais em Astrofísica -- Questão 1 (c)

# c) Foram observadas duas estrelas muito próximas, com diferentes índices de cor, e em
# vários ângulos zenitais. Estas estrelas são HD30544, com B-V = -0.06, e HD30545, com
# B-V=1.21. A partir destas observações obteve-se os dados do arquivo "fotometria1c.dat":

import sys
import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.api as sm

def linearfit(X, y, cor):

    # Linear Fit: Segunda Ordem

    # create data
    df = pd.DataFrame({'airmass': cor*X, 'ci': y})

    # fit simple linear regression model
    y = df['ci']
    x = df['airmass']
    x = sm.add_constant(x)
    model = sm.OLS(y, x).fit()

    # view model summary
    print('=' * 78)
    print(model.summary())

    # produce residual plots
    fig = plt.figure(figsize=(12, 8))
    fig = sm.graphics.plot_regress_exog(model, 'airmass', fig=fig)

    plt.show()

    # regression part
    slope, intercept = model.params[1], model.params[0]

    line = slope * x + intercept
    plt.plot(x, line, 'r', label='y = {:.2f}*x + ({:.2f})'.format(slope, intercept))
    plt.legend(fontsize=12)

    # create scatterplot
    plt.scatter(df.airmass, df.ci, color='blue', s=50, alpha=.5)
    plt.title('extinction coefficient: ordem 2')
    plt.xlabel('airmass')
    plt.ylabel('ci')

    plt.show()

    return slope,intercept

def main(argv=None):

    # Sistema Fotométrico Padrão

    cor1 = -0.06
    cor2 = 1.21

    cor = cor1 - cor2

    # Dados

    bv1 = [] # HD30544
    bv2 = [] # HD30545
    amass = [] # airmass

    dataset = None
    dataset = open('fotometria1c.dat', 'r')

    for line in dataset:
        BV1, BV2, AMASS = line.split(',')

        bv1.append(float(BV1))
        bv2.append(float(BV2))
        amass.append(float(AMASS))

    dataset.close()

    bv1 = np.array(bv1)
    bv2 = np.array(bv2)
    X = np.array(amass)

    # bv1 - bv2 = m0 + k2_bv * (cor1-cor2) * X # <<-------- Reta a ser ajustada
    # ci_12 = delta_m0 + k2_bv * (delta_cor) * X # <<-------- Reta a ser ajustada

    ybv = bv1 - bv2

    slope, intercept = linearfit(X,ybv,cor)

    print('=' * 78)
    print('Coeficientes de Segunda Ordem')
    print('-' * 78)
    print('k2_bv = {0}'.format(slope))
    print('delta_m-0 = {0}'.format(intercept))
    print('=' * 78)

    return 0

if __name__ == "__main__":
    sys.exit(main())
