import matplotlib.pyplot as plt
import numpy as np
from math import log, exp

with open("1000MC_1000A_if.txt") as file:

    Opg = "a"

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
        lista.sort()

        plt.hist(lista, max_min, label="Plots how many agents that has what value")
        plt.xlabel("An agents value")
        plt.ylabel("Number of agents")
        plt.legend()

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
