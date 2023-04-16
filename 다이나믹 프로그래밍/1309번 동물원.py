MOD = 9901
n = int(input())
dp = [[0, 0] for _ in range(n + 1)]

dp[1][0] = 1
dp[1][1] = 2

for i in range(2, n + 1):
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD
    dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % MOD

print((dp[n][0] + dp[n][1]) % MOD)