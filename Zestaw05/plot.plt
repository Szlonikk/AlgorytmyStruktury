set term png
set output 'output.png'
set xlabel "Rozmiar tablicy"
set ylabel "Czas (nanosekundy)"

plot 'selection.txt' lt 5 lw 2 w l,'bubble.txt' lt 6 lw 2 w l, 'insertion.txt' lt 7 lw 2 w l

