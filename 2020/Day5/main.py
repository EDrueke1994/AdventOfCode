# -*- coding: utf-8 -*-
"""
Created on Sat Dec  5 12:22:36 2020

@author: Elizabeth
"""
from math import floor
from math import ceil

myfile = open("input.txt","r")

highestid = 0
ids = list()

for line in myfile:
    line = line.strip()
    maxrow = 127
    minrow = 0
    maxcol = 7
    mincol = 0
    for ele in line:
        if ele == "F":
            maxrow = floor((maxrow-minrow)/2) + minrow
        elif ele == "B":
            minrow = ceil((maxrow-minrow)/2) + minrow
        elif ele == "L":
            maxcol = floor((maxcol-mincol)/2) + mincol
        elif ele == "R":
            mincol = ceil((maxcol-mincol)/2) + mincol
    seatid = maxrow*8 + maxcol
    
    ids.append(seatid)
    
    if seatid > highestid:
        highestid = seatid

print(highestid)

seats = min(ids)
foundseat = False
while foundseat == False:
    if seats not in ids:
        foundseat = True
    seats = seats+1
print(seats-1)