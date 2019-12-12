import matplotlib.pyplot as plt
import numpy as np
from math import log, exp

with open("Lommepenger.txt") as file:

    Opg = "a"

    b = 1/500
    eq = b*exp(-b*500)

    print(eq)

    if(Opg == "a"):
        lista = []

        """
        for i in file:
            lista.append(b*exp(-b*float(i)))
        """

        for i in file:
            lista.append(float(i))

        max_v = max(lista)
        min_v = min(lista)

        """lista.sort()"""

        max_min = int((max_v-min_v)*0.05)

        plt.hist(lista, max_min)

        plt.show()

    elif(Opg == "b"):
        lista = []

        for i in file:
            lista.append(log(float(i)))

        lista.sort()
        max_v = max(lista)
        min_v = min(lista)

        max_min = int((max_v-min_v))

        lol = np.linspace(min_v, max_v, max_min/0.05)

        ting, tang  = np.histogram(lista, lol)

        plt.plot(tang)

        plt.show()

        plt.plot(ting)

        plt.show()
