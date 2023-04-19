n = int(input())
a = list(map(int, input().split()))
dp = [1] * n

for i in range(n):
    for j in range(i):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))

LIS = []
cnt = max(dp)
for i in range(n - 1, -1, -1):
    if dp[i] == cnt:
        LIS.append(a[i])
        cnt -= 1

LIS.reverse()
print(*LIS)