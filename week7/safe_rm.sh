#!/bin/bash

if [ "$1" ]; then
    mkdir "safe_rm_recycle"
    cp $1 [/root/os-2122/week7/safe_rm_recycle]
    rm -f ${pathToFile}
  
   
else 
    echo "ERROR"

fi
