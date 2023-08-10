from sys import stdin
input = stdin.readline
N = int(input())
data = list(map(int, input().split()))

start, end = 0, N-1
sum = abs(data[start] + data[end])
answer = [start, end]

while start < end:
    cur_sum = data[start] + data[end]
    # print(f'cur_sum: {cur_sum}, start: {data[start]}, end: {data[end]}')

    if abs(cur_sum) < sum:
        sum = abs(cur_sum)
        answer = start, end
    if cur_sum < 0:
        start +=1
    elif cur_sum > 0:
        end -=1
    else:
        break
print(data[answer[0]], data[answer[1]])