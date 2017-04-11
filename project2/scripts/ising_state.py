import matplotlib.pyplot as plt
import numpy as np

ising_states = []

for i in np.arange(1.1, 3.2, 0.3):
    ising_state = open('../data/lattice-128-{0}.csv'.format(i))
    ising_matrix = []

    for row in ising_state:
        ising_matrix.append(row.split())

    # Create list of ising state matrices fro 8 different temperatures
    ising_states.append(np.array(ising_matrix, dtype=float))

fig, axarr = plt.subplots(2, 4)


axarr[0][0].imshow(ising_states[0], cmap=plt.cm.binary, aspect='equal')
axarr[0][0].set_title('$\ T = 1.1 $')
axarr[0][1].imshow(ising_states[1], cmap=plt.cm.binary, aspect='equal')
axarr[0][1].set_title('$\ T = 1.4 $')
axarr[0][2].imshow(ising_states[2], cmap=plt.cm.binary, aspect='equal')
axarr[0][2].set_title('$\ T = 1.7 $')
axarr[0][3].imshow(ising_states[3], cmap=plt.cm.binary, aspect='equal')
axarr[0][3].set_title('$\ T = 2.0 $')
axarr[1][0].imshow(ising_states[4], cmap=plt.cm.binary, aspect='equal')
axarr[1][0].set_title('$\ T = 2.3 $')
axarr[1][1].imshow(ising_states[5], cmap=plt.cm.binary, aspect='equal')
axarr[1][1].set_title('$\ T = 2.6 $')
axarr[1][2].imshow(ising_states[6], cmap=plt.cm.binary, aspect='equal')
axarr[1][2].set_title('$\ T = 2.9 $')
axarr[1][3].imshow(ising_states[7], cmap=plt.cm.binary, aspect='equal')
axarr[1][3].set_title('$\ T = 3.2 $')

plt.suptitle('Ising model states for 128 x 128 lattice')
fig.set_size_inches(10, 5.8)
fig.set_dpi(1000)
fig.savefig('../plots/ising_states.png')
