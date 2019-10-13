#!/usr/bin/python

NAMES = open('names.txt').read().split(',')

SORTED = sorted(NAMES)

def sum_word_value(n):
    sum = 0
    for i in n:
        if i.isalpha():
            sum += ord(i)-64
    return sum

position = total = 0
for i in SORTED:
    position += 1
    total += position * sum_word_value(i)

print total
