#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'


import sys
import numpy as np
import matplotlib.pyplot as plt

import scipy as sp
import pandas as pd
import statsmodels.api as sm

def concordance(database,measured):
    
    c = 1 - (database - measured)/100
    
    return c

def linearfit(X,Y):

    # Linear Fit

    # create data
    df = pd.DataFrame({'x': X, 'y': Y})

    # fit simple linear regression model
    y = df['y']
    x = df['x']
    x = sm.add_constant(x)
    model = sm.OLS(y, x).fit()

    # view model summary
    print('=' * 78)
    print(model.summary())

    # produce residual plots
    fig = plt.figure(figsize=(12, 8))
    fig = sm.graphics.plot_regress_exog(model, 'x', fig=fig)

    plt.show()

    # regression part
    slope, intercept = model.params[1], model.params[0]

    line = slope * x + intercept
    plt.plot(x, line, 'r', label='y = {:.2f}*X + ({:.2f})'.format(slope, intercept))
    plt.legend(fontsize=12)

    # create scatterplot
    plt.scatter(df.x, df.y, color='blue', s=50, alpha=.5)
    plt.title('Perfil de Brilho de De Vaucouleurs')
    plt.xlabel('$R^{1/4}$')
    plt.ylabel('$\mu$')

    plt.show()

    return slope,intercept

def main(argv=None):
    
    # Dados
    
    dados = pd.DataFrame(
    [[float(token) for token in line.split()]  
        for line in open("dados_ajuste.txt") if line.strip()],
     columns = ["sma", "intens"]
     )
    
    sma = np.array(dados['sma']) # X
    intens = np.array(dados['intens']) # Y
    
    # Conversões -- [px -> arcsec] & [nmgy -> Jy]
    sma = sma * (0.39597) # [arcsec]
    intens = intens * (3.631 * 10**(-6)) # [Jy]
    
    # Semieixos maiores ajustados, elevados a (1/4)
    R14 = sma**(.25) # R**(1/4) # [arcsec**(1/4)]
    
    # Brilho superficial
    mu = -2.5 * np.log10(intens)
    
    # --- --- ---
    
    # Coeficientes do ajuste
    slope, intercept = linearfit(R14,mu)

    print('\n')
    print('=' * 78)
    print('Coeficientes')
    print('-' * 78)
    print('slope = {0}'.format(slope))
    print('intercept = {0}'.format(intercept))
    print('=' * 78)
    print('\n')
    
    # --- --- ---
    
    # Resultados
    
    mu_0 = intercept
    I_0 = 10**(-(2/5) * intercept)
    
    # Magnitude Bolométrica do Sol
    # Ref: https://www.astro.princeton.edu/~gk/A403/constants.pdf
    Mbol_sun = 4.74
    
    I0 = 10**((Mbol_sun + 21.572 - mu_0)/(2.5)) # [L_sun]
    I_e = 10**(-3.33) * I_0
    
    alpha = ((2.5)/(slope * np.log(10)))**(4)
    R_eff = 3459 * alpha
    
    distance = 22.64 * 10**(3) # [kpc] # 22.64 +/- 1.62 [Mpc] (CMB)
    theta = R_eff * (4.84814 * 10**(-6)) # [rad]
    r = distance * np.sin(theta) # [kpc]
    
    R_opt = 2.5 * R_eff # Raio Óptico
    
    # Luminosidade
    
    n = 4 # galaxia eliptica
    j = 2*n
    fat = 1
    i = 2
    while i <= j:
        fat = fat*i
        i = i + 1

    L = fat * np.pi * I_0 * alpha**(2)
    
    # Área dos pixels
    A = (0.39597)**(2)
    
    # Brilho superficial efetivo
    mu_eff = 22.5 - 2.5 * np.log10(intens) + 2.5 * np.log10(A) # [mag/arcsec**2]
    
    print('=' * 78)
    print('Resultados')
    print('-' * 78)
    
    print('mu_0 = {0}'.format(mu_0))
    print('I_0 = {0}'.format(I_0))
    print('I0 = {0} [L_sun]'.format(I0))
    print('I_e = {0}'.format(I_e))
    
    print('alpha = {0}'.format(alpha))
    print('R_eff = {0} [kpc]'.format(R_eff))
    print('r = {0} [kpc]'.format(r))
    print('R_opt = {0} [kpc]'.format(R_opt))
    
    print('L = {0} [L_sun]'.format(L))
    
    print('mu_eff = {0} [mag/arcsec²]'.format(mu_eff))
    
    print('=' * 78)
    print('\n')
    
    # Concordance
    
    concordance_r = concordance(14.23/2,r)
    concordance_L = concordance(9.92E7,L)
    
    print('=' * 78)
    print('Concordância')
    print('-' * 78)
    
    print('concordance_raio = {0}'.format(concordance_r))
    print('concordance_Lumi = {0}'.format(concordance_L))
    
    print('=' * 78)
    print('\n')
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
