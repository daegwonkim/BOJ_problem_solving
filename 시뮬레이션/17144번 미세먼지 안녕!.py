import sys

sys.stdin.readline

def spread():
    dy = (1, -1, 0, 0)
    dx = (0, 0, 1, -1)

    tmp_room = [[0] * c for _ in range(r)]
    for y in range(r):
        for x in range(c):
            if room[y][x] > 0:
                tmp = 0
                for k in range(4):
                    ny = y + dy[k]
                    nx = x + dx[k]
                    if 0 <= ny < r and 0 <= nx < c and room[ny][nx] != -1:
                        tmp_room[ny][nx] += room[y][x] // 5
                        tmp += room[y][x] // 5
                room[y][x] -= tmp

    for i in range(r):
        for j in range(c):
            room[i][j] += tmp_room[i][j]

def rotate(move, cleaner):
    dir = prev = 0
    y, x = cleaner, 1
    while True:
        ny = y + move[dir][0]
        nx = x + move[dir][1]

        if room[y][x] == -1:
            break
        if not 0 <= ny < r or not 0 <= nx < c:  #맵 끝에 다다를 시 방향을 바꿈
            dir += 1
            continue

        room[y][x], prev = prev, room[y][x]
        y, x = ny, nx

def count():
    result = 0
    for i in range(r):
        for j in range(c):
            if room[i][j] > 0:
                result += room[i][j]

    return result

r, c, t = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(r)]

up_move = ((0, 1), (-1, 0), (0, -1), (1, 0))    #위쪽 공기청정기 순환
down_move = ((0, 1), (1, 0), (0, -1), (-1, 0))  #아래쪽 공기청정기 순환

# 공기청정기 위치 확인
up = down = 0
for i in range(r):
    if room[i][0] == -1:
        up = i
        down = i + 1
        break

for _ in range(t):
    spread()    #미세먼지 확산
    rotate(up_move, up) #시계방향 회전
    rotate(down_move, down) #반시계방향 회전

print(count())