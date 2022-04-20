import sys

# 전처리 부분
input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def bt(y, x, cnt):
    global ans

    visited[ord(board[y][x]) - ord('A')] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < r and 0 <= nx < c:
            index = ord(board[ny][nx]) - ord('A')
            if visited[index] == False:
                bt(ny, nx, cnt + 1)
                visited[index] = False
    
    ans = max(ans, cnt)

# 변수 선언 및 초기화 부분
r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]
visited = [0] * 26
ans = 0

# 메인 코드 부분
bt(0, 0, 1)
print(ans)