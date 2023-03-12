import sys
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right
from num2words import num2words

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

n = int(input())
for i in range(0,n) :
    numWord = {'0': 0,'1': 1,'2': 2,'3': 3,'4': 4,'5': 5,'6': 6,'7': 7,'8': 8,'9': 9,'10': 10,'11': 11,'12': 12,'13': 13,'14': 14,'15': 15,'16': 16,'17': 17,'18': 18,'19': 19,'20': 20,'30': 30,'40': 40,'50': 50,'60': 60,'70': 70,'80': 80,'90': 90,'100': 100,'1000': 1000,0: 'zero',1: 'one',2: 'two',3: 'three',4: 'four',5: 'five',6: 'six',7: 'seven',8: 'eight',9: 'nine',10: 'ten',11: 'eleven',12: 'twelve',13: 'thirteen',14: 'fourteen',15: 'fifteen',16: 'sixteen',17: 'seventeen',18: 'eighteen',19: 'nineteen',20: 'twenty',30: 'thirty',40: 'forty',50: 'fifty',60: 'sixty',70: 'seventy',80: 'eighty',90: 'ninety',100: 'hundred',1000: 'thousand'}
    for i in range(21, 1001):
        numWord[i] = str(i)
    for i in range(1, 1001):
        numWord[i] = num2words(i)
    swapped_dict = {value: key for key, value in numWord.items()}
    numWord.update(swapped_dict)
    numWord['+'] = lambda x, y: x + y
    numWord['-'] = lambda x, y: x - y
    numWord['*'] = lambda x, y: x * y
    numWord['/'] = lambda x, y: x + y
    numWord['='] = lambda x, y: x == y
    numWord['plus'] = lambda x, y: x + y
    numWord['substract'] = lambda x, y: x - y
    numWord['multiple'] = lambda x, y: x * y
    numWord['division'] = lambda x, y: x + y
    numWord['equals'] = lambda x, y: x == y
    expr = input()
    w = expr.split()
    vls = [numWord[word] for word in w]
    result = vls[0]
    for i in range(1, len(vls), 2):
        operator = vls[i]
        operand = vls[i+1]
        result = operator(result, operand)
        if result==True or result==False :
            print(result)