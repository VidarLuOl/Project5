import matplotlib.pyplot as plt
import numpy as np
from math import log, exp


"""
with open("Lommepenger.txt") as file:
    lista = []
    listb = []
    a = 0

    for i in file:

        lista.append(float(i))
        a += 1
        if(a == 1000):
            listb.append(lista)
            lista = []
            a = 0

    max = np.max(listb)

    step = 30
    bins = int(max/step)
    m_val = np.linspace(0, max, bins)


    hist_arr = np.zeros((len(listb[0]), len(m_val)-1))
    diff = np.zeros(1000)
    hist_arr[0] = np.histogram(listb[0], bins = m_val)[0]

    for i in range(1, len(listb[0])-1):
        hist_arr[i,:] = np.histogram(listb[:i], bins = m_val)[0]
        diff[i] = np.linalg.norm(((hist_arr[i]/i)-(hist_arr[i-1]/(i-1))))

    plt.plot(diff)
"""


with open("E_5L_2_0.txt") as file:
    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    max_min = int((max_v-min_v)*0.05)

    v,u = np.histogram(lista, max_min)
    senter = 0.5*(u[1:] + u[:-1])
    plt.plot(senter, v, label="alpha = 0")



with open("E_5L_2_1.txt") as file:
    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    max_min = int((max_v-min_v)*0.05)

    v,u = np.histogram(lista, max_min)
    senter = 0.5*(u[1:] + u[:-1])
    plt.plot(senter, v, label="alpha = 1")

with open("E_5L_2_2.txt") as file:
    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    max_min = int((max_v-min_v)*0.05)

    v,u = np.histogram(lista, max_min)
    senter = 0.5*(u[1:] + u[:-1])
    plt.plot(senter, v, label="alpha = 2")

with open("E_5L_2_3.txt") as file:
    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    max_min = int((max_v-min_v)*0.05)

    v,u = np.histogram(lista, max_min)
    senter = 0.5*(u[1:] + u[:-1])
    plt.plot(senter, v, label="alpha = 3")

with open("E_5L_2_4.txt") as file:
    lista = []

    for i in file:
        lista.append(float(i))

    max_v = max(lista)
    min_v = min(lista)

    max_min = int((max_v-min_v)*0.05)

    v,u = np.histogram(lista, max_min)
    senter = 0.5*(u[1:] + u[:-1])
    plt.plot(senter, v, label="alpha = 4")

plt.xlabel("An agents value")
plt.ylabel("Number of agents")
plt.legend()

plt.xlim(40,200)
plt.ylim(1200,5000)

plt.show()
