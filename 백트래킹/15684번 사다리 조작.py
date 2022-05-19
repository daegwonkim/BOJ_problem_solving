import sys

input = sys.stdin.readline

def check():
    for start in range(n):
        k = start
        for j in range(h):
            if board[j][k]:
                k += 1
            elif k > 0 and board[j][k - 1]:
                k -= 1
        if k != start: return False
    return True

def dfs(y, x, cnt):
    global ans

    if check():
        ans = min(ans, cnt)
        return
    elif cnt == 3 or ans <= cnt:
        return

    for i in range(y, h):
        if i == y: k = x
        else: k = 0

        for j in range(k, n - 1):
            if not board[i][j] and not board[i][j + 1]:
                if j > 0 and board[i][j - 1]: continue

                board[i][j] = True
                dfs(i, j + 2, cnt + 1)
                board[i][j] = False

n, m, h = map(int, input().split())
board = [[False] * n for _ in range(h)]

if m == 0:
    print(0)
    exit(0)

for _ in range(m):
    a, b = map(int, input().split())
    board[a - 1][b - 1] = True

ans = 4
dfs(0, 0, 0)
print(ans if ans < 4 else -1)