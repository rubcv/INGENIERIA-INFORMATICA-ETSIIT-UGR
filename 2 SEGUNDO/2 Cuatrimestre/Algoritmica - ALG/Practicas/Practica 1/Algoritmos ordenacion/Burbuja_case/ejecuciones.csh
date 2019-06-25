#!/bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 100
@ i = $inicio
echo > tiempos3.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./Burbuja $i ` >> tiempos3.dat
@ i += $incremento
end
