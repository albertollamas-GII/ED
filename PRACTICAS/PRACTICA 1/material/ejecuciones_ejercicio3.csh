#!/bin/csh 
@ inicio = 1024
@ fin = 1000000000

alias MATH 'set \!:1 = `echo "\!:3-$" | bc -l`' 
set ejecutable = ejercicio3
set salida = tiempos_ej3.dat
@ factor = 4
@ i = $inicio

echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
   
   if ($i >= 65536) then
    @ factor = 2
   endif 
   MATH  nuevo = $i*$factor
   
   @ i = $nuevo 
   
end
