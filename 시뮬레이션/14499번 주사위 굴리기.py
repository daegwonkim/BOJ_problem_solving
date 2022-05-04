import sys

input = sys.stdin.readline

# [동, 서, 북, 남]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def roll(dir):
    tmp = dice[0]

    if dir == 1:    # 동쪽으로 굴리기
        dice[0], dice[3], dice[5], dice[2] = dice[3], dice[5], dice[2], tmp
    elif dir == 2:  # 서쪽으로 굴리기
        dice[0], dice[2], dice[5], dice[3] = dice[2], dice[5], dice[3], tmp
    elif dir == 3:  # 북쪽으로 굴리기
        dice[0], dice[4], dice[5], dice[1] = dice[4], dice[5], dice[1], tmp
    else:           # 남쪽으로 굴리기
        dice[0], dice[1], dice[5], dice[4] = dice[1], dice[5], dice[4], tmp

n, m, x, y, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
order = list(map(int, input().split()))

dice = [0] * 6
for i in range(k):
    dir = order[i]

    # 방향에 따른 이동 좌표 설정
    nx = x + dx[dir - 1]
    ny = y + dy[dir - 1]

    if not 0 <= nx < n or not 0 <= ny < m: continue

    roll(dir)   # 주사위 굴리기

    if board[nx][ny] == 0:
        board[nx][ny] = dice[5]
    else:
        dice[5] = board[nx][ny]
        board[nx][ny] = 0

    print(dice[0])
    x, y = nx, ny