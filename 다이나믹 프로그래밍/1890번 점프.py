n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * n for _ in range(n)]

dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if (dp[i][j] == 0) or (i == n - 1 and j == n - 1):
            continue

        # 오른쪽으로 점프할 수 있는 경우
        if j + board[i][j] < n:
            dp[i][j + board[i][j]] += dp[i][j]

        # 왼쪽으로 점프할 수 있는 경우
        if i + board[i][j] < n:
            dp[i + board[i][j]][j] += dp[i][j]

print(dp[n - 1][n - 1])