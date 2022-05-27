import sys

input = sys.stdin.readline

n = int(input())
line = [list(map(int, input().split())) for _ in range(n)]

# 첫번째 전봇대를 기준으로 오름차순 정렬
line.sort()

# 최장 증가 수열 구하기
dp = [1] * n
for i in range(n):
    for j in range(i):
        if line[i][1] > line[j][1] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

# 없애야 하는 전깃줄의 최소 개수 = 전체 전깃줄의 수 - 최대 전깃줄의 수
print(n - max(dp))