MOD = 1000000000
n, k = map(int, input().split())
dp = [[0] * (n + 1) for _ in range(k + 1)]
dp[1] = [1] * (n + 1)

for i in range(2, k + 1):
    for j in range(n + 1):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        dp[i][j] %= MOD

print(dp[k][n])