from sys import stdin
input = stdin.readline

T = int(input())

def factorial(n):
    num = 1
    for i in range(1, n+1):
        num *= i
    return num

for _ in range(T):
    N, M = map(int, input().split())
    print(factorial(M)//(factorial(N) * factorial(M-N)))