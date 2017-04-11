import matplotlib.pyplot as plt

# Read data
datapoints = open('../data/hypersim-2-100000.csv', 'r')

x_outside = []
y_outside = []

x_inside = []
y_inside = []

for point in datapoints:
    x, y = point.split()

    x = float(x)
    y = float(y)

    if ((x**2 + y**2) > 1):
        x_outside.append(x)
        y_outside.append(y)
    else:
        x_inside.append(x)
        y_inside.append(y)


fig, ax = plt.subplots()

circle = plt.Circle((0, 0), radius=1, fc='none', alpha=0.5)

ax.scatter(x_inside, y_inside, marker='.', color='g')
ax.scatter(x_outside, y_outside, marker='.', color='b')

ax.add_patch(circle)
ax.set_xlim(0, 1)
ax.set_xlabel('$\ x $')
ax.set_ylabel('$\ y $')
ax.set_ylim(0, 1)
ax.set_aspect(1)
ax.set_title('Area of circle using Monte Carlo method \n $\ N = 100000 $',
             y=1.05)
fig.tight_layout()
fig.set_dpi(1000)
fig.savefig('../plots/circle_100000.png')
