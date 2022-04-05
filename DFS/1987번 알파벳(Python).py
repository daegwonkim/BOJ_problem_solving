import sys

def dfs(y, x, cnt):
    global max_value
    max_value = max(max_value, cnt)

    chk[paint[y][x]] = 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < r and 0 <= nx < c:
            if chk[paint[ny][nx]] == 0:
                dfs(ny, nx, cnt + 1)
                chk[paint[ny][nx]] = 0

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

r, c = map(int, input().split())
paint = [list(map(lambda x : ord(x) - 65, input())) for _ in range(r)]
chk = [0] * 26
max_value = 0

dfs(0, 0, 1)
print(max_value)