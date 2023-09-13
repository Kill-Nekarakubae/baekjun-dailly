from sys import stdin
from collections import deque
input = stdin.readline

N, M = map(int, input().split())
k_x, k_y = map(int, input().split())
target = list() 

# for _ in range(M):
#     x,y = map(int, input().split())
#     target.append([x,y])

dx = [-2,-2,-1,-1,1,1,2,2]
dy = [-1,1,-2,2,-2,2,-1,1]
visited = [[-1]*(N+1) for _ in range(N+1)]

def BFS(): 
    queue = deque()
    queue.append([k_x, k_y])
    visited[k_y][k_x] = 0

    while queue:
        x,y = queue.popleft()
        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if 0 < nx <= N and 0 < ny <= N:
                if visited[ny][nx] == -1:
                    queue.append([nx,ny])
                    visited[ny][nx] = visited[y][x] + 1

BFS()
answer = list()

for _ in range(M):
    x,y = map(int, input().split())
    print(visited[y][x], end= ' ')