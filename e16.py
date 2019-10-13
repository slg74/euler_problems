#!/usr/bin/python

import math

n = str( '%d' % pow(2, 1000) )
nlist = []
for i in n:
    nlist.append(int(i))

print (sum(map(int, nlist )))
