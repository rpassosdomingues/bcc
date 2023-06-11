#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Rafael Passos Domingues'

import sys
import numpy as np
import matplotlib.pyplot as plt

def SNR(t_exp, fwhm, R_source, R_sky, RN, n_pix, win):
    
    # Noise's
    
    N_source = R_source * t_exp
    N_sky = R_sky * (n_pix) * t_exp
    N_read = (n_pix) * ( (RN)**(2) + (win/2.)**(2)  )
    N_dark = fwhm * (n_pix) * t_exp
    
    # Signal-Noise Ratio
    
    snr = ( (N_source) / ( np.sqrt((N_source) + (N_sky) + (N_read) + (N_dark) )) )
    
    return snr

def main(argv=None):
    
    # Example -- LRIS: Keck I - Hawaii: np.url(https://www2.keck.hawaii.edu/inst/lris/lrishome.html)
    
    # Constants
    
    # Count's Rate: Differents values filter
    
    B = V = R = I = m = 20. # [mag]
    
    CR_B = 1470. # [e-/sec]
    CR_V = 1521. # [e-/sec]
    CR_R = 1890. # [e-/sec]
    CR_I = 1367. # [e-/sec]
    
    # Count's Rate vs magnitude
    
    # R(M) = R(m) * 10**( (0.4)*(20-m) ) # V = 25.1 ~ Sky of New Moon 
    
    n_pix = 0.22 # ["/pixel]
    win = 2.0 # [e-/ADU]
    
    # R_optimal = 1.7 * sigma # (Gaussian): R_optimal = 2.35 * sigma 
    # R_optimal = (2/3)*(FWHM)
    
    R_source = 6.1 # [e-/sec]
    R_sky = 13.8 # [e-/sec/px]
    RN = 8 # [e-]
    
    # exposure time
    
    t_exp = np.arange(0., 1500., 50.) # exposure time [sec]
    
    # Different values of the FWHM
    
    (fwhm04 , fwhm07, fwhm10, fwhm13) = (0.4, 0.7, 1.0, 1.3) # [arcsec]
    
    # SNR and SNR in limit cases >> Exposition time
    
    snr04 = SNR(t_exp,fwhm04, R_source, R_sky, RN, n_pix, win)
    snr07 = SNR(t_exp,fwhm07, R_source, R_sky, RN, n_pix, win)
    snr10 = SNR(t_exp,fwhm10, R_source, R_sky, RN, n_pix, win)
    snr13 = SNR(t_exp,fwhm13, R_source, R_sky, RN, n_pix, win)
    
    # Limit Cases
    
    N_source = R_source * t_exp
    N_sky = R_sky * (n_pix) * t_exp
    
    snr_bright = np.sqrt( N_source ) #~ np.sqrt(t_exp) # brightness sources
    snr_weak = ( (N_source) / np.sqrt(N_sky) ) #~ np.sqrt(t_exp) # weakness sources (sky limited)
    
    print('snr_bright = {0}'.format(snr_bright))
    print('snr_weak = {0}'.format(snr_weak))
    
    # Gráficos
    
    fig, ax = plt.subplots()
    
    ax.scatter(t_exp, snr04, c='navy', s=5, alpha=1, label='FWHM = 0.4"')
    ax.scatter(t_exp, snr07, c='red', s=5, alpha=1, label='FWHM = 0.7"')
    ax.scatter(t_exp, snr10, c='black', s=5, alpha=1, label='FWHM = 1.0"')
    ax.scatter(t_exp, snr13, c='green', s=5, alpha=1, label='FWHM = 1.3"')
    ax.legend()
    
    ax.set_xlabel("exposure time [sec]")
    ax.set_ylabel("SNR")
    
    fig, ax = plt.subplots()
    
    ax.scatter(t_exp, snr_bright, c='blue', s=5, alpha=1, label='Fontes brilhantes')
    ax.scatter(t_exp, snr_weak, c='red', s=5, alpha=1, label='Fontes fracas')
    ax.legend()
    
    ax.set_xlabel("exposure time [sec]")
    ax.set_ylabel("SNR")
    
    #plt.grid()
    #plt.title("S/N vs exposure time for V=26 mag star using LRIS on KeckII plotted for
    #different values of the FWHM of point sources.")
    
    plt.show()
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
