from sys import stdin
input = stdin.readline
N = int(input())
cost = list(map(int, input().split()))
max_card_count_in_pack = len(cost) 

dp = [0] * (N+1) # i개의 카드를 얻기 위한 금액의 최댓값
dp[1] = cost[0]

for card_count in range(1, N+1):
    if card_count <= max_card_count_in_pack:
        for id in range(card_count):
            dp[card_count] = max(dp[card_count], dp[card_count-id-1]+cost[id])
print(dp[-1])