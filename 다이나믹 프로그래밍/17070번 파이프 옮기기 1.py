import sys
input = sys.stdin.readline

n = int(input())
house = [list(map(int, input().split())) for _ in range(n)]

# 0: 가로, 1: 세로, 2: 대각선
dp = [[[0] * n for _ in range(n)] for _ in range(3)]

# 파이프 시작 위치 및 방향 설정
dp[0][0][1] = 1

# DP를 수행하면서 현재 행의 윗 행을 사용해야하므로 첫 행을 먼저 초기화
for i in range(2, n):
    if house[0][i] == 0:
        dp[0][0][i] = dp[0][0][i - 1]

for y in range(1, n):
    for x in range(2, n):
        # 대각선 방향인 상태로 현재 위치에 올 수 있는 경우의 수
        if (house[y][x], house[y - 1][x], house[y][x - 1]) == (0, 0, 0):
            dp[2][y][x] = dp[0][y - 1][x - 1] + dp[1][y - 1][x - 1] + dp[2][y - 1][x - 1]
        
        # 가로 또는 세로 방향인 상태로 현재 위치에 올 수 있는 경우의 수
        if house[y][x] == 0:
            dp[0][y][x] = dp[0][y][x - 1] + dp[2][y][x - 1]
            dp[1][y][x] = dp[1][y - 1][x] + dp[2][y - 1][x]
    
# 파이프를 맵 끝으로 이동시키는 경우의 수는
# 각 방향인 상태로 맵 끝에 올 수 있는 경우의 수를 모두 더한 것과 같음
print(dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1])