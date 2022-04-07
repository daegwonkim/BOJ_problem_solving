import sys
input = sys.stdin.readline

def check(y, x, num):
    for i in range(9):
        if num == board[y][i] or num == board[i][x]:
            return False

    square_y = y // 3 * 3
    square_x = x // 3 * 3

    for i in range(3):
        for j in range(3):
            if num == board[square_y + i][square_x + j]:
                return False
    
    return True

def bt(cnt):
    if cnt == len(point):
        for i in range(9):
            print(*board[i])

        exit(0)
    
    for i in range(1, 10):
        y = point[cnt][0]
        x = point[cnt][1]

        if check(y, x, i):
            board[y][x] = i
            bt(cnt + 1)
            board[y][x] = 0

board = [list(map(int, input().split())) for _ in range(9)]
point = []

for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            point.append((i, j))

bt(0)