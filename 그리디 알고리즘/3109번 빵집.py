import sys

input = sys.stdin.readline
dy = (-1, 0, 1)

def dfs(y, x):
    if x == c - 1:
        return True
    
    for i in range(3):
        ny = y + dy[i]
        nx = x + 1

        if not 0 <= ny < r or nx >= c or graph[ny][nx] == 'x':
            continue
        if not visited[ny][nx]:
            visited[ny][nx] = True
            if dfs(ny, nx):
                return True

    return False

r, c = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(r)]
visited = [[False] * c for _ in range(r)]
ans = 0

for i in range(r):
    if dfs(i, 0):
        ans += 1

print(ans)