import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

# eixo x = quantidade de elementos
x = []
for qtd in range(5000,15000,1000):
    x.append(qtd)

# eixo y = media do tempo de execução
y = []
arquivo = open("arquivo.txt", "r")
for linha in arquivo:
    tempos = [float(tempo) for tempo in linha.replace(" \n","").split(" ")]
    y.append(sum(tempos)/len(tempos))

sns.set_theme(context='notebook', style='darkgrid', palette='deep', font='sans-serif', font_scale=1, color_codes=True, rc=None)

eixox = np.array(x)
eixoy = np.array(y)

plt.xlabel("Número de entradas")
plt.ylabel("Tempo de execução (segundos)")
plt.title("Gráfico de complexidade")
plt.plot(eixox, eixoy,color ="red")


plt.savefig('grafico.png')