#!/usr/bin/env python3

#Bara gör det som står, summera x*x*x från x=1 till x=input()

print(sum([x*x*x for x in range(1,int(input())+1)]))