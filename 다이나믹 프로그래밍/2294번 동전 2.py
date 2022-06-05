import sys

input = sys.stdin.readline
INF = sys.maxsize

n, k = map(int, input().split())
coin = []
for _ in range(n):
    coin.append(int(input()))

# dp[i] : i원을 만드는데 필요한 동전의 최소 개수
dp = [0] + [INF] * 10000

for c in coin:
    for i in range(c, k + 1):
        dp[i] = min(dp[i], dp[i - c] + 1)

print(dp[k] if dp[k] != INF else -1)