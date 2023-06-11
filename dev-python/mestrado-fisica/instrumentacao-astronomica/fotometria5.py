#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

# LISTA 2: Técnicas Observacionais em Astrofísica -- Questão 5

import sys
import numpy as np

def luminosidade(d,f_0,m_B):
    L_B = 4 * (np.pi) * d**2 * f_0 * 10**(-(2/5)*m_B) * (0.44e4) * np.pi*((0.098e-4)**2/2) # Levando em conta o \lambda e o FWHM
    return L_B

def main(argv=None):

    d = 10 # [pc] - parsecs
    m_B = 5.41
    f_0 = 6.61e-9 # [erg/cm**2/s/angstrom]
    #f_0 = 4.27e-23  # [W/m**2/Hz]

    L_B = luminosidade(d,f_0,m_B)

    print('='*60)
    print('Fração da luminosidade do Sol que é emitida na banda B')
    print('-'*60)
    print('L_B = {0}'.format(L_B))
    print('='*60)

    return 0

if __name__ == "__main__":
    sys.exit(main())
