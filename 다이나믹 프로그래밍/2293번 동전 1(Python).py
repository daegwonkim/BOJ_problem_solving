import sys

input = sys.stdin.readline

n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)]
dp = [0] * (k + 1)
dp[0] = 1

for i in coin:
    for j in range(i, k + 1):
        dp[j] += dp[j - i]  # j원을 만드는 경우의 수 = 지금까지 구한 j원을 만드는 경우의 수 + (j - i)원을 만드는 경우의 수

print(dp[k])