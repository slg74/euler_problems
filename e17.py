#!/usr/bin/python

import os, sys
lib_path = os.path.abspath(os.path.join('/home/Scott/pynumword'))
sys.path.append(lib_path)

import num2word
import re

def get_string_length(s):
    s = re.sub('-', ' ', num2word.to_card(s)) # change hyphens to spaces
    l = sum( i != ' ' for i in s)             # don't count spaces
    return l

total = 0
for i in range(1001):
    if i > 0:
        total = total + get_string_length(i)

print total

