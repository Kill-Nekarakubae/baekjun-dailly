from sys import stdin
input = stdin.readline
N, M = map(int, input().split())
data = list(map(int, input().split()))
data.sort()
visited  = [False]*N

stack = []

def DFS():
    if len(stack) == M:
        print(*stack)
        return
    
    duplicated_num = 0

    for i in range(N):
        if not visited[i] and duplicated_num != data[i]:
            if len(stack) != 0 and data[i] >= stack[-1]:
                stack.append(data[i])   
                visited[i] = True
                duplicated_num = data[i]
                DFS()
                stack.pop()
                visited[i] = False
            elif len(stack) == 0:
                stack.append(data[i])
                visited[i] = True
                duplicated_num = data[i]
                DFS()
                stack.pop()
                visited[i] = False

DFS()

    