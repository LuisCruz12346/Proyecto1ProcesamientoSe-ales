reset
set grid
set style data lines
set autoscale

#------------- Graf 1 ----------------
set title "Funcion seno con ruido aleatorio"
set xlabel "Muestras"
set ylabel "seno(n) + ruido"
plot "signal.dat"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 2 ----------------
set title "Señal cuantizada a 5 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q5_signal.dat"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 3 ----------------
set title "Señal cuantizada a 9 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q9_signal.dat"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 4 ----------------
set title "Señal cuantizada a 11 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q11_signal.dat"
pause -1 "Fin de gráficas"
