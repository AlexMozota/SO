#!/bin/bash

check_proc(){

N=$1

if [ "$N"  ]

then
echo "[$N] $(date)"

else
echo "[$$] $(date)"

fi

}

check_proc 

check_proc "1"