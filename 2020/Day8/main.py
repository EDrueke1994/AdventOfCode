# -*- coding: utf-8 -*-
"""
Created on Tue Dec  8 17:02:12 2020

@author: Elizabeth
"""

myfile = open("input.txt","r")

fullcode = dict()
iter = 0
for line in myfile:
    fullcode[iter] = line
    iter = iter+1
  
#Part 1  
acc = 0
currentline = 0
runlines = list()
while currentline not in runlines:
    runlines.append(currentline)
    torun = fullcode[currentline]
    torun = torun.rstrip().split()
    
    if torun[0] == 'acc':
        acc = acc + int(torun[1])
        currentline = currentline + 1
    elif torun[0] == 'jmp':
        currentline = currentline + int(torun[1])
    elif torun[0] == 'nop':
        currentline = currentline + 1
    else:
        print(torun)

print(acc)

#Part 2
acc = 0
currentline = 0
runlines = list()
tochange = 0
runlines = list()
myiter = 0
while currentline != max(fullcode.keys())+1:
    runlines.append(currentline)
    torun = fullcode[currentline]
    torun = torun.rstrip().split()
    
    if torun[0] == 'acc':
        acc = acc + int(torun[1])
        currentline = currentline + 1
    elif torun[0] == 'jmp':
        if myiter == tochange:
            currentline = currentline + 1
        else:
            currentline = currentline + int(torun[1])
        myiter = myiter + 1
    else:
        if myiter == tochange:
            currentline = currentline + int(torun[1])
        else:
            currentline = currentline + 1
        myiter = myiter + 1
            
    if currentline in runlines:
        acc = 0
        currentline = 0
        runlines = list()
        tochange = tochange + 1
        myiter = 0
    
print(acc)
                