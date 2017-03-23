import matplotlib.pyplot as plt
import pandas as pd

# Read simulation files
sim_l_2 = pd.read_csv('../data/simulation-l-2.csv', header=None,
                      names=['Beta', 'Average Magnetization',
                             'Average Magnetization Squared',
                             'Average Absolute Magnetization',
                             'Magnetic Susceptability'])

sim_l_4 = pd.read_csv('../data/simulation-l-4.csv', header=None,
                      names=['Beta', 'Average Magnetization',
                             'Average Magnetization Squared',
                             'Average Absolute Magnetization',
                             'Magnetic Susceptability'])

fig, ax = plt.subplots()

ax.plot(sim_l_4['Beta'], sim_l_4['Average Magnetization'],
        label="Average Magnetization", linestyle="--")

ax.set(title="Ising model average magnetization for L = 4", xlabel="Beta",
       ylabel="Average Magnetization")

plt.grid()
fig.savefig('../plots/avg_mag_l_4.png')
