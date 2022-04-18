'''import matplotlib.pyplot as plt

x,y = [],[]

for linha in open('dados.txt', 'r'):
    dados = [float(s) for s in linha.split()]
    x.append(dados[0])
    y.append(dados[1])

plt.plot(x,y)
plt.show()'''

import matplotlib.pyplot as plt

import numpy as np

dados = np.loadtxt('dados.txt')

plt.plot(dados[:,0], dados[:,1])
plt.show()