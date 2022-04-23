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

from pandas import read_excel

#BubbleSort

dados = np.loadtxt('dados_bubbleSort.txt')

plt.plot(dados[:,0], dados[:,1])
plt.xlabel('Tamanho da amostra', fontsize=13)
plt.ylabel('Tempo de utilização da CPU (s)', fontsize=13)
plt.title('Clock - BubbleSort')
plt.show()

#Quicksort

dados = np.loadtxt('dados_quickSort.txt')

plt.plot(dados[:,0], dados[:,1])
plt.xlabel('Tamanho da amostra', fontsize=13)
plt.ylabel('Tempo de utilização da CPU (s)', fontsize=13)
plt.title('Clock - QuickSort')
plt.show()

#Sobreposição dos gráficos do bubbleSort x quickSort

dados_excel = read_excel('./dados.xlsx', names=['A','B','C'])

plt.plot(dados_excel['A'], dados_excel['B'], linestyle='--', marker='o', color = 'blue', markersize = 4)
plt.plot(dados_excel['A'], dados_excel['C'], linestyle='--', marker='o', color = 'red', markersize = 4)

plt.xlabel('Tamanho da amostra', fontsize=13)
plt.ylabel('Tempo de utilização da CPU (s)', fontsize=13)
plt.title('Clock - BubbleSort x QuickSort')
plt.legend(['Ordenação com o BubbleSort','Ordenação com o QuickSort'], fontsize=13)

axes = plt.gca()
axes.yaxis.grid(b=True, color='black', alpha=0.3, linestyle='-.', linewidth=1)

plt.show()