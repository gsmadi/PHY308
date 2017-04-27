import matplotlib.pyplot as plt
import pandas as pd


# Data columns
factor = 'factor'
time = 'time'
iterations = 'iterations'

column_names = [factor, time, iterations]

# Read simulaiton files
lat_100 = pd.read_csv('../data/relaxation-100.csv', header=None,
                      names=column_names)

lat_200 = pd.read_csv('../data/relaxation-200.csv', header=None,
                      names=column_names)

lat_300 = pd.read_csv('../data/relaxation-300.csv', header=None,
                      names=column_names)

lat_400 = pd.read_csv('../data/relaxation-400.csv', header=None,
                      names=column_names)

lat_500 = pd.read_csv('../data/relaxation-500.csv', header=None,
                      names=column_names)

# Read simulaiton files
lat_op_100 = pd.read_csv('../data/relaxation-op-100.csv', header=None,
                         names=column_names)

lat_op_200 = pd.read_csv('../data/relaxation-op-200.csv', header=None,
                         names=column_names)

lat_op_300 = pd.read_csv('../data/relaxation-op-300.csv', header=None,
                         names=column_names)

lat_op_400 = pd.read_csv('../data/relaxation-op-400.csv', header=None,
                         names=column_names)

lat_op_500 = pd.read_csv('../data/relaxation-op-500.csv', header=None,
                         names=column_names)

lat_op_100.describe()
lat_op_200.describe()
lat_op_400.describe()


# Iterations versus factor plot
iter_plot, iter_ax = plt.subplots()

iter_ax.plot(lat_100[factor], lat_100[iterations],
             label="$\ L = 100 $", marker=".", linestyle="")

iter_ax.plot(lat_200[factor], lat_200[iterations],
             label="$\ L = 200 $", marker=".", linestyle="")

iter_ax.plot(lat_300[factor], lat_300[iterations],
             label="$\ L = 300 $", marker=".", linestyle="")

iter_ax.plot(lat_400[factor], lat_400[iterations],
             label="$\ L = 400 $", marker=".", linestyle="")

iter_ax.plot(lat_500[factor], lat_500[iterations],
             label="$\ L = 500 $", marker=".", linestyle="")

iter_ax.set(title="Number of iterations versus relaxation factor",
            xlabel="Relaxation factor",
            ylabel="Number of iterations")

iter_ax.legend(loc='upper right')
iter_ax.grid(True)
iter_plot.savefig('../plots/iter_plot.png', dpi=400)

# Iterations versus factor plot - optimal
iter_op_plot, iter_op_ax = plt.subplots()

iter_op_ax.plot(lat_op_100[factor], lat_op_100[iterations],
                label="$\ L = 100 $", marker=".", linestyle="")

iter_op_ax.plot(lat_op_200[factor], lat_op_200[iterations],
                label="$\ L = 200 $", marker=".", linestyle="")

iter_op_ax.plot(lat_op_300[factor], lat_op_300[iterations],
                label="$\ L = 300 $", marker=".", linestyle="")

iter_op_ax.plot(lat_op_400[factor], lat_op_400[iterations],
                label="$\ L = 400 $", marker=".", linestyle="")

iter_op_ax.plot(lat_op_500[factor], lat_op_500[iterations],
                label="$\ L = 500 $", marker=".", linestyle="")

iter_op_ax.set(title="Optimal relxation factors",
               xlabel="Relaxation factor",
               ylabel="Number of iterations")

iter_op_ax.set_yscale('log')
iter_op_ax.legend(loc='upper left')
iter_op_ax.grid(True)
iter_op_plot.savefig('../plots/iter_op_plot.png', dpi=400)
