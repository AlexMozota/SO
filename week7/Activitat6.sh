#!/bin/bash

check_proc(){

N=$1

if [ N = 0 ]

then
echo "$$"
else
echo "$N"
fi

}

check_proc

check_proc "1"