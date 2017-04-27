import matplotlib.pyplot as plt
import numpy as np

temp_data_100 = open('../data/lattice-100-1.940000.csv')
actual_data_100 = open('../data/lattice-100-0.000000.csv')

temp_data_200 = open('../data/lattice-200-1.970000.csv')
actual_data_200 = open('../data/lattice-200-0.000000.csv')

temp_data_300 = open('../data/lattice-300-1.980000.csv')
actual_data_300 = open('../data/lattice-300-0.000000.csv')

temp_data_400 = open('../data/lattice-400-1.980000.csv')
actual_data_400 = open('../data/lattice-400-0.000000.csv')

temp_data_500 = open('../data/lattice-500-1.990000.csv')
actual_data_500 = open('../data/lattice-500-0.000000.csv')

temp_matrix_100 = []
actual_matrix_100 = []
discrepancy_matrix_100 = []

temp_matrix_200 = []
actual_matrix_200 = []
discrepancy_matrix_200 = []

temp_matrix_300 = []
actual_matrix_300 = []
discrepancy_matrix_300 = []

temp_matrix_400 = []
actual_matrix_400 = []
discrepancy_matrix_400 = []

temp_matrix_500 = []
actual_matrix_500 = []
discrepancy_matrix_500 = []

for row in temp_data_100:
    temp_matrix_100.append(row.split())

for row in actual_data_100:
    actual_matrix_100.append(row.split())


for row in temp_data_200:
    temp_matrix_200.append(row.split())

for row in actual_data_200:
    actual_matrix_200.append(row.split())

for row in temp_data_300:
    temp_matrix_300.append(row.split())

for row in actual_data_300:
    actual_matrix_300.append(row.split())


for row in temp_data_400:
    temp_matrix_400.append(row.split())

for row in actual_data_400:
    actual_matrix_400.append(row.split())


for row in temp_data_500:
    temp_matrix_500.append(row.split())

for row in actual_data_500:
    actual_matrix_500.append(row.split())


# Create list of ising state matrices fro 8 different temperatures
temp_100 = np.array(temp_matrix_100, dtype=float)
actual_100 = np.array(actual_matrix_100, dtype=float)
discrepancy_matrix_100 = np.abs(temp_100 - actual_100)
dis_100 = np.array(discrepancy_matrix_100, dtype=float)

temp_200 = np.array(temp_matrix_200, dtype=float)
actual_200 = np.array(actual_matrix_200, dtype=float)
discrepancy_matrix_200 = np.abs(temp_200 - actual_200)
dis_200 = np.array(discrepancy_matrix_200, dtype=float)

temp_300 = np.array(temp_matrix_300, dtype=float)
actual_300 = np.array(actual_matrix_300, dtype=float)
discrepancy_matrix_300 = np.abs(temp_300 - actual_300)
dis_300 = np.array(discrepancy_matrix_300, dtype=float)

temp_400 = np.array(temp_matrix_400, dtype=float)
actual_400 = np.array(actual_matrix_400, dtype=float)
discrepancy_matrix_400 = np.abs(temp_400 - actual_400)
dis_400 = np.array(discrepancy_matrix_400, dtype=float)

temp_500 = np.array(temp_matrix_500, dtype=float)
actual_500 = np.array(actual_matrix_500, dtype=float)
discrepancy_matrix_500 = np.abs(temp_500 - actual_500)
dis_500 = np.array(discrepancy_matrix_500, dtype=float)


fig, axarr = plt.subplots()
fig1, axarr1 = plt.subplots()
fig2, axarr2 = plt.subplots()

cax = axarr.imshow(temp_500, cmap=plt.cm.hot, aspect='equal')
cbar = fig.colorbar(cax)

cax1 = axarr1.imshow(actual_500, cmap=plt.cm.hot, aspect='equal')
cbar1 = fig1.colorbar(cax1)

cax2 = axarr2.imshow(dis_400, cmap=plt.cm.binary, aspect='equal')
cax3 = axarr2.imshow(dis_400, cmap=plt.cm.binary, aspect='equal')
cbar2 = fig2.colorbar(cax2)
