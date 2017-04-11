from itertools import combinations, product

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

# Read data
datapoints = open('../data/hypersim-3-1000.csv', 'r')

x_outside = []
y_outside = []
z_outside = []

x_inside = []
y_inside = []
z_inside = []

for point in datapoints:
    x, y, z = point.split()

    x = float(x)
    y = float(y)
    z = float(z)

    if ((x**2 + y**2 + z**2) > 1):
        x_outside.append(x)
        y_outside.append(y)
        z_outside.append(z)
    else:
        x_inside.append(x)
        y_inside.append(y)
        z_inside.append(z)

fig = plt.figure()
ax = plt.gca(projection='3d')
ax.set_aspect('equal')

# Render cube
r = [0, 1]
for s, e in combinations(np.array(list(product(r, r, r))), 2):
    if np.sum(np.abs(s-e)) == r[1]-r[0]:
        ax.plot3D(*zip(s, e), color='k')

# Render sphere
theta, phi = np.mgrid[0:0.5*np.pi:50j, 0:0.5*np.pi:50j]
x = np.cos(theta)*np.sin(phi)
y = np.sin(theta)*np.sin(phi)
z = np.cos(phi)

ax.plot_wireframe(x, y, z, color='k')

ax.scatter(x_inside, y_inside, z_inside, marker='.', color='g')
ax.scatter(x_outside, y_outside, z_outside, marker='.', color='b')

ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.set_zlim(0, 1)
ax.set_xlabel('$\ x $')
ax.set_ylabel('$\ y $')
ax.set_zlabel('$\ z $')
ax.set_title('Volume of sphere using Monte Carlo method \n $\ N = 1000 $',
             y=1.05)
fig.tight_layout()
fig.set_dpi(500)
fig.savefig('../plots/sphere_1000.png')
