import sys

input = sys.stdin.readline

def floyd():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dp[i][k] == 1 and dp[k][j] == 1:
                    dp[i][j] = 1

n, m = map(int, input().split())
dp = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    dp[a][b] = 1

floyd()

ans = 0
for i in range(1, n + 1):
    light_cnt = heavy_cnt = 0
    for j in range(1, n + 1):
        if i == j: continue
        elif dp[i][j] == 1:
            light_cnt += 1
        elif dp[j][i] == 1:
            heavy_cnt += 1
    if light_cnt > n // 2 or heavy_cnt > n // 2:
        ans += 1

print(ans)