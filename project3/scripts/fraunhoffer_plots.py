import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import matplotlib as mpl
from matplotlib import gridspec

# Data column
root = 'root'
angle = 'angle'


column_names = [root, angle]
cm = np.array([[0, 0, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [29, 29, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [57, 58, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [86, 87, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [115, 116, 0],
               [141, 143, 0],
               [160, 161, 0],
               [180, 180, 0],
               [199, 198, 0],
               [219, 216, 0],
               [232, 229, 0],
               [247, 229, 0],
               [249, 235, 1],
               [251, 241, 1],
               [253, 247, 2],
               [255, 253, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 2],
               [255, 254, 1],
               [255, 254, 1],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0],
               [255, 254, 0]])
ccm = mpl.colors.ListedColormap(cm/255.0)


def fraun_int(x):
    return (np.sin(int_x)/int_x)**2


# Read simulaiton files
data = pd.read_csv('../data/fraunhoffer.csv', header=None,
                   names=column_names)

amp_x = np.linspace(-20, 20, num=200)
int_x = np.linspace(-15, 15, num=200)
root_x = np.linspace(0, 16)

fraun_amplitude = np.sin(amp_x)/amp_x
fraun_roots = np.sin(root_x)/root_x
fraun_amp_prime = -np.sin(root_x)/root_x**2 + np.cos(root_x)/root_x
fraun_intensity = fraun_int(int_x)


# Plots
amp, ax = plt.subplots()

ax.plot(amp_x, fraun_amplitude)
ax.set(title='Fraunhoffer diffraction amplitude',
       xlabel='x', ylabel='Amplitude')
ax.grid(True)
ax.axhline(y=0, color='k')
amp.savefig('../plots/fraun_amplitude.png', dpi=200)

roots, ax1 = plt.subplots()

ax1.plot(root_x, fraun_roots, label='Amplitude')
ax1.plot(root_x, fraun_amp_prime, label='Derivative')
ax1.plot(data[root], np.zeros(4), label='Roots', marker='o', linestyle='')
ax1.set(title='Diffraction pattern roots',
        xlabel='x', ylabel='Amplitude')
ax1.grid(True, which='both')
ax1.axhline(y=0, color='k')
ax1.axvline(x=0, color='k')


ax1.axvline(x=0, color='k')
ax1.legend(loc='upper right')
roots.savefig('../plots/fraun_root.png', dpi=200)

gs = gridspec.GridSpec(2, 1, wspace=0.0, hspace=0.0, top=0.95,
                       height_ratios=[1, 3], bottom=0.05,
                       left=0.17, right=0.845)

intensity_plot = plt.figure()
ax2 = plt.subplot(gs[0])
ax3 = plt.subplot(gs[1])

intense_view = np.ones((20, 200))*fraun_intensity

ax2.imshow(intense_view, cmap=ccm)
ax2.axis('tight')
ax2.set_axis_off()
ax3.plot(int_x, fraun_intensity)
ax3.set(xlabel='x', ylabel='Intensity', xlim=[-15, 15])
ax3.grid(True)

ax3.axvline(x=0, color='red', linestyle='--')
for root in data[root]:
    ax3.axvline(x=float(root), color='red', linestyle='--')
    ax3.axvline(x=float(-root), color='red', linestyle='--')

intensity_plot.axes.append(ax2)
intensity_plot.axes.append(ax3)
intensity_plot.suptitle('Fraunhoffer Intensity', fontsize=14)
intensity_plot.subplots_adjust(top=0.95)
gs.tight_layout(intensity_plot, rect=[0, 0.03, 1, 0.95])
intensity_plot.savefig('../plots/fraun_int.png', dpi=200)
