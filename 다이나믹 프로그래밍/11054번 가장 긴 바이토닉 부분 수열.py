import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dp_increase = [1] * n   # 가장 긴 증가하는 부분 수열의 길이
dp_decrease = [1] * n   # 가장 긴 감소하는 부분 수열의 길이

for i in range(n):
    for j in range(0, i):
        if arr[i] > arr[j]:
            dp_increase[i] = max(dp_increase[i], dp_increase[j] + 1)

for i in range(n - 1, -1, -1):
    for j in range(n - 1, i, -1):
        if arr[i] > arr[j]:
            dp_decrease[i] = max(dp_decrease[i], dp_decrease[j] + 1)

ans = 0

# (가장 긴 증가하는 부분 수열의 길이 + 가장 긴 감소하는 부분 수열의 길이) - 1 = 가장 긴 바이토닉 부분 수열의 길이
for i in range(n):
    ans = max(ans, dp_increase[i] + dp_decrease[i])
print(ans - 1)