import sys
from collections import deque
input = sys.stdin.readline

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

m, n = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(n)]
queue = deque(())
ans = 0

def bfs():
    while queue:
        y, x = queue.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m and box[ny][nx] == 0:
                box[ny][nx] = box[y][x] + 1
                queue.append((ny, nx))

for i in range(n):
        for j in range(m):
            if box[i][j] == 1:
                queue.append((i, j))

bfs()

for i in range(n):
    for j in range(m):
        if box[i][j] == 0:
            print(-1)
            exit(0)
        ans = max(ans, box[i][j])

print(ans - 1)        