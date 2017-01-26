set multiplot layout 3, 1 title "Simple Harmonic Oscillator" font ",14"
set tmargin 2
set xzeroaxis
set grid
set title "Position"
unset key
plot "sho.dat" using 1:2 smooth csplines
set title "Velocity"
unset key
plot "sho.dat" using 1:3  smooth csplines
set title "Acceleration"
unset key
plot "sho.dat" using 1:4  smooth csplines
pause -1
