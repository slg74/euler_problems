#!/usr/bin/bash
y=1901
num_sundays=0
while [ $y -le 2000 ]; do
    m=1
    echo "working on year $y..."
    while [ $m -le 12 ]; do
        val=`cal $m $y | awk -F, '{sum += $1} END {print sum}'`
        if [ $val -eq 46 -o $val -eq 75 ]; then
            let num_sundays=$num_sundays+1
        fi
        let m=$m+1
    done
    let y=$y+1
done
echo "$num_sundays sundays fall on the first of the month" 
echo "from 1 Jan 1901 to 31 Dec 2000"
