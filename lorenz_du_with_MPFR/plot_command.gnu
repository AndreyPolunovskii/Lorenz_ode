#!/usr/bin/gnuplot

set term eps
set output "X.eps"
set grid xtics ytics
set bar 0
set xzeroaxis lt -1
set yzeroaxis lt -1


plot "output_data.txt" using 1:2 linewidth 1  with lines  title "x(t)" 
plot "output_data.txt" using 1:3 linewidth 1  with lines title "y(t)"
plot "output_data.txt" using 1:4 linewidth 1  with lines title "z(t)"



set output "fasov.eps"

plot "output_data.txt" using 2:3 linewidth 1  with lines title "x/y"
plot "output_data.txt" using 3:4 linewidth 1  with lines title "y/z"
plot "output_data.txt" using 2:4 linewidth 1  with lines title "x/z"
