import sys
from collections import deque

input = sys.stdin.readline
dy = (1, -1, 0, 0)
dx = (0, 0, 1, -1)

def bfs(start_y, start_x):
    que.append((start_y, start_x, 'S', 0))
    visited[start_y][start_x] = True

    while que:
        y, x, type, time = que.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if not 0 <= ny < r or not 0 <= nx < c:
                continue

            if graph[ny][nx] == '.' and not visited[ny][nx]:
                visited[ny][nx] = True
                que.append((ny, nx, type, time + 1))
            elif graph[ny][nx] == 'D' and type == 'S':
                return time + 1

    return "KAKTUS"

r, c = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(r)]
visited = [[False] * c for _ in range(r)]
que = deque()

start_y = start_x = 0
for i in range(r):
    for j in range(c):
        if graph[i][j] == 'S':
            start_y, start_x = i, j
        elif graph[i][j] == '*':
            que.append((i, j, '*', 0))

print(bfs(start_y, start_x))