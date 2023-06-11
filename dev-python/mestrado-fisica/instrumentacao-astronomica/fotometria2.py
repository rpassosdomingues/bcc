#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# LISTA 2: Técnicas Observacionais em Astrofísica -- Questão 2 (a)

# a) Calcular as magnitudes e cores instrumentais e depois, usando os coeficientes de
# extinção calculados no exercício 1, calcular as magnitudes e cores instrumentais fora da
# atmosfera.

# b) Usando os dados das estrelas-padrão da tabela fornecida, obter os coeficientes de
# transformação e transformar as magnitudes e cores instrumentais calculados no item 2a
# para o sistema padrão UBV.

import sys
import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.api as sm

def linearfit(x,y):

    # Linear Fit

    # create data
    df = pd.DataFrame({'instrumental': x, 'padrao': y})

    # fit simple linear regression model
    y = df['padrao']
    x = df[['instrumental']]
    x = sm.add_constant(x)
    model = sm.OLS(y, x).fit()

    # view model summary
    print('=' * 78)
    print(model.summary())

    # produce residual plots
    fig = plt.figure(figsize=(12, 8))
    fig = sm.graphics.plot_regress_exog(model, 'instrumental', fig=fig)

    plt.show()

    # regression part
    slope, intercept = model.params[1], model.params[0]

    line = slope * x + intercept
    plt.plot(x, line, 'r', label='y = {:.2f} * x + ({:.2f})'.format(slope, intercept))
    plt.legend(fontsize=15)

    # create scatterplot
    plt.scatter(df.instrumental, df.padrao, color='blue', s=50, alpha=.5)
    plt.title('extinction coefficient')
    plt.xlabel('instrumental')
    plt.ylabel('padrao')

    plt.show()

    return slope,intercept
"""
def magSTD(mag_v,mag_bv,mag_ub,X,alpha12_bv,alpha12_ub,bv,ub,intercept2_bv,intercept2_ub):

    # Usando coeficientes de primeira ordem calculados no exercício 1 - letra (b)
    slope1_v, intercept1_v = (0.31,-9.73)
    slope1_bv,intercept1_bv = (0.14,-0.48)
    slope1_ub, intercept1_ub = (0.41,1.34)

    alpha1_v = intercept1_v
    alpha1_bv = intercept1_bv + intercept2_bv
    alpha1_ub = intercept1_ub + intercept2_ub

    MAG_v = mag_v + slope1_v * X + alpha1_v
    MAG_bv = mag_bv + slope1_bv * X + alpha12_bv * bv * X + alpha1_bv
    MAG_ub = mag_ub + slope1_ub * X + alpha12_ub * ub * X + alpha1_ub

    return MAG_v,MAG_bv,MAG_ub

def colorindex(mag_v,mag_b,mag_u):
    bv = mag_b - mag_v
    ub = mag_u - mag_b
    return bv, ub

def magnitude(cte,fluxo_v,fluxo_b,fluxo_u):
    mag_v = -2.5 * np.log10(fluxo_v) + cte
    mag_b = -2.5 * np.log10(fluxo_b) + cte
    mag_u = -2.5 * np.log10(fluxo_u) + cte
    return mag_v,mag_b,mag_u

def flux(contagem_v,contagem_b,contagem_u,t_exposicao):
    fluxo_v = (contagem_v/t_exposicao)
    fluxo_b = (contagem_b/t_exposicao)
    fluxo_u = (contagem_u/t_exposicao)
    return fluxo_v,fluxo_b,fluxo_u
"""
def main(argv=None):
    """
    # Objetos do aglomerado aberto IC4665

    cte = 0. # Magnitude Instrumental

    # Contagens do Céu para diferentes tempos de exposição

    vsky1, bsky1, usky1 = (54, 93, 29)    # Contagens Sky: T = 1 [s]
    vsky2, bsky2, usky2 = (104, 170, 56)  # Contagens Sky: T = 2 [s]
    vsky4, bsky4, usky4 = (204, 332, 108) # Contagens Sky: T = 4 [s]
    vsky8, bsky8, usky8 = (400, 608, 200) # Contagens Sky: T = 8 [s]

    # Dados: Massa de ar, contagens v,b e u com céu subtraído e tempo de exposição

    X_A,v_A,b_A,u_A,texp_A = (1.353, 28871, 61625, 18546, 1)
    X_B,v_B,b_B,u_B,texp_B = (1.339, 14765, 32059, 9107, 1)

    X_G,v_G,b_G,u_G,texp_G = (1.320, 24974, 54924, 16518, 2)
    X_I,v_I,b_I,u_I,texp_I = (1.311, 21312, 20108, 1766, 2)
    X_J,v_J,b_J,u_J,texp_J = (1.313, 20670, 31818, 5778, 2)

    X_N,v_N,b_N,u_N,texp_N = (1.300, 27272, 15024, 460, 4)
    X_O,v_O,b_O,u_O,texp_O = (1.297, 26452, 21240, 1548, 4)
    X_P,v_P,b_P,u_P,texp_P = (1.288, 18096, 36660, 8408, 4)

    X_S,v_S,b_S,u_S,texp_S = (1.270, 22208, 38240, 5584, 8)
    X_U,v_U,b_U,u_U,texp_U = (1.269, 15008, 18720, 2784, 8)
    X_V,v_V,b_V,u_V,texp_V = (1.259, 11664, 23616, 4136, 8)
    X_W,v_W,b_W,u_W,texp_W = (1.247, 9968, 7664, 408, 8)

    # Fluxo -> t_exp = 1 [s]

    fluxo_v_A,fluxo_b_A,fluxo_u_A = flux(v_A,b_A,u_A,texp_A)
    fluxo_v_B,fluxo_b_B,fluxo_u_B = flux(v_B,b_B,u_B,texp_B)

    # Fluxo -> t_exp = 2 [s]

    fluxo_v_G, fluxo_b_G, fluxo_u_G = flux(v_G, b_G, u_G, texp_G)
    fluxo_v_I, fluxo_b_I, fluxo_u_I = flux(v_I, b_I, u_I, texp_I)
    fluxo_v_J, fluxo_b_J, fluxo_u_J = flux(v_J, b_J, u_J, texp_J)

    # Fluxo -> t_exp = 4 [s]

    fluxo_v_N, fluxo_b_N, fluxo_u_N = flux(v_N, b_N, u_N, texp_N)
    fluxo_v_O, fluxo_b_O, fluxo_u_O = flux(v_O, b_O, u_O, texp_O)
    fluxo_v_P, fluxo_b_P, fluxo_u_P = flux(v_P, b_P, u_P, texp_P)

    # Fluxo -> t_exp = 8 [s]

    fluxo_v_S, fluxo_b_S, fluxo_u_S = flux(v_S, b_S, u_S, texp_S)
    fluxo_v_U, fluxo_b_U, fluxo_u_U = flux(v_U, b_U, u_U, texp_U)
    fluxo_v_V, fluxo_b_V, fluxo_u_V = flux(v_V, b_V, u_V, texp_V)
    fluxo_v_W, fluxo_b_W, fluxo_u_W = flux(v_W, b_W, u_W, texp_W)

    # Magnitudes instrumentais nas bandas V,B e U

    mag_v_A,mag_b_A,mag_u_A = magnitude(cte,fluxo_v_A,fluxo_b_A,fluxo_u_A)
    mag_v_B, mag_b_B, mag_u_B = magnitude(cte, fluxo_v_B, fluxo_b_B, fluxo_u_B)

    mag_v_G, mag_b_G, mag_u_G = magnitude(cte, fluxo_v_G, fluxo_b_G, fluxo_u_G)
    mag_v_I, mag_b_I, mag_u_I = magnitude(cte, fluxo_v_I, fluxo_b_I, fluxo_u_I)
    mag_v_J, mag_b_J, mag_u_J = magnitude(cte, fluxo_v_J, fluxo_b_J, fluxo_u_J)

    mag_v_N, mag_b_N, mag_u_N = magnitude(cte, fluxo_v_N, fluxo_b_N, fluxo_u_N)
    mag_v_O, mag_b_O, mag_u_O = magnitude(cte, fluxo_v_O, fluxo_b_O, fluxo_u_O)
    mag_v_P, mag_b_P, mag_u_P = magnitude(cte, fluxo_v_P, fluxo_b_P, fluxo_u_P)

    mag_v_S, mag_b_S, mag_u_S = magnitude(cte, fluxo_v_S, fluxo_b_S, fluxo_u_S)
    mag_v_U, mag_b_U, mag_u_U = magnitude(cte, fluxo_v_U, fluxo_b_U, fluxo_u_U)
    mag_v_V, mag_b_V, mag_u_V = magnitude(cte, fluxo_v_V, fluxo_b_V, fluxo_u_V)
    mag_v_W, mag_b_W, mag_u_W = magnitude(cte, fluxo_v_W, fluxo_b_W, fluxo_u_W)

    # Cores instrumentais

    bv_A, ub_A = colorindex(mag_v_A, mag_b_A, mag_u_A)
    bv_B, ub_B = colorindex(mag_v_B, mag_b_B, mag_u_B)

    bv_G, ub_G = colorindex(mag_v_G, mag_b_G, mag_u_G)
    bv_I, ub_I = colorindex(mag_v_I, mag_b_I, mag_u_I)
    bv_J, ub_J = colorindex(mag_v_J, mag_b_J, mag_u_J)

    bv_N, ub_N = colorindex(mag_v_N, mag_b_N, mag_u_N)
    bv_O, ub_O = colorindex(mag_v_O, mag_b_O, mag_u_O)
    bv_P, ub_P = colorindex(mag_v_P, mag_b_P, mag_u_P)

    bv_S, ub_S = colorindex(mag_v_S, mag_b_S, mag_u_S)
    bv_V, ub_V = colorindex(mag_v_V, mag_b_V, mag_u_V)
    bv_U, ub_U = colorindex(mag_v_U, mag_b_U, mag_u_U)
    bv_W, ub_W = colorindex(mag_v_W, mag_b_W, mag_u_W)

    print("=" * 30)
    print("   \t(b-v) \t\t\t (B-V)")
    print("-" * 30)

    print("{0:12.4f}\t{1:12.4f}\n".format(bv_A, ub_A))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_B, ub_B))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_G, ub_G))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_I, ub_I))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_J, ub_J))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_N, ub_N))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_O, ub_O))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_P, ub_P))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_S, ub_S))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_V, ub_V))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_U, ub_U))
    print("{0:12.4f}\t{1:12.4f}\n".format(bv_W, ub_W))

    print("=" * 30)

    X = [X_A, X_B, X_G, X_I, X_J, X_N, X_O, X_P, X_S, X_U, X_V, X_W]

    v = [v_A, v_B, v_G, v_I, v_J, v_N, v_O, v_P, v_S, v_U, v_V, v_W]
    b = [b_A, b_B, b_G, b_I, b_J, b_N, b_O, b_P, b_S, b_U, b_V, b_W]
    u = [u_A, u_B, u_G, u_I, u_J, u_N, u_O, u_P, u_S, u_U, u_V, u_W]

    texp = [texp_A, texp_B, texp_G, texp_I, texp_J, texp_N, texp_O, texp_P, texp_S, texp_U, texp_V, texp_W]

    fluxo_v, fluxo_b, fluxo_u = flux(v, b, u, texp)

    mag_v, mag_b, mag_u = magnitude(cte, fluxo_v, fluxo_b, fluxo_u)
    bv, ub = colorindex(mag_v, mag_b, mag_u)

    print("=" * 30)
    print("Magnitudes Instrumentais")
    print("-" * 30)

    print("{0:12.4f}\t{1:12.4f}\n".format(mag_v, mag_b, mag_u))

    print("." * 30)
    print('\n')

    print("=" * 30)
    print("Cores Instrumentais")
    print("-" * 30)

    print("{0:12.4f}\t{1:12.4f}\n".format(bv, ub))

    print("=" * 30)
    """
    # LETRA B: Sistema Fotométrico Padrão

    BV = [0.011,0.002,-0.009,1.028,0.449,1.728]
    bv = [-0.8232,-0.8418,-0.8557,0.0631,-0.4683,0.6473]

    UB = [-0.54,-0.49,0.55,0.77,-0.01,2.08]
    ub = [1.3038,1.3664,1.3045,2.6409,1.8522,3.7851]

    # Coeficientes (slope,intercept) da lei de Bourguer

    gamma12_bv, beta12_bv = linearfit(bv, BV)
    gamma12_ub, beta12_ub = linearfit(ub, UB)

    print('=' * 78)
    print('Coeficientes')
    print('-' * 78)
    print('gamma12_bv = {0}'.format(gamma12_bv))
    print('beta12_bv = {0}'.format(beta12_bv))
    print('.' * 78)
    print('gamma12_ub = {0}'.format(gamma12_ub))
    print('beta12_ub = {0}'.format(beta12_ub))
    print('=' * 78)

    #MAG_v, MAG_bv, MAG_ub = magSTD(mag_v,mag_bv,mag_ub,X,gamma12_bv,gamma12_ub,bv,ub,beta12_bv,beta12_ub)

    return 0

if __name__ == "__main__":
    sys.exit(main())
