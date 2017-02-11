set title "Errors vs. h"
set xlabel "h"
set ylabel "Error"
set key
set tmargin 2
set xzeroaxis
set grid
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2
set style line 3 linecolor rgb '#008c0e' linetype 1 linewidth 2
set style line 4 linecolor rgb '#ff9400' linetype 1 linewidth 2
set style line 5 linecolor rgb '#91009b' linetype 1 linewidth 2


# Save graph for Latex
set terminal epslatex size 4.5,3.62 color colortext
set out 'errors.tex'

# Plot errors against against
plot "../data/errors_0.dat" using 1:2 smooth csplines title "$x=0$" with lines linestyle 1, \
     "../data/errors_pi_4.dat" using 1:2 smooth csplines title "$x=\\frac{\\pi}{4}$" with lines linestyle 2, \
     "../data/errors_pi_4.dat" using 1:2 smooth csplines title "$x=\\frac{\\pi}{2}$" with lines linestyle 3, \
     "../data/errors_3pi_4.dat" using 1:2 smooth csplines title "$x=\\frac{3 \\pi}{4}$" with lines linestyle 4, \
     "../data/errors_pi.dat" using 1:2 smooth csplines title "$x=\\pi$" with lines linestyle 5

# Show output in window
set output
