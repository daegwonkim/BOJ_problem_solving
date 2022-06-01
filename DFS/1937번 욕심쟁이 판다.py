import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
dy = (1, -1, 0, 0)
dx = (0, 0, 1, -1)

def dfs(y, x):
    # 이미 이동할 수 있는 칸의 수를 구한 경우
    if dp[y][x] != 0:
        return dp[y][x]

    dp[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if not 0 <= ny < n or not 0 <= nx < n:
            continue
        if forest[y][x] < forest[ny][nx]:
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1)

    return dp[y][x]

n = int(input())
forest = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(n):
            ans = max(ans, dfs(i, j))

print(ans)