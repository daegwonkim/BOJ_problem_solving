import sys
from collections import deque

input = sys.stdin.readline
dy = (1, -1, 0, 0)
dx = (0, 0, 1, -1)

def bfs(i, j):
    que = deque()
    que.append((i, j))

    tmp = [(i, j)]
    while que:
        y, x = que.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if not 0 <= ny < n or not 0 <= nx < n:
                continue

            if not visited[ny][nx] and low <= abs(arr[y][x] - arr[ny][nx]) <= high:
                visited[ny][nx] = True
                que.append((ny, nx))
                tmp.append((ny, nx))
    
    return tmp

n, low, high = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

cnt = 0
while True:
    visited = [[False] * n for _ in range(n)]
    check = False

    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                visited[i][j] = True
                tmp = bfs(i, j)
                if len(tmp) > 1:
                    check = True
                    pop = sum([arr[y][x] for y, x in tmp]) // len(tmp)
                    for y, x in tmp:
                        arr[y][x] = pop
    
    if not check:
        break

    cnt += 1

print(cnt)