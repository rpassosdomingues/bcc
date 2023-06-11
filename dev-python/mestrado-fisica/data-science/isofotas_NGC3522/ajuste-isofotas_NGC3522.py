#!/usr/bin/python
# -*- coding: utf-8 -*-

__author__ = 'Oscar Cavichia'


import sys
import numpy as np
import matplotlib.pyplot as plt

#import astropy

from astropy.modeling.models import Gaussian2D
from astropy.io import fits
from astropy.nddata import Cutout2D
from astropy.wcs import WCS

#!pip3 install photutils

#import photutils

from photutils.datasets import make_noise_image
from photutils.isophote import EllipseGeometry
from photutils.aperture import EllipticalAperture
from photutils.isophote import Ellipse
from photutils.isophote import build_ellipse_model

def main(argv=None):
    
    #Substituir a imagem abaixo pela sua
    
    imageFile = "NGC3522_SDSSr.fits.bz2"
    # https://vizier.u-strasbg.fr/viz-bin/VizieR-4
    # http://skyserver.sdss.org/dr8/en/tools/explore/obj.asp?ra=166.6708&dec=20.0856
    # RA: 166.6708 deg / DEC: 20.0856 deg
    # http://simbad.u-strasbg.fr/simbad/sim-basic?Ident=NGC+3522&submit=SIMBAD+search
    # https://ned.ipac.caltech.edu/byname?objname=NGC+3522&hconst=67.8&omegam=0.308&omegav=0.692&wmap=4&corr_z=1
    
    hdul = fits.open(imageFile)
    #hdul.info()
    
    hdu=fits.open(imageFile)[0]
    
    image_data=hdu.data
    
    wcs = WCS(hdu.header)
    
    #Verificar no ds9 as coordenadas x0 e y0 da galáxia e mudar os valores:
    
    position = (1709.39, 630.338)
    size = (400, 400)
    
    cutout = Cutout2D(image_data, position=position, size=size, wcs=wcs)
    image_data_cut = cutout.data
    
    plt.imshow(image_data_cut, origin='lower', cmap='viridis', vmin=0,vmax=1)
    
    #Caso mude os valores de size, substituir x0 e y0 abaixo pela metade dos valores
    geometry = EllipseGeometry(x0=200, y0=200, sma=20, eps=0.1, pa=20.*np.pi/180.)
    
    aper = EllipticalAperture((geometry.x0, geometry.y0), geometry.sma, geometry.sma*(1 - geometry.eps), geometry.pa)
    
    plt.imshow(image_data_cut, origin='lower')
    
    aper.plot(color='red')
    
    #Criamos uma instancia da classe Ellipse para fazer o ajuste de isofotas elípticas
    
    ellipse = Ellipse(image_data_cut, geometry)
    
    #Fazemos o ajuste da elípse com o método fit_image. Não ajustamos em menos de 2 pixels.
    
    isolist = ellipse.fit_image(minsma=2)
    
    #O resultado é o objeto isolist que contem os atributos:
    #https://photutils.readthedocs.io/en/stable/api/photutils.isophote.IsophoteList.html#photutils.isophote.IsophoteList
    
    #['sma', 'intens', 'int_err', 'eps', 'ellip_err', 'pa', 'pa_err', 'x0', 'x0_err', 'y0', 'y0_err', 'rms', 'pix_stddev', 'grad', 'grad_error', 'grad_r_error', 'sarea', 'ndata', 'nflag', 'niter', 'valid', 'stop_code', 'tflux_e', 'tflux_c', 'npix_e', 'npix_c', 'a3', 'b3', 'a4', 'b4', 'a3_err', 'b3_err', 'a4_err', 'b4_err']
    
    #Vamos imprimir os semieixos das isofotas
    
    print("sma = {0} \n intens = {1}".format(isolist.sma,isolist.intens))
    
    #Os nomes de cada coluna são:
    
    #print(isolist.get_names())
    
    #Podemos imprimir uma tabela ordenada por sma:
    
    #print(isolist.to_table())
    
    #Vamos salvar a tabela em uma arquivo txt
    
    from tabulate import tabulate
    
    with open('dados_ajuste.txt', 'w') as f:
        f.write(tabulate(isolist.to_table(["sma","intens"])))
        
    #Construir uma imagem do modelo
    
    model_image = build_ellipse_model(image_data_cut.shape, isolist)
    
    residual = image_data_cut - model_image
    
    fig, (ax1, ax2, ax3) = plt.subplots(figsize=(14, 5), nrows=1, ncols=3)
    
    fig.subplots_adjust(left=0.04, right=0.98, bottom=0.02, top=0.98)
    
    ax1.imshow(image_data_cut, origin='lower',cmap='viridis',vmin=0,vmax=2)
    
    ax1.set_title('Original + Ajuste')
    
    smas = np.linspace(10, 100, 10)
    
    for sma in smas:
        iso = isolist.get_closest(sma)
        
        x, y, = iso.sampled_coordinates()
        
        ax1.plot(x, y, color='white')
        
    ax2.imshow(model_image, origin='lower',cmap='viridis',vmin=0,vmax=2)
    ax2.set_title('Modelo Ellipse')

    ax3.imshow(residual, origin='lower',cmap='viridis',vmin=0,vmax=2)
    ax3.set_title('Residuo')
    
    plt.show()
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
    
