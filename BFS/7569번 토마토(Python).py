import sys
from collections import deque

# 전처리 부분
input = sys.stdin.readline
dz = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dx = [0, 0, 0, 0, 1, -1]

# 알고리즘 부분
def bfs():
    while que:
        z, y, x = que.popleft()

        for i in range(6):
            nz = z + dz[i]
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= nz < h and 0 <= ny < n and 0 <= nx < m:
                if box[nz][ny][nx] == 0:
                    box[nz][ny][nx] = box[z][y][x] + 1
                    que.append([nz, ny, nx])

# 변수 선언 및 초기화 부분
m, n, h = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
que = deque()
ans = 0

# 메인 코드 부분
for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                que.append([i, j, k])

bfs()

for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 0:
                print(-1)
                exit()
            if ans < box[i][j][k]:
                ans = box[i][j][k]

print(ans - 1)