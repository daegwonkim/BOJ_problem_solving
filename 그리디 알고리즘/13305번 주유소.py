import sys

n = int(input())
roads = list(map(int, input().split()))
prices = list(map(int, input().split()))

ans = 0
p = sys.maxsize
for i in range(n - 1):
    if prices[i] < p:
        ans += prices[i] * roads[i]
        p = prices[i]
    else:
        ans += p * roads[i]
print(ans)