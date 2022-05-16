import sys
from collections import deque

input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def init():
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                ry, rx = i, j
            elif board[i][j] == 'B':
                by, bx = i, j
    
    que.append([ry, rx, by, bx, 1])
    visited[ry][rx][by][bx] = True

def move(y, x, dy, dx):
    cnt = 0

    # 한 쪽 방향으로 이동할 수 있을 때까지 이동
    while board[y + dy][x + dx] != '#' and board[y][x] != 'O':
        y += dy
        x += dx
        cnt += 1

    # 최종 이동좌표(y, x)와 이동거리(cnt)
    return y, x, cnt

def bfs():
    init()

    while que:
        ry, rx, by, bx, cnt = que.popleft()

        if cnt > 10: break  # 실패 조건 : 이동 횟수가 10번을 초과한 경우

        for i in range(4):
            nry, nrx, rcnt = move(ry, rx, dy[i], dx[i]) # 빨간 구슬 이동
            nby, nbx, bcnt = move(by, bx, dy[i], dx[i]) # 파란 구슬 이동

            if board[nby][nbx] != 'O':  # 실패 조건이 아닌 경우 : 파란 구슬이 구멍에 빠지지 않은 경우
                if board[nry][nrx] == 'O':  # 성공 조건인 경우 : 빨간 구슬이 구멍에 빠진 경우
                    print(cnt)
                    return
                if nry == nby and nrx == nbx:   # 두 구슬이 겹친 경우
                    # 이동 거리가 더 짧은 구슬이 먼저 왔다는 의미이므로
                    # 두 구슬 중 이동 거리가 더 긴 구슬을 한 칸 뒤로 이동
                    if rcnt > bcnt:
                        nry -= dy[i]
                        nrx -= dx[i]
                    else:
                        nby -= dy[i]
                        nbx -= dx[i]
                if not visited[nry][nrx][nby][nbx]:
                    visited[nry][nrx][nby][nbx] = True
                    que.append([nry, nrx, nby, nbx, cnt + 1])
    
    print(-1)

n, m = map(int, input().split())
board = [list(input().rstrip()) for _ in range(n)]
que = deque()
visited = [[[[0] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]

bfs()