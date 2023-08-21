from sys import stdin
input = stdin.readline
S = int(input())

if S == 1:
    print(1)
else:
    sum = 0
    i = 1
    while S >= sum:
        sum = int(i*(i+1)//2)
        i += 1
    print(i-2)
