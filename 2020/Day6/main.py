# -*- coding: utf-8 -*-
"""
Created on Sun Dec  6 10:14:59 2020

@author: Elizabeth
"""

myfile = open("input.txt","r")

yesquestions1 = ""
totalcount1 = 0

yesquestions2 = ""
totalcount2 = 0
newgroup = True

for line in myfile:
    line = line.rstrip()
    if line == "":
        totalcount1 = totalcount1 + len(yesquestions1)
        yesquestions1 = ""
        totalcount2 = totalcount2 + len(yesquestions2)
        newgroup = True
    elif newgroup == True:
        yesquestions1 = line
        yesquestions2 = line
        newgroup = False
    else:
        yesquestions1 = list(set(line + yesquestions1))
        yesquestions1 = ''.join([ele for ele in yesquestions1])
        yesquestions2 = list(set(line).intersection(set(yesquestions2)))
        yesquestions2 = ''.join([ele for ele in yesquestions2])
        
totalcount1 = totalcount1 + len(yesquestions1)
totalcount2 = totalcount2 + len(yesquestions2)

print(totalcount1)        
print(totalcount2)