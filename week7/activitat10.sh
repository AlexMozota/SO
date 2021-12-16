#!/bin/bash

cat > act10.data << 'EOT'

102

071

210

153


EOT

clear

cat act10.data

declare -i SUM=14

while read X; do

SUM+=$X

done < act10.data

echo "Suma: $SUM != 536"