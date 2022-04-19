import sys

# 전처리 부분
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def dfs(y, x):
    if y == (m - 1) and x == (n - 1):
        return 1
    if visited[y][x] == True:
        return dp[y][x]

    visited[y][x] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < m and 0 <= nx < n:
            if graph[ny][nx] < graph[y][x]:
                dp[y][x] += dfs(ny, nx)

    return dp[y][x]

# 변수 선언 및 초기화 부분
m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]
dp = [[0] * n for _ in range(m)]
visited = [[0] * n for _ in range(m)]

# 메인 코드 부분
print(dfs(0, 0))