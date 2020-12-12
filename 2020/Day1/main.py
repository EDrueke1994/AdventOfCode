# -*- coding: utf-8 -*-
"""
Advent of Code

Day 1 Challenge 1
"""

myfile = open("input.txt","r")

numbers = list()

for number in myfile:
    mynum = int(number)
    numbers.append(mynum)
    
#Find 2 numbers that sum to 2020
iter = 1
for num in numbers:
    diff = 2020 - num
    if diff in numbers:
        print(num*diff)
        
    for num2 in numbers[iter:]:
        diff2 = diff - num2
        if diff2 in numbers[iter:]:
            print(diff2*num2*num)