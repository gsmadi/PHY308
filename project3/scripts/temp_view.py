import matplotlib.pyplot as plt
import numpy as np

temp_data = open('../data/lattice-100-1.940000.csv')
actual_data = open('../data/lattice-100-0.000000.csv')
temp_matrix = []
actual_matrix = []
discrepancy_matrix = []

for row in temp_data:
    temp_matrix.append(row.split())

for row in actual_data:
    actual_matrix.append(row.split())


# Create list of ising state matrices fro 8 different temperatures
temp = np.array(temp_matrix, dtype=float)
actual = np.array(actual_matrix, dtype=float)

discrepancy_matrix = np.abs(temp - actual)

dis = np.array(discrepancy_matrix, dtype=float)

fig, axarr = plt.subplots()
fig1, axarr1 = plt.subplots()
fig2, axarr2 = plt.subplots()


cax = axarr.imshow(temp, cmap=plt.cm.hot, aspect='equal')
cbar = fig.colorbar(cax)

cax1 = axarr1.imshow(actual, cmap=plt.cm.hot, aspect='equal')
cbar1 = fig1.colorbar(cax1)

cax2 = axarr2.imshow(dis, cmap=plt.cm.binary, aspect='equal')
cbar2 = fig2.colorbar(cax2)
