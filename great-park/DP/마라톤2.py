# from sys import stdin
# input = stdin.readline
# N, K = map(int, input().split())

# check_point = list()

# for i in range(N):
#     x,y = map(int, input().split())
#     check_point.append([x,y])

# def cal_distance(x1,y1,x2,y2):
#     return abs(x1-x2) + abs(y1-y2)

# distance = list([0] * N for _ in range(N))

# for i in range(N):
#     for j in range(N):
#         distance[i][j] = cal_distance(check_point[i][0], check_point[j][0], check_point[i][1], check_point[j][1])

# INF = 1e10

# dp = [[INF]*N for _ in range(K+1)]
# dp[0][0] = 0

# # K = 0
# for node_num in range(1, N):
#     dp[0][node_num] = dp[0][node_num-1] + dp[node_num-1][node_num] # 바로 이전 노드에서의 dp 값 + 바로 이전 노드와의 거리

# # 1~K
# for i in range(1, K+1):
#     dp[i][0] = 0
#     dp[i][1] = dp[i-1][1]
#     dp[i][i] = distance[0][i]

#     for j in range(1,N):
#         for m in range(i, 0, -1):
#             if j - m -1 < 0:
#                 continue
#             dp[i][j] = min(dp[i][j], dp[i - m][j - m - 1] + distance[j][j - m - 1], dp[i][j - 1] + distance[j - 1][j])

# print(dp[-1][-1])


# 실패