import sys
from copy import deepcopy

input = sys.stdin.readline

def move(board, dir):
    # 동쪽으로 이동
    if dir == 0:
        for i in range(n):  # 모든 행에 대하여 수행
            top = n - 1
            for j in range(n - 2, -1, -1):
                if board[i][j]:
                    tmp = board[i][j]
                    board[i][j] = 0
                    if board[i][top] == 0:
                        board[i][top] = tmp
                    elif board[i][top] == tmp:
                        board[i][top] *= 2
                        top -= 1
                    else:
                        top -= 1
                        board[i][top] = tmp
    # 서쪽으로 이동
    elif dir == 1:
        for i in range(n):  # 모든 행에 대하여 수행
            top = 0
            for j in range(1, n):
                if board[i][j]:
                    tmp = board[i][j]
                    board[i][j] = 0
                    if board[i][top] == 0:
                        board[i][top] = tmp
                    elif board[i][top] == tmp:
                        board[i][top] *= 2
                        top += 1
                    else:
                        top += 1
                        board[i][top] = tmp
    # 남쪽으로 이동
    elif dir == 2:
        for j in range(n):  # 모든 열에 대하여 수행
            top = n - 1
            for i in range(n - 2, -1, -1):
                if board[i][j]:
                    tmp = board[i][j]
                    board[i][j] = 0
                    if board[top][j] == 0:
                        board[top][j] = tmp
                    elif board[top][j] == tmp:
                        board[top][j] *= 2
                        top -= 1
                    else:
                        top -= 1
                        board[top][j] = tmp
    # 북쪽으로 이동
    else:
        for j in range(n):  # 모든 열에 대하여 수행
            top = 0
            for i in range(1, n):
                if board[i][j]:
                    tmp = board[i][j]
                    board[i][j] = 0
                    if board[top][j] == 0:
                        board[top][j] = tmp
                    elif board[top][j] == tmp:
                        board[top][j] *= 2
                        top += 1
                    else:
                        top += 1
                        board[top][j] = tmp
    
    return board

# 알고리즘 부분
def select_dir(board, cnt):
    global ans

    if cnt == 5:
        for i in range(n):
            for j in range(n):
                ans = max(ans, board[i][j])
        return

    for i in range(4):
        tmp_board = move(deepcopy(board), i)    # 기존 보드의 형태를 유지하기 위함
        select_dir(tmp_board, cnt + 1)

# 메인 코드 부분
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

ans = 0
select_dir(arr, 0)
print(ans)