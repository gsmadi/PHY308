import math

import matplotlib.pyplot as plt
import pandas as pd

# Read data
data_dim_2 = pd.read_csv('../data/hypersphere-2.csv',
                         header=None, names=['n', 'val', 'sme'])

data_dim_3 = pd.read_csv('../data/hypersphere-3.csv',
                         header=None, names=['n', 'val', 'sme'])

data_dim_10 = pd.read_csv('../data/hypersphere-10.csv',
                          header=None, names=['n', 'val', 'sme'])

# Plot data
dim_2_plot, ax_dim_2 = plt.subplots()
dim_3_plot, ax_dim_3 = plt.subplots()
dim_10_plot, ax_dim_10 = plt.subplots()

# Dim 2
circle_actual = math.pi

dim_2_errors = 100*abs(data_dim_2['val'] - circle_actual)/circle_actual
ax_dim_2.plot(data_dim_2['n'], data_dim_2['val'],
              linestyle="-", marker="o", label="Approximation")
ax_dim_2.plot(data_dim_2['n'], len(data_dim_2)*[circle_actual], color='g',
              linestyle='--', label='Actual', linewidth=2.5)

ax_dim_2.set_xscale("log", nonposx='clip')
ax_dim_2.set(title="Circle area approximation via Monte Carlo Method",
             xlabel="Number of iterations", ylabel="Approximation")
ax_dim_2.grid(True)
ax_dim_2.legend(loc='lower center')

ax_2_error = ax_dim_2.twinx()

ax_2_error.plot(data_dim_2['n'], dim_2_errors, color='r', label='% Error')
ax_2_error.set_ylabel('% Error', color='r')
ax_2_error.tick_params('y', colors='r')
ax_2_error.set_yscale("log")
ax_2_error.grid(True, color='r', linestyle='--')

dim_2_plot.tight_layout()
dim_2_plot.set_dpi(1000)
dim_2_plot.savefig('../plots/dim_2_plot.png')


# Dim 3
sphere_actual = (4.0/3.0)*math.pi

dim_3_errors = 100*abs(data_dim_3['val'] - sphere_actual)/sphere_actual
ax_dim_3.plot(data_dim_3['n'], data_dim_3['val'],
              linestyle="-", marker="o", label="Approximation")
ax_dim_3.plot(data_dim_3['n'], len(data_dim_3)*[sphere_actual], color='g',
              linestyle='--', label='Actual', linewidth=2.5)

ax_dim_3.set_xscale("log", nonposx='clip')
ax_dim_3.set(title="Sphere volume approximation via Monte Carlo Method",
             xlabel="Number of iterations", ylabel="Approximation")
ax_dim_3.grid(True)
ax_dim_3.legend(loc='upper right')

ax_3_error = ax_dim_3.twinx()

ax_3_error.plot(data_dim_3['n'], dim_3_errors, color='r')
ax_3_error.set_ylabel('% Error', color='r')
ax_3_error.tick_params('y', colors='r')
ax_3_error.set_yscale("log")
ax_3_error.grid(True, color='r', linestyle='--')

dim_3_plot.tight_layout()
dim_3_plot.set_dpi(1000)
dim_3_plot.savefig('../plots/dim_3_plot.png')


# Dim 10
ten_dim_actual = math.pi**5/120.0

dim_10_errors = 100*abs(data_dim_10['val'] - ten_dim_actual)/ten_dim_actual
ax_dim_10.plot(data_dim_10['n'], data_dim_10['val'],
               linestyle="-", marker="o", label="Approximation")
ax_dim_10.plot(data_dim_10['n'], len(data_dim_10)*[ten_dim_actual], color='g',
               linestyle='--', label='Actual', linewidth=2.5)

ax_dim_10.set_xscale("log", nonposx='clip')
ax_dim_10.set(title="Sphere-10D volume approximation via Monte Carlo Method",
              xlabel="Number of iterations", ylabel="Approximation")
ax_dim_10.grid(True)
ax_dim_10.legend(loc='lower center')

ax_10_error = ax_dim_10.twinx()

ax_10_error.plot(data_dim_10['n'], dim_10_errors, color='r')
ax_10_error.set_ylabel('% Error', color='r')
ax_10_error.tick_params('y', colors='r')
ax_10_error.set_yscale("log")
ax_10_error.grid(True, color='r', linestyle='--')

dim_10_plot.tight_layout()
dim_10_plot.set_dpi(1000)
dim_10_plot.savefig('../plots/dim_10_plot.png')
dim_10_errors
