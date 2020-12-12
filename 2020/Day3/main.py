# -*- coding: utf-8 -*-
"""
Created on Thu Dec  3 12:41:31 2020

@author: Elizabeth
"""

myfile = open("input.txt","r")

ntrees1 = 0
ntrees2 = 0
ntrees3 = 0
ntrees4 = 0
ntrees5 = 0

count = 0

for line in myfile:
    
    line = line.strip()
    
    if line[count % len(line)] == "#":
        ntrees1 = ntrees1 + 1
    
    if line[count*3 % len(line)] == "#":
        ntrees2 = ntrees2 + 1
    
    if line[count*5 % len(line)] == "#":
        ntrees3 = ntrees3 + 1
    
    if line[count*7 % len(line)] == "#":
        ntrees4 = ntrees4 + 1

    if count % 2 == 0:
        if line[int(count/2) % len(line)] == "#":
            ntrees5 = ntrees5 + 1

    count = count + 1
    
mult = ntrees1*ntrees2*ntrees3*ntrees4*ntrees5
print(mult)
print(ntrees1, ntrees2, ntrees3, ntrees4, ntrees5)