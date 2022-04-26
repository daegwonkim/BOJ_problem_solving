import sys

input = sys.stdin.readline

str_A, str_B = input().strip(), input().strip()
len_A, len_B = len(str_A), len(str_B)
dp = [[0] * (len_B + 1) for _ in range(len_A + 1)]

for i in range(1, len_A + 1):
    for j in range(1, len_B + 1):
        if str_A[i - 1] == str_B[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[len_A][len_B])