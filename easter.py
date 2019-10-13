#!/usr/bin/python

from math import floor
import datetime
import sys

""" calculate the date of easter                  """
""" Meeus / Jones / Butcher algorithm             """
""" From Practical Astronomy With Your Calculator """

def Gregorian(Y):
    a = Y % 19
    b = floor(Y/100)
    c = Y % 100
    d = floor(b/4)
    e = b % 4
    f = floor((b+8)/25)
    g = floor((b-f+1)/3)
    h = (19*a+b-d-g+15)%30
    i = floor(c/4)
    k = c % 4
    L = (32+2*e+2*i-h-k)%7
    m = floor((a+11*h+22*L)/451)
    month = int(floor((h+L-7*m+114)/31))
    day = int(((h+L-7*m+114) % 31) + 1)

    return month, day

def Julian(Y):
    a = Y % 4
    b = Y % 7
    c = Y % 19
    d = (19*c + 15) % 30
    e = (2*a + 4*b - d + 34) % 7
    f = d + e + 114
    f, g = f/31, f%31

    return f, g+1

def main():
    for i in range(1000, 2050):
        m, d = Gregorian(i)
        mj, dj = Julian(i)
        print "Gregorian: " + str(i) + " " + str(m) + " " + str(d) + "\tJulian: " +  str(i) + " " + str(mj) + " " + str(dj)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        sys.exit()
        
