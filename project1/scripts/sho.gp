set xlabel "Position"
set ylabel "Velocity/Acceleration"
set key
set tmargin 2
set xzeroaxis
set grid
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2

# Save graph for Latex
set terminal epslatex size 3,2.5 color colortext
set output "sho10.tex"

# Plot errors against against
plot "../data/sho.dat" using 1:2 title "Velocity" with lines linestyle 1, \
     "../data/sho.dat" using 1:3 title "Acceleration" with lines linestyle 2

# Show output in window
set terminal wxt size 350,262 enhanced font 'Verdana,8' persist

# Plot errors against against
plot "../data/sho.dat" using 1:2 title "" with lines linestyle 1, \
     "../data/sho.dat" using 1:3 title "$x=\\frac{\\pi}{4}$" with lines linestyle 2
