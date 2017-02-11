set tmargin 2
set xzeroaxis
set grid
# reset linetypes to base dash patterns
set for [i=1:5] linetype i dt i
set title "Actual vs. Computed derivative"
set xlabel "x"
set ylabel "y"
set xrange [0:pi]
set key
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 1
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 1
set style line 3 linecolor rgb '#008c0e' linetype 1 linewidth 1
set style line 4 linecolor rgb '#000000' linetype 3 linewidth 2
set xtics (0, '$\frac{\pi}{4}$' pi/4, '$\frac{\pi}{2}$' pi/2, '$\frac{3 \pi}{4}$' 3*pi/4, '$\pi$' pi)
f(x) = cos(x) # Actual

# Save plot for Latex
set terminal epslatex size 4.5,3.62 color colortext
set output 'docs/actual_computed.tex'

plot "data/derivative_error_5.0.dat" using 1:2 smooth csplines title "Computed with $h=5.0$" with lines linestyle 1, \
     "data/derivative_error_0.5.dat" using 1:2 smooth csplines title "Computed with $h=0.5$" with lines linestyle 2, \
     "data/derivative_error_0.05.dat" using 1:2 smooth csplines title "Computed with $h=0.5$" with lines linestyle 3, \
     f(x) title "Actual" with lines linestyle 4

# Show plot in window
set terminal wxt size 350,262 enhanced font 'Verdana,8' persist

# Plot Actual against Computed
plot "data/derivative_error_5.0.dat" using 1:2 smooth csplines title "Computed with h = 5.0" with lines linestyle 1, \
     "data/derivative_error_0.5.dat" using 1:2 smooth csplines title "Computed with h = 0.5" with lines linestyle 2, \
     "data/derivative_error_0.05.dat" using 1:2 smooth csplines title "Computed with h = 0.5" with lines linestyle 3, \
     f(x) title "Actual" with lines linestyle 4
