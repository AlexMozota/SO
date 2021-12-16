#!/bin/bash

x=$(pidof -x $(basename $0))
if [ $x  ]; then

# @TODO Substituir $x per les variables que continguin la informació.

echo "[ERROR]: Aquest script ja s’esta executant amb pid $x"

echo "[INFO]: Eliminant procés amb pid $x"

# @TODO Comanda per eliminar el procés amb pid $x, (tip: kill)
Kill -9 $x

fi

# @TODO Substituir $name i $pid per les variables que continguin la informació.

echo "[INFO]: Executant el script amb nom $1 amb el següent $$."
./$1


 

# @TODO Fer un recubriment amb el programa $name.