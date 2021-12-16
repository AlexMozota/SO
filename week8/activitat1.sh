#!/bin/bash

awk -F, '/Fire/ {print$2,$3,$4}' pokedex.csv