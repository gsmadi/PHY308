import matplotlib.pyplot as plt
import pandas as pd

# Specifify data columns
temp = 'Temp'
avg_mag = 'Average Magnetization'
avg_mag_squared = 'Average Magnetization Squared'
avg_abs_mag = 'Average Absolute Magnetization'
mag_susc = 'Magnetic Susceptability'

column_names = [temp, avg_mag, avg_mag_squared, avg_abs_mag, mag_susc]

# Read simulation files
sim_l_2 = pd.read_csv('data/simulation_l_32.csv', header=None,
                      names=column_names)

sim_l_4 = pd.read_csv('data/simulation_l_4.csv', header=None,
                      names=column_names)

sim_l_8 = pd.read_csv('data/simulation_l_8.csv', header=None,
                      names=column_names)

sim_l_16 = pd.read_csv('data/simulation_l_16.csv', header=None,
                       names=column_names)

# Global matplotlib initialization
plt.grid()

# Average Magnetization Plot
avg_mag_plot, ax = plt.subplots()

ax.plot(sim_l_2[temp], sim_l_2[avg_mag],
        label="L = 2", marker=".", linestyle="")

ax.plot(sim_l_4[temp], sim_l_4[avg_mag],
        label="L = 4", marker=".", linestyle="")

ax.plot(sim_l_8[temp], sim_l_8[avg_mag],
        label="L = 8", marker=".", linestyle="")

ax.plot(sim_l_16[temp], sim_l_16[avg_mag],
        label="L = 16", marker=".", linestyle="")

ax.set(title="Ising Model Average Magnetization",
       xlabel="Temperature",
       ylabel="Average Magnetization - <M>")

ax.legend(loc='upper right')
ax.grid(True)
avg_mag_plot.savefig('plots/avg_mag.png')


# Average Magnetization Squared Plot
avg_mag_squared_plot, ax1 = plt.subplots()

ax1.plot(sim_l_2[temp], sim_l_2[avg_mag_squared],
         label="L = 2")

ax1.plot(sim_l_4[temp], sim_l_4[avg_mag_squared],
         label="L = 4")

ax1.plot(sim_l_8[temp], sim_l_8[avg_mag_squared],
         label="L = 8")

ax1.plot(sim_l_16[temp], sim_l_16[avg_mag_squared],
         label="L = 16")

ax1.set(title="Ising Model Average Magnetization Squared",
        xlabel="Temperature",
        ylabel="Average Magnetization Squared - <M^2>")

ax1.legend(loc='lower left')
ax1.grid(True)
avg_mag_squared_plot.savefig('plots/avg_mag_squared.png')


# Average Absolute Magnetization plot
avg_abs_mag_plot, ax2 = plt.subplots()

ax2.plot(sim_l_2[temp], sim_l_2[avg_abs_mag],
         label="L = 2")

ax2.plot(sim_l_4[temp], sim_l_4[avg_abs_mag],
         label="L = 4")

ax2.plot(sim_l_8[temp], sim_l_8[avg_abs_mag],
         label="L = 8")

ax2.plot(sim_l_16[temp], sim_l_16[avg_abs_mag],
         label="L = 16")

ax2.set(title="Ising Model Average Absolute Magnetization",
        xlabel="Temperature",
        ylabel="Average Absolute Magnetization - <|M|>")

ax2.legend(loc='lower left')
ax2.grid(True)
avg_abs_mag_plot.savefig('plots/avg_abs_mag.png')


# Magnetic Susceptability plot
mag_susc_plot, ax2 = plt.subplots()

ax2.plot(sim_l_2[temp], sim_l_2[mag_susc],
         label="L = 32")

ax2.plot(sim_l_4[temp], sim_l_4[mag_susc],
         label="L = 4")

ax2.plot(sim_l_8[temp], sim_l_8[mag_susc],
         label="L = 8")

ax2.plot(sim_l_16[temp], sim_l_16[mag_susc],
         label="L = 16")

ax2.set(title="Ising Model Magnetic Susceptability",
        xlabel="Temperature",
        ylabel="Magnetic Susceptability - X'")

ax2.legend(loc='upper left')
ax2.grid(True)
mag_susc_plot.savefig('plots/mag_susc.png')
