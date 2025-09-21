reset
set grid
set autoscale

#------------- Graf 1 ----------------
set style data lines
set title "Funcion seno con ruido aleatorio"
set xlabel "Muestras"
set ylabel "seno(n) + ruido"
plot "signal.dat"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 2 ----------------
set style data steps
set title "Señal cuantizada a 5 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q5_signal.dat" with steps title "Nivel 5 bits"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 3 ----------------
set title "Señal cuantizada a 9 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q9_signal.dat" with steps title "Nivel 9 bits"
pause -1 "Presiona Enter para continuar..."

#------------- Graf 4 ----------------
set title "Señal cuantizada a 11 bits"
set xlabel "Muestras"
set ylabel "Señal cuantizada"
plot "q11_signal.dat" with steps title "Nivel 11 bits"
pause -1 "Fin de gráficas"
