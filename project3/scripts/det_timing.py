import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Data column
size = 'size'
time = 'time'


column_names = [size, time]

# Read simulaiton files
data = pd.read_csv('../data/det_time.csv', header=None,
                   names=column_names)

# Attempt several fits
x = data[size].as_matrix()
y = data[time].as_matrix()

cubic = np.polyfit(x, y, 3)
cubic_fit = np.poly1d(cubic)

fit_points = np.linspace(0, 18, num=100)

fig, ax = plt.subplots()

ax.plot(data[size], data[time],
        label="$\ Observed$", marker="^", linestyle="", color='red')

ax.plot(fit_points, cubic_fit(fit_points),
        label="$\ Cubic$", linestyle="--", color='blue')

ax.set(title="Determinant computation time for large matrices",
       xlabel="Matrix size - N*N (thousands)",
       ylabel="Computation time (s)")

ax.legend(loc='upper left')
ax.grid(True)
fig.savefig('../plots/det_plot.png', dpi=400)
