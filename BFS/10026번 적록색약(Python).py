import sys
from collections import deque

# 전처리 부분
input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def bfs(i, j):
    que = deque()
    que.append([i, j])

    while que:
        y, x = que.popleft()

        for k in range(4):
            ny = y + dy[k]
            nx = x + dx[k]

            if 0 <= ny < n and 0 <= nx < n:
                if paint[y][x] == paint[ny][nx] and visited[ny][nx] == False:
                    visited[ny][nx] = True
                    que.append([ny, nx])

def solve():
    cnt = 0

    for i in range(n):
        for j in range(n):
            if visited[i][j] == False:
                visited[i][j] = True
                bfs(i, j)
                cnt += 1

    print(cnt, end = " ")

# 변수 선언 및 초기화 부분
n = int(input())
paint = [list(map(str, input())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]

# 메인 코드 부분
solve()

for i in range(n):
    for j in range(n):
        if paint[i][j] == 'G':
            paint[i][j] = 'R'

visited = [[0] * n for _ in range(n)]
solve()