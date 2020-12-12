# -*- coding: utf-8 -*-
"""
Created on Thu Dec 10 09:31:37 2020

@author: Elizabeth
"""
#import math

myfile = open("input.txt","r")

adapters = list()
adapters.append(0)
for line in myfile:
    line = line.rstrip()
    line = int(line)
    adapters.append(line)
    
adapters.sort()
adapters.append(adapters[len(adapters)-1]+3)

#Part 1
differences = list()
i = 1
while i < len(adapters):
    differences.append(adapters[i] - adapters[i-1])
    i = i + 1

print(differences.count(1)*(differences.count(3)))

#Part 2

#First create base
indices = list()
indices.append(0)
i = 1
while i < len(adapters):
    if adapters[i] - adapters[indices[len(indices)-1]] > 3:
        indices.append(i-1)
        i = i-1
    i = i+1
indices.append(len(adapters)-1)

#Then count number of in-between indices
i = 1
total = 1
while i < len(indices):
    mydiff = indices[i] - indices[i-1]
    if mydiff == 1:
        mycount = 1
    elif mydiff == 2:
        mycount = 2
        if adapters[indices[i+1]] - adapters[indices[i-1]+1] <= 3:
            mycount = mycount + 1
    else:
        mycount = 4
        check1 = False
        check2 = False
        if adapters[indices[i+1]] - adapters[indices[i-1]+1] <= 3:
            mycount = mycount + 1
            check1 = True
        if adapters[indices[i+1]] - adapters[indices[i-1]+2] <= 3:
            mycount = mycount + 1
            check2 = True
        if check1 and check2:
            mycount = mycount + 1
        
    total = total*mycount
    i = i+1

print(total)



#allcombos = list()
#
#j = 1
#while j < len(adapters):
#    if j==1:
#        mycombo = list()
#        mycombo.append(0)
#        i = j
#        while adapters[i] - mycombo[0] <= 3:
#            temp = mycombo.copy()
#            temp.append(i)
#            allcombos.append(temp)
#            i = i+1
#    else:
#        newcombos = list()
#        for combo in allcombos:
#            if combo[len(combo) - 1] == len(adapters)-1:
#                newcombos.append(combo)
#                continue
#            else:
#                i = combo[len(combo)-1]+1
#                while i < len(adapters) and adapters[i] - adapters[combo[len(combo)-1]] <= 3:
#                    temp = combo.copy()
#                    temp.append(i)
#                    newcombos.append(temp)
#                    i = i+1
#        if allcombos == newcombos:
#            break
#        else:
#            allcombos = newcombos
#    j = j+1
#    print(j,len(allcombos))
#    
#invalid = 0
#for combo in allcombos:
#    if combo[len(combo) - 1] != len(adapters) - 1:
#        invalid = invalid + 1
#        
#print(len(allcombos) - invalid)