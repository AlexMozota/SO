#!/bin/bash

N=$1


decimal_expr='^[0-9]+([.][0-9]+)?$'
decimal_expr1='^-[0-9]+([.][0-9]+)?$'

if ! [[ $N =~ $decimal_expr || $N =~ $decimal_expr1 ]] ; then


echo "error: Not a number" >&2;

exit 1

fi