#!/bin/bash
cat /etc/passwd | sed '/^#/d' | awk 'NR%2==0 { print }' | cut -d ':' -f 1 | rev | sort -r | awk -v F1=$FT_LINE1 -v F2=$FT_LINE2 "F1<=NR && NR<=F2" | tr "\n" "," | sed 's/,/, /g' | sed 's/, $/./' | tr -d "\n"
exit
