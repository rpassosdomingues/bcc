#!/usr/bin/python
# -*- coding: utf-8 -*-

# RAFAEL PASSOS DOMINGUES

import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt
import statsmodels.formula.api as sm

x = sp.random.normal(size=100)

y = 2*x + 1

dic = {"y":y, "x":x}
dados = pd.DataFrame(data=dic)

print("."*30)
print("Estatísticas descritivas de y:")
dados['y'].describe()
print("."*30)

reg = sm.ols(formula='y ~ x', data=dados).fit()
print(reg.summary())

coefs = pd.DataFrame(reg.params)
coefs.columns = ['Coeficientes']

print("."*30)
print(coefs)
print("."*30)

plt.scatter(y=dados['y'], x=dados['x'], color='blue', s=50, alpha=.5)

X_plot = sp.linspace(min(dados['x']), max(dados['x']), len(dados['x']))
plt.plot(X_plot, X_plot*reg.params[1] + reg.params[0], color='r')

plt.ylim(-11,16)
plt.xlim(-2.5,3)

plt.title('Reta de regressão')

plt.ylabel('$y$ - Variável Dependente')
plt.xlabel('$x$ - Preditor')

plt.show()
