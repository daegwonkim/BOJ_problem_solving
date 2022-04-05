import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

n = int(input())
paint = [list(map(str, input())) for _ in range(n)]
chk = [[False] * n for _ in range(n)]

cnt = 0

def dfs(y, x):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < n:
            if paint[y][x] == paint[ny][nx] and chk[ny][nx] == False:
                chk[ny][nx] = True
                dfs(ny, nx)

for i in range(n):
    for j in range(n):
        if chk[i][j] == False:
            chk[i][j] = True
            dfs(i, j)
            cnt += 1

print(cnt, end = ' ')

cnt = 0
chk = [[False] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if paint[i][j] == 'G':
            paint[i][j] = 'R'

for i in range(n):
    for j in range(n):
        if chk[i][j] == False:
            chk[i][j] = True
            dfs(i, j)
            cnt += 1

print(cnt)