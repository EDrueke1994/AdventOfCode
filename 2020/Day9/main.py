# -*- coding: utf-8 -*-
"""
Created on Wed Dec  9 13:24:58 2020

@author: Elizabeth
"""

myfile = open("input.txt","r")

iter = 0
preamble = dict()
allnums = dict()
for line in myfile:
    line = line.rstrip()
    mynum = int(line)
    
    allnums[iter] = mynum
    
    if iter < 25:
        preamble[iter] = mynum
        iter = iter + 1
    else:
        found = False
        for k1,v1 in preamble.items():
            if found == False:
                for k2,v2 in preamble.items():
                    if k1 == k2:
                        continue
                    if v1+v2 == mynum:
                        found = True
        if found == True:
            preamble[iter%25] = mynum
            iter = iter + 1
        else:
            print(mynum)
            break     

rangemin = 0
rangemax = 0
for k1,v1 in allnums.items():
    mysum = v1
    for k2,v2 in allnums.items():
        if k2 > k1:
            mysum = mysum + v2
            if mysum == mynum:
                rangemin = k1
                rangemax = k2
                break
        
thelist = list()
iter = rangemin
while iter <= rangemax:
    thelist.append(allnums[iter])
    iter = iter + 1
    
print(max(thelist) + min(thelist))