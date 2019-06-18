#!/bin/bash

echo "1 -> Cambiar prioridad al proceso que mas consume:"
echo "2 -> Obtener PID del proceso que mas consume:"

read $1
# $1 = 1
proceso=`ps aux --width 30 --sort -rss | head -2 | grep "^manjaro" | tr -s ' ' | cut -d' ' -f2`
case $1 in
    1)
    echo "Prioridad cambiada al proceso: ${proceso}" >> trace.txt
    renice -20 $proceso ;;
   2)
    echo "PID del proceso que mas consume: ${proceso}"
    ;;
esac
