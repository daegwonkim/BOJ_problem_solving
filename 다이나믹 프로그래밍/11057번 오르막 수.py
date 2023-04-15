MOD = 10007
n = int(input())
dp = [1] * 10

for i in range(2, n + 1):
    for j in range(1, 10):
        dp[j] += dp[j - 1]
print(sum(dp) % MOD)