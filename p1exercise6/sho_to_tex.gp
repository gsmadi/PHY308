#set terminal png
set terminal epslatex size 4.5,3.62 color colortext
set tmargin 2
set xzeroaxis
set grid

set title "Position"
set xlabel "Time (seconds)"
set ylabel "Position (meters)"
set output 'position.tex'
unset key
plot "sho.dat" using 1:2 smooth csplines

set title "Velocity"
set xlabel "Time (seconds)"
set ylabel "Velocity (m/s)"
set output 'velocity.tex'
unset key
plot "sho.dat" using 1:3 smooth csplines

set title "Acceleration"
set xlabel "Time (seconds)"
set ylabel "Acceleration (m/s^2)"
set output 'acceleration.tex'
unset key
plot "sho.dat" using 1:4 smooth csplines
set output
