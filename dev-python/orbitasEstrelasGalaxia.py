#!/usr/bin/python
# -*- coding: utf-8 -*-

# Simulation of Stellar Orbits in the Galaxy: An application of semi-empirical models to Universal Gravitation
# <https://doi.org/10.3390/mol2net-04-05868>
__author__ = 'Rafael Passos Domingues'

import sys
import numpy as np
import matplotlib.colors
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3

from math import *
from pylab import *
from mpl_toolkits.mplot3d import Axes3D

def grafico(xxb, yyb, zzb, xxd, yyd, zzd, xxh, yyh, zzh):
    xb = []
    yb = []
    zb = []

    xd = []
    yd = []
    zd = []

    xh = []
    yh = []
    zh = []

    dataset = None
    dataset = open('orbitas-estrelas-galaxia.dat', 'r')

    for line in dataset:
        XB, YB, ZB, XD, YD, ZD, XH, YH, ZH = line.split('\t')

        xb.append(float(XB))
        yb.append(float(YB))
        zb.append(float(ZB))

        xd.append(float(XD))
        yd.append(float(YD))
        zd.append(float(ZD))

        xh.append(float(XH))
        yh.append(float(YH))
        zh.append(float(ZH))

    dataset.close()
    return xb, yb, zb, xd, yd, zd, xh, yh, zh

def cil2cart(s, phi, z):
    x = s * cos(phi)
    y = s * sin(phi)
    z = z
    return x,y,z

def galact2cil(d, b, l, phis, zs):
    R0, V0 = (7.5, 200.) # Constantes de Oort
    u, v, w = (-10, 7.2, 10)  # Correcao do LSR

    # Coordinates
    s_estrela = sqrt( R0**(2) + (d*cos(b))**(2) - 2*d*R0*cos(l)*cos(b) )
    phi_estrela =  180 - phis
    z_estrela = zs + d*cos(b)

    vlsr = ((v * R0 / 15) - V0) * sin(l) * cos(b)
    vr = ((vlsr / sin(l) * cos(b)) + V0) * (s_estrela / R0)

    # Velocitys
    vs = -vr * cos(b)*cos(l)
    vphi = vr * cos(b)*sin(l)
    vz = vr * sin(b)
    return s_estrela, phi_estrela, z_estrela, vs, vphi, vz

def orbits(exc1, exc2, pc, b0, d0, h0, sb0, phib0, vsb0, zb0, vzb0, sd0, phid0, vsd0, zd0, vzd0, sh0, phih0, vsh0, zh0, vzh0, lb, ld, lh, tb, n, dt):
    handle_xyz = None
    handle_xyz = open("orbitas-estrelas-galaxia.dat", "w")

    for i in range(0, n, 1):
        sb, zb, sd, zd, sh, zh = positions2(sb0, vsb0, zb0, vzb0, sd0, vsd0, zd0, vzd0, sh0, vsh0, zh0, vzh0, dt)

        t = 0.
        k1, k2 = (0., 0.)
        db = tb / 20.
        b1, b2, b3 = (0., db, 2 * db)
        frb1, fzb1, frd1, fzd1, frh1, fzh1 = (0., 0., 0., 0., 0., 0.)

        for q in range(1, 10, 1):

            ab2,ab3,ad2,ad3,ah2,ah3 = majorsemiaxiselipsoide(exc1, exc2, b2, b3, sb0, zb0, sd0, zd0, sh0, zh0)

            frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3 = integrais(b0, d0, h0, ab2, ad2, ah2, ab3, ad3, ah3, b2)

            kb1, kb2, kd1, kd2, kh1, kh2 = simpson(k1, k2, frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3, db)

        ksb, kzb, ksd, kzd, ksh, kzh = acelerations(exc1, exc2, pc, sb0, kb1, zb0, kb2, sd0, kd1, zd0, kd2, sh0, kh1, zh0, kh2)

        vsb, vzb, vsd, vzd, vsh, vzh = velocitys(vsb0, ksb, lb, sb, vzb0, kzb, vsd0, ksd, ld, sd, vzd0, kzd, vsh0, ksh, lh, sh, vzh0, kzh, dt)

        sb0, phib0, zb0, sd0, phid0, zd0, sh0, phih0, zh0 = positions(sb0, vsb, phib0, lb, sb, zb0, vzb, sd0, vsd, phid0, ld, sd, zd0, vzd, sh0, vsh, phih0, lh, sh, zh0, vzh, dt)

        for q in range(1, 10, 1):

            ab2,ab3,ad2,ad3,ah2,ah3 = majorsemiaxiselipsoide(exc1, exc2, b2, b3, sb0, zb0, sd0, zd0, sh0, zh0)

            frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3 = integrais(b0, d0, h0, ab2, ad2, ah2, ab3, ad3, ah3, b2)

            kb1, kb2, kd1, kd2, kh1, kh2 = simpson(k1, k2, frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3, db)

            b1 = b1 + 2. * db
            b2 = b2 + 2. * db
            b3 = b3 + 2. * db

        ksb1, kzb1, ksd1, kzd1, ksh1, kzh1 = acelerations(exc1, exc2, pc, sb0, kb1, zb0, kb2, sd0, kd1, zd0, kd2, sh0, kh1, zh0, kh2)

        vsb0, vzb0, vsd0, vzd0, vsh0, vzh0 = velocitys(vsb0, ksb1, lb, sb, vzb0, kzb1, vsd0, ksd1, ld, sd, vzd0, kzd1, vsh0, ksh1, lh, sh, vzh0, kzh1, dt)

        t = t + dt

        xxb, yyb, zzb = cil2cart(sb0, phib0, zb0)
        xxd, yyd, zzd = cil2cart(sd0, phid0, zd0)
        xxh, yyh, zzh = cil2cart(sh0, phih0, zh0)

        handle_xyz.write("{0:12.4f}\t{1:12.4f}\t{2:12.4f}\t{3:12.4f}\t{4:12.4f}\t{5:12.4f}\t{6:12.4f}\t{7:12.4f}\t{8:12.4f}\n".format(xxb, yyb, zzb, xxd, yyd, zzd, xxh, yyh, zzh))

    handle_xyz.close()
    return xxb, yyb, zzb, xxd, yyd, zzd, xxh, yyh, zzh

def positions(sb0, vsb, phib0, lb, sb, zb0, vzb, sd0, vsd, phid0, ld, sd, zd0, vzd, sh0, vsh, phih0, lh, sh, zh0, vzh, dt):
    sb0 = sb0 + dt * vsb
    phib0 = phib0 + dt * (lb / sb ** 2.)
    zb0 = zb0 + dt * vzb

    sd0 = sd0 + dt * vsd
    phid0 = phid0 + dt * (ld / sd ** 2.)
    zd0 = zd0 + dt * vzd

    sh0 = sh0 + dt * vsh
    phih0 = phih0 + dt * (lh / sh ** 2.)
    zh0 = zh0 + dt * vzh
    return sb0, phib0, zb0, sd0, phid0, zd0, sh0, phih0, zh0

def positions2(sb0, vsb0, zb0, vzb0, sd0, vsd0, zd0, vzd0, sh0, vsh0, zh0, vzh0, dt):
    sb = sb0 + .5 * dt * vsb0
    zb = zb0 + .5 * dt * vzb0

    sd = sd0 + .5 * dt * vsd0
    zd = zd0 + .5 * dt * vzd0

    sh = sh0 + .5 * dt * vsh0
    zh = zh0 + .5 * dt * vzh0
    return sb, zb, sd, zd, sh, zh

def velocitys(vsb0, ksb1, lb, sb, vzb0, kzb1, vsd0, ksd1, ld, sd, vzd0, kzd1, vsh0, ksh1, lh, sh, vzh0, kzh1, dt):
    vsb0 = vsb0 + dt * (ksb1 + lb ** 2. / sb ** 3.)
    vzb0 = vzb0 + dt * kzb1

    vsd0 = vsd0 + dt * (ksd1 + ld ** 2. / sd ** 3.)
    vzd0 = vzd0 + dt * kzd1

    vsh0 = vsh0 + dt * (ksh1 + lh ** 2. / sh ** 3.)
    vzh0 = vzh0 + dt * kzh1
    return vsb0, vzb0, vsd0, vzd0, vsh0, vzh0

def acelerations(exc1, exc2, pc, sb0, kb1, zb0, kb2, sd0, kd1, zd0, kd2, sh0, kh1, zh0, kh2):
    ksb1 = -4. * pi * (sqrt(1. - exc2 ** 2.) / exc2 ** 3.) * pc * sb0 * kb1
    kzb1 = -4. * pi * (sqrt(1. - exc2 ** 2.) / exc2 ** 3.) * pc * zb0 * kb2

    ksd1 = -4. * pi * (sqrt(1. - exc1 ** 2.) / exc1 ** 3.) * pc * sd0 * kd1
    kzd1 = -4. * pi * (sqrt(1. - exc1 ** 2.) / exc1 ** 3.) * pc * zd0 * kd2

    ksh1 = -4. * pi * (sqrt(1. - exc2 ** 2.) / exc2 ** 3.) * pc * sh0 * kh1
    kzh1 = -4. * pi * (sqrt(1. - exc2 ** 2.) / exc2 ** 3.) * pc * zh0 * kh2
    return ksb1, kzb1, ksd1, kzd1, ksh1, kzh1

def simpson(k1, k2, frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3, db):
    kb1 = k1 + db * (frb1 + 4 * frb2 + frb3) / 3.
    kb2 = k2 + db * (fzb1 + 4 * fzb2 + fzb3) / 3.

    kd1 = k1 + db * (frd1 + 4 * frd2 + frd3) / 3.
    kd2 = k2 + db * (fzd1 + 4 * fzd2 + fzd3) / 3.

    kh1 = k1 + db * (frh1 + 4 * frh2 + frh3) / 3.
    kh2 = k2 + db * (fzh1 + 4 * fzh2 + fzh3) / 3.
    return kb1, kb2, kd1, kd2, kh1, kh2

def integrais(b0, d0, h0, ab2, ad2, ah2, ab3, ad3, ah3, b2):
    frb2 = exp(-ab2 / b0) * (sin(b2)) ** 2.
    fzb2 = exp(-ab2 / b0) * (tan(b2)) ** 2.

    frd2 = exp(-ad2 / d0) * (sin(b2)) ** 2.
    fzd2 = exp(-ad2 / d0) * (tan(b2)) ** 2.

    frh2 = exp(-ah2 / h0) * (sin(b2)) ** 2.
    fzh2 = exp(-ah2 / h0) * (tan(b2)) ** 2.

    frb3 = exp(-ab3 / b0) * (sin(b2)) ** 2.
    fzb3 = exp(-ab3 / b0) * (tan(b2)) ** 2.

    frd3 = exp(-ad3 / d0) * (sin(b2)) ** 2.
    fzd3 = exp(-ad3 / d0) * (tan(b2)) ** 2.

    frh3 = exp(-ah3 / h0) * (sin(b2)) ** 2.
    fzh3 = exp(-ah3 / h0) * (tan(b2)) ** 2.

    frb1 = frb3
    fzb1 = fzb3

    frd1 = frd3
    fzd1 = fzd3

    frh1 = frh3
    fzh1 = fzh3
    return frb1, fzb1, frd1, fzd1, frh1, fzh1, frb2, fzb2, frd2, fzd2, frh2, fzh2, frb3, fzb3, frd3, fzd3, frh3, fzh3

def majorsemiaxiselipsoide(exc1, exc2, b2, b3, sb0, zb0, sd0, zd0, sh0, zh0):
    ab2 = (1 / exc2) * sqrt((sb0 * sin(b2)) ** 2. + (zb0 * tan(b2)) ** 2.)
    ab3 = (1 / exc2) * sqrt((sb0 * sin(b3)) ** 2. + (zb0 * tan(b3)) ** 2.)

    ad2 = (1 / exc1) * sqrt((sd0 * sin(b2)) ** 2. + (zd0 * tan(b2)) ** 2.)
    ad3 = (1 / exc1) * sqrt((sd0 * sin(b3)) ** 2. + (zd0 * tan(b3)) ** 2.)

    ah2 = (1 / exc2) * sqrt((sh0 * sin(b2)) ** 2. + (zh0 * tan(b2)) ** 2.)
    ah3 = (1 / exc2) * sqrt((sh0 * sin(b3)) ** 2. + (zh0 * tan(b3)) ** 2.)
    return ab2, ab3, ad2, ad3, ah2, ah3

def arms(s1, s2, psi1, psi2):
    x1 = s1 * cos(psi1)
    y1 = s1 * sin(psi1)

    x2 = - x1
    y2 = - y1

    x3 = s2 * cos(psi2)
    y3 = s2 * sin(psi2)

    x4 = - x3
    y4 = - y3
    return x1, y1, x2, y2, x3, y3, x4, y4

def main(argv=None):
    exc1, exc2 = (0.99,0.99) # Excentricidades: Simetria cilíndrica e esférica
    exc = 0.99
    pc = 11613.5
    a0 = 2.8
    b0 = 2.26
    d0 = 2.8
    h0 = 5.
    A = 15.20
    B = A * sqrt(1 - exc2 ** 2)

    m = .8
    i = 14./57.3
    psi0 = 0.

    s1 = np.arange(0.1, 18., 0.01)
    s2 = np.arange(0.1, 13., 0.01)

    psi1 = ( m/tan(i) ) * ( log(s1/a0) ) + psi0
    psi2 = ( m/tan(i) ) * ( log(s2/a0) ) + psi0

    # Estrelas do Bojo

    sb0, phib0, zb0 = (1., 0., 0.)
    vsb0, vpb0, vzb0 = (0., 10., 50.)

    #sb0, phib0, zb0, vsb0, vpb0, vzb0 = galact2cil(7.5,1.,1.,1.,1.)

    # Estrelas do Disco

    sd0, phid0, zd0 = (7.5, 0., 0.)
    vsd0, vpd0, vzd0 = (0., 100., 50.)

    # Estrelas do Halo

    sh0, phih0, zh0 = (A, 0., 2*B)
    vsh0, vph0, vzh0 = (0., 50., 50.)

    lb, ld, lh = (sb0 * vpb0, sd0 * vpd0, sh0 * vph0)

    tb = asin(exc)

    n = 500 #input("Número de pontos a calcular [pontos] = ")
    dt = 0.001

    x1, y1, x2, y2, x3, y3, x4, y4 = arms(s1, s2, psi1, psi2)
    xxb, yyb, zzb, xxd, yyd, zzd, xxh, yyh, zzh = orbits(exc1, exc2, pc, b0, d0, h0, sb0, phib0, vsb0, zb0, vzb0, sd0, phid0, vsd0, zd0, vzd0, sh0, phih0, vsh0, zh0, vzh0, lb, ld, lh, tb, n, dt)
    xb, yb, zb, xd, yd, zd, xh, yh, zh = grafico(xxb, yyb, zzb, xxd, yyd, zzd, xxh, yyh, zzh)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    ax.scatter(x1, y1, c='steelblue', s=10, alpha=.1, label='Braços Espirais')
    ax.scatter(x2, y2, c='steelblue', s=10, alpha=.1)
    ax.scatter(x3, y3, c='steelblue', s=10, alpha=.1)
    ax.scatter(x4, y4, c='steelblue', s=10, alpha=.1)

    ax.scatter(xh, yh, zh, c='red', s=10, alpha=1, label='Estrelas do Halo')
    ax.scatter(xd, yd, zd, c='navy', s=10, alpha=1, label='Estrelas do Disco')
    ax.scatter(xb, yb, zb, c='black', s=10, alpha=1, label='Estrelas do Bojo')

    ax.legend()

    ax.set_xlabel("X [kpc]")
    ax.set_ylabel("Y [kpc]")
    ax.set_zlabel("Z [kpc]")

    ax.set_xlim(-15, 15)
    ax.set_ylim(-15, 15)
    ax.set_zlim(-7, 7)

    #plt.title("Órbitas Estelares na Galáxia")

    plt.show()
    return 0

if __name__ == "__main__":
    sys.exit(main())
