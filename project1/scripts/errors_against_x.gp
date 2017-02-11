set title "Errors"
set xlabel "x"
set ylabel "Error"
set xrange [0:pi]
set key
set tmargin 2
set xzeroaxis
set grid
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2
set style line 3 linecolor rgb '#008c0e' linetype 1 linewidth 2
set xtics (0, '$\frac{\pi}{4}$' pi/4, '$\frac{\pi}{2}$' pi/2, '$\frac{3 \pi}{4}$' 3*pi/4, '$\pi$' pi)
# Save graph for Latex
set terminal epslatex size 4.5,3.62 color colortext
set output 'docs/derivative.tex'

# Plot errors against against
plot "data/derivative_error_5.0.dat" using 1:3 smooth csplines title "$h=5.0$" with lines linestyle 1, \
     "data/derivative_error_0.5.dat" using 1:3 smooth csplines title "$h=0.5$" with lines linestyle 2, \
     "data/derivative_error_0.05.dat" using 1:3 smooth csplines title "$h=0.05$" with lines linestyle 3
# Show output in window
set terminal wxt size 350,262 enhanced font 'Verdana,8' persist

# Plot errors against against
plot "data/derivative_error_5.0.dat" using 1:3 smooth csplines title "h = 5.0" with lines linestyle 1, \
     "data/derivative_error_0.5.dat" using 1:3 smooth csplines title "h = 0.5" with lines linestyle 2, \
     "data/derivative_error_0.05.dat" using 1:3 smooth csplines title "h = 0.05" with lines linestyle 3
