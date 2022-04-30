import sys
from collections import deque

# 전처리 부분
input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def bfs():
    que = deque()
    que.append([0, 0, 0])

    while que:
        y, x, w = que.popleft()

        if y == n - 1 and x == m - 1:
            return cnt[y][x][w]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m:
                if matrix[ny][nx] and w == 0:
                    cnt[ny][nx][1] = cnt[y][x][0] + 1
                    que.append([ny, nx, 1])
                elif not matrix[ny][nx] and not cnt[ny][nx][w]:
                    cnt[ny][nx][w] = cnt[y][x][w] + 1
                    que.append([ny, nx, w])
    
    return -1

# 메인 코드 부분
n, m = map(int, input().split())
matrix = [list(map(int, input().rstrip())) for _ in range(n)]
cnt = [[[0] * 2 for _ in range(m)] for _ in range(n)]

cnt[0][0][0] = 1
print(bfs())