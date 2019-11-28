import matplotlib.pyplot as plt
import numpy as np

with open("Lommepenger.txt") as file:
    size = file.readline()

    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    num_bins = int(((max_v-min_v)/0.5))
    plt.hist(lista, num_bins)
    plt.show()
