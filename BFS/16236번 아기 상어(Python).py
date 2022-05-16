import sys
import heapq
from collections import deque

input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def bfs():
    eat_fish = []
    cnt = [[0] * n for _ in range(n)]

    que = deque([])
    que.append([pos_y, pos_x])

    while que:
        y, x = que.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                if cnt[ny][nx] == 0 and size >= arr[ny][nx]:
                    cnt[ny][nx] = cnt[y][x] + 1

                    if arr[ny][nx] != 0 and size > arr[ny][nx]:
                        heapq.heappush(eat_fish, [cnt[ny][nx], ny, nx])

                    que.append([ny, nx])
    
    return eat_fish

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
pos_y, pos_x = 0, 0
for i in range(n):
    for j in range(n):
        if arr[i][j] == 9:
            arr[i][j] = 0
            pos_y, pos_x = i, j

size = 2
ans, eat_cnt = 0, 0
while True:
    eat_fish = bfs()

    if not eat_fish: break

    cnt, pos_y, pos_x = eat_fish[0]
    ans += cnt
    eat_cnt += 1
    arr[pos_y][pos_x] = 0

    if size == eat_cnt:
        size += 1
        eat_cnt = 0

print(ans)