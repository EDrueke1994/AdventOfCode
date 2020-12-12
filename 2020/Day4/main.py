# -*- coding: utf-8 -*-
"""
Created on Sat Dec  5 11:38:06 2020

@author: Elizabeth
"""
import string

myfile = open("input.txt","r")

nvalid = 0

#Passport fields
byr = 0
iyr = 0
eyr = 0
hgt = 0
hcl = 0
ecl = 0
pid = 0
cid = 0

for line in myfile:
    if line == '\n':
        #print(byr,iyr,eyr,hgt,hcl,ecl,pid)
        if byr != 0 and iyr != 0 and eyr != 0 and hgt != 0 and hcl != 0 and ecl != 0 and pid != 0:
            nvalid = nvalid + 1
        byr = 0
        iyr = 0
        eyr = 0
        hgt = 0
        hcl = 0
        ecl = 0
        pid = 0
        cid = 0
    values = line.split()
    for thing in values:
        thing.strip()
        if thing[:3] == "byr":
            temp = thing[4:]
            if temp.isdigit():
                if 1920 <= int(temp) <= 2002:
                    byr = temp
        elif thing[:3] == "iyr":
            temp = thing[4:]
            if temp.isdigit():
                if 2010 <= int(temp) <= 2020:
                    iyr = temp
        elif thing[:3] == "eyr":
            temp = thing[4:]
            if temp.isdigit():
                if 2020 <= int(temp) <= 2030:
                    eyr = temp
        elif thing[:3] == "hgt":
            temp = thing[4:]
            unit = temp[-2:]
            height = temp[:len(temp)-2]
            if unit == "in":
                if height.isdigit() and 59 <= int(height) <= 76:
                    hgt = temp
            elif unit == "cm":
                if height.isdigit() and 150 <= int(height) <= 193:
                    hgt = temp
        elif thing[:3] == "hcl":
            temp = thing[4:]
            #print("1",temp)
            if temp[0] == "#" and len(temp) == 7:
                #print("2",temp)
                ishex = True
                for dig in temp[1:]:
                   # print(dig,dig in string.hexdigits)
                    if dig not in string.hexdigits:
                        ishex =False
                if ishex == True:
                    hcl = temp
        elif thing[:3] == "ecl":
            temp = thing[4:]
            if temp in ["amb","blu","brn","gry","grn","hzl","oth"]:
                ecl = temp
        elif thing[:3] == "pid":
            temp = thing[4:]
            if len(temp) == 9 and temp.isdigit():
                pid = temp
        elif thing[:3] == "cid":
            cid = thing[4:]

if byr != 0 and iyr != 0 and eyr != 0 and hgt != 0 and hcl != 0 and ecl != 0 and pid != 0:
    nvalid = nvalid + 1

print(nvalid)
    