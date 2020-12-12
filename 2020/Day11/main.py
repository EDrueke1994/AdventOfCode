# -*- coding: utf-8 -*-
"""
Created on Fri Dec 11 07:41:33 2020

@author: Elizabeth
"""
def count_occupied_adjacent(mydict,k,v,i):
    count = 0
 
    if i > 0 and v[i-1] == '#':
        count = count + 1
    if i < len(v)-1 and v[i+1] == '#':
        count = count + 1
    
    if 0<k<myiter-1:
        above = mydict[k-1]
        below = mydict[k+1]
    elif k == 0:
        above = 'aaaaaaaa'
        below = mydict[k+1]
    else:
        above = mydict[k-1]
        below = 'aaaaaaaa'
                
    if 0<i<len(v)-1:
        above = above[i-1:i+2]
        below = below[i-1:i+2]
    elif i==0:
        above = above[:2]
        below = below[:2]
    else:
        above = above[-2:]
        below = below[-2:]
                
    count = count + above.count('#')
    count = count + below.count('#')
    
    return count   
    
def count_occupied_visible(mydict,k,v,i):
    count = 0
    
    #Look right
    temp = i + 1
    foundseat = False
    while temp < len(v) and foundseat == False:
        if v[temp] == '#':
            count = count + 1
            foundseat = True
        elif v[temp] == 'L':
            foundseat = True
        temp = temp + 1
        
    #Look left
    temp = i-1
    foundseat = False
    while temp >= 0 and foundseat == False:
        if v[temp] == '#':
            count = count + 1
            foundseat = True
        elif v[temp] == 'L':
            foundseat = True
        temp = temp - 1
        
    #Look up
    temp = k - 1
    foundseat = False
    while temp >= 0 and foundseat == False:
        row = mydict[temp]
        if row[i] == '#':
            count = count + 1
            foundseat = True
        elif row[i] == 'L':
            foundseat = True
        temp = temp - 1
        
    #Look down
    temp = k+1
    foundseat = False
    while temp < len(mydict.keys()) and foundseat == False:
        row = mydict[temp]
        if row[i] == '#':
            count = count + 1
            foundseat = True
        elif row[i] == 'L':
            foundseat = True
        temp = temp + 1
        
    #Diagonal up-left
    temp = i-1
    temp2 = k-1
    foundseat = False
    while temp >= 0 and temp2 >= 0 and foundseat == False:
        row = mydict[temp2]
        if row[temp] == '#':
            count = count + 1
            foundseat = True
        elif row[temp] == 'L':
            foundseat = True
        temp = temp-1
        temp2 = temp2-1
    
    #Diagonal up-right
    temp = i+1
    temp2 = k-1
    foundseat = False
    while temp < len(v) and temp2 >= 0 and foundseat == False:
        row = mydict[temp2]
        if row[temp] == '#':
            count = count + 1
            foundseat = True
        elif row[temp] == 'L':
            foundseat = True
        temp = temp + 1
        temp2 = temp2 - 1
        
    #Diagonal down-left
    temp = i-1
    temp2 = k+1
    foundseat = False
    while temp >= 0 and temp2 < len(mydict.keys()) and foundseat == False:
        row = mydict[temp2]
        if row[temp] == '#':
            count = count + 1
            foundseat = True
        elif row[temp] == 'L':
            foundseat = True
        temp = temp - 1
        temp2 = temp2 + 1
        
    #Diagonal down-right
    temp = i+1
    temp2 = k+1
    foundseat = False
    while temp < len(v) and temp2 < len(mydict.keys()) and foundseat == False:
        row = mydict[temp2]
        if row[temp] == '#':
            count = count + 1
            foundseat = True
        elif row[temp] == 'L':
            foundseat = True
        temp = temp + 1
        temp2 = temp2 + 1
        
    return count   
    
myfile = open("input.txt","r")

layout = dict()

myiter = 0
for line in myfile:
    line = line.rstrip()
    layout[myiter] = line
    myiter = myiter+1
    
#Part1
firstpass = True
newlayout = dict()
loopn = 0
layout1 = layout
while newlayout != layout1:
    loopn = loopn+1
    #print(loopn)
    if not firstpass:
        layout1 = newlayout
        newlayout = dict()
    firstpass = False
    for k,v in layout1.items():
        newrow = str()
        for i in range(len(v)):
            adjoccupied = count_occupied_adjacent(layout1,k,v,i)
            if v[i] == 'L':
                if adjoccupied == 0:
                    newrow = newrow + '#'
                else:
                    newrow = newrow + 'L'
            elif v[i] == '.':
                newrow = newrow + '.'
            elif v[i] == '#':
                if adjoccupied >= 4:
                    newrow = newrow + 'L'
                else:
                    newrow = newrow + '#'
        if len(newrow) != len(v):
            print('Error')
            break
        newlayout[k] = newrow
        #print(k,newrow.count('.'),newrow.count('L'),newrow.count('#'))

occupied1 = 0
for row in layout1.values():       
    occupied1 = occupied1 + row.count('#')

print(occupied1)        

#Part2
firstpass = True
newlayout = dict()
loopn = 0
layout2 = layout
while newlayout != layout2:
    loopn = loopn+1
    print(loopn)
    if not firstpass:
        layout2 = newlayout
        newlayout = dict()
    firstpass = False
    for k,v in layout2.items():
        newrow = str()
        for i in range(len(v)):
            visoccupied = count_occupied_visible(layout2,k,v,i)
            if v[i] == 'L':
                if visoccupied == 0:
                    newrow = newrow + '#'
                else:
                    newrow = newrow + 'L'
            elif v[i] == '.':
                newrow = newrow + '.'
            elif v[i] == '#':
                if visoccupied >= 5:
                    newrow = newrow + 'L'
                else:
                    newrow = newrow + '#'
        if len(newrow) != len(v):
            print('Error')
            break
        newlayout[k] = newrow
        #print(k,newrow.count('.'),newrow.count('L'),newrow.count('#'))

occupied2 = 0
for row in layout2.values():       
    occupied2 = occupied2 + row.count('#')

print(occupied2)   