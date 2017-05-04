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


fig, axarr = plt.subplots(nrows=1, ncols=2,
                          gridspec_kw={'width_ratios': [1, 1]})

cax = axarr[0].imshow(temp_500, cmap=plt.cm.hot)
axarr[0].set(title='Simulated')
cax = axarr[1].imshow(actual_500, cmap=plt.cm.hot)
axarr[1].set(title='Actual')

# Add colorbar axis
fig.subplots_adjust(right=0.95)
cbar_ax = fig.add_axes([0.98, 0.15, 0.05, 0.7])
fig.colorbar(cax, cax=cbar_ax)

fig.tight_layout()
fig.suptitle('Lattice temperature comparison', fontsize=14)
fig.savefig('../plots/temp_comp.png', dpi=200, bbox_inches='tight')
