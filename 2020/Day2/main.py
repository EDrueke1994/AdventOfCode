# -*- coding: utf-8 -*-
"""
Day 2 Advent of Code - Passwords
"""

myfile = open("input.txt","r")

correct = 0
correct2 = 0

for line in myfile:
    dash = line.find("-")
    space = line.find(" ")
    num1 = line[:dash]
    num2 = line[dash+1:space]
    letter = line[space+1]
    password = line[space+4:]
    nletters = password.count(letter)
    if int(num1) <= nletters <= int(num2):
        correct = correct+1
    if password[int(num1)-1]==letter or password[int(num2)-1]==letter:
        if password[int(num1)-1] != password[int(num2)-1]:
            correct2 = correct2+1
        #print(password,num1,num2,letter)

print(correct)
print(correct2)