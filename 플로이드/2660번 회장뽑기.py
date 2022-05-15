import sys

input = sys.stdin.readline
INF = sys.maxsize

def floyd():
    for i in range(1, n + 1):
        dp[i][i] = 0

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dp[i][j] > dp[i][k] + dp[k][j]:
                    dp[i][j] = dp[i][k] + dp[k][j]

n = int(input())
dp = [[INF] * (n + 1) for _ in range(n + 1)]

while True:
    a, b = map(int, input().split())

    if a == -1 and b == -1:
        break

    dp[a][b] = 1
    dp[b][a] = 1

floyd()

result = []
for i in range(1, n + 1):
    result.append(max(dp[i][1:]))

m = min(result)
print(m, result.count(m))
for i, v in enumerate(result):
    if v == m:
        print(i + 1, end = ' ')