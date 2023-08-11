from sys import stdin
input = stdin.readline
DIV = 1000000009
dp = list([0]*1001 for _ in range(1001))
dp[1][1] = 1
dp[2][1] = 1
dp[2][2] = 1
dp[3][1] = 1
dp[3][2] = 2
dp[3][3] = 1

for num in range(4, 1001):
    for count in range(1, num+1):
        # num-1 에서 1 추가하기 + num-2에서 2 추가히기 + num-3에서 3 추가하기
        dp[num][count] = (dp[num-1][count-1] + dp[num-2][count-1] + dp[num-3][count-1]) % DIV

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    ans = sum(dp[N][1:M + 1])% DIV
    print(ans)