# -*- coding: utf-8 -*-
"""
Created on Tue Dec  8 15:23:18 2020

@author: Elizabeth
"""
myfile = open("input.txt","r")

searchfor = 'shiny gold'

bagallocations = dict()

for line in myfile:
    line = line.rstrip()
    mylist = line.split(' bags contain ')
    
    mykey = mylist[0]
    myvalues = mylist[1]
    myvalues = myvalues.split(', ')
    myvalues[len(myvalues)-1] = myvalues[len(myvalues)-1].strip('.')
    
    for iter in range(len(myvalues)):
        myvalues[iter] = myvalues[iter].rstrip('bags')
        myvalues[iter] = myvalues[iter].rstrip('bag')
        myvalues[iter] = myvalues[iter].rstrip()
    
    bagallocations[mykey] = myvalues
    
#Part 1
ncombos = 0
nextsearch = list()
nextsearch.append(searchfor)
allpossibilities = list()
while nextsearch != list():
    currentsearch = nextsearch
    nextsearch = list()
    for key,values in bagallocations.items():
        mylist = list()
        for item in values:
            mylist.append(item[2:])
        for item in currentsearch:
            if item in mylist:
                nextsearch.append(key)
                allpossibilities.append(key)
                ncombos = ncombos+1

print(len(set(allpossibilities)))

#Part 2
nbags = 0
nextsearch = dict()
nextsearch[searchfor] = 1
while nextsearch != dict():
    currentsearch = nextsearch
    nextsearch = dict()
    for key in currentsearch.keys():
        for bag in bagallocations[key]:
            if bag == 'no other':
                continue
            else:
                nbags = nbags + currentsearch[key]*int(bag[0])
                if bag[2:] in nextsearch.keys():
                    nextsearch[bag[2:]] = nextsearch[bag[2:]] + currentsearch[key]*int(bag[0])
                else:
                    nextsearch[bag[2:]] = currentsearch[key]*int(bag[0])

print(nbags)