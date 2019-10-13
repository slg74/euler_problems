#!/usr/bin/python

def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)


def paths(rights, downs):
    total = rights + downs
    combos = factorial(total) / factorial(rights) / factorial(downs)
    return combos


rights = 20
downs = 20
print paths(rights, downs)
