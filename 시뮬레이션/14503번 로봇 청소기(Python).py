import sys

# 전처리 부분
input = sys.stdin.readline
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

# 변수 선언 및 초기화 부분
n, m = map(int, input().split())
r, c, d = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
cnt = 0

# 메인 코드 부분
while(True):
    check = False

    if board[r][c] == 0:
        board[r][c] = 2
        cnt += 1

    for i in range(4):
        d = (d + 3) % 4
        y = r + dy[d]
        x = c + dx[d]

        if board[y][x] == 0:
            r, c = y, x
            check = True
            break
    
    if check == False:
        tmp_d = (d + 2) % 4
        y = r + dy[tmp_d]
        x = c + dx[tmp_d]

        if board[y][x] == 1: break
        r, c = y, x

print(cnt)