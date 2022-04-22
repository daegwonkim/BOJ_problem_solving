import sys
from collections import deque

# 전처리 부분
input = sys.stdin.readline
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

# 알고리즘 부분
def dummy():
    y, x = 1, 1
    time, dir = 0, 0

    board[y][x] = 1
    dq = deque([[y, x]])

    while True:
        time += 1

        y = y + dy[dir]
        x = x + dx[dir]

        if y < 1 or y > n or x < 1 or x > n or board[y][x] == 1: break

        if board[y][x] == 0:
            tail_y, tail_x = dq.popleft()
            board[tail_y][tail_x] = 0

        board[y][x] = 1
        dq.append([y, x]) 
        
        if time in times.keys():
            if times[time] == 'L':
                dir = (dir + 1) % 4
            else: dir = (dir + 3) % 4

    return time

# 변수 선언 및 초기화 부분
n = int(input())
k = int(input())
board = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(k):
    r, c = map(int, input().split())
    board[r][c] = 2
l = int(input())
times = {}
for _ in range(l):
    t, d = input().split()
    times[int(t)] = d

# 메인 코드 부분
print(dummy())