import sys

# 전처리 부분
input = sys.stdin.readline
# pypy3의 경우 재귀 사용시 메모리 사용량이 높기 때문에 재귀 허용 깊이를 낮춰주어 메모리 초과 발생 방지
sys.setrecursionlimit(10 ** 5)
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def melt(y, x):
    height = 0

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < m:
            if not arr[ny][nx]:
                height += 1
    
    return y, x, height

# 알고리즘 부분
def dfs(y, x):
    visited[y][x] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < m:
            if not visited[ny][nx] and arr[ny][nx]:
                dfs(ny, nx)

# 메인 코드 부분
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
ans = 0

while True:
    ans += 1

    reduce = []
    for i in range(n):
        for j in range(m):
            if arr[i][j]:
                y, x, h = melt(i, j)    # 빙하가 녹게 될 높이 확인
                if h:
                    reduce.append([y, x, h])

    # 빙하 녹이기
    for y, x, h in reduce:
        arr[y][x] = max(arr[y][x] - h, 0)

    cnt = 0
    visited = [[0] * m for _ in range(n)]

    # 빙하가 녹고 난 이후 덩어리 개수 확인
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and arr[i][j]:
                cnt += 1

                if cnt == 2:
                    break

                dfs(i, j)

    # 덩어리가 2개 이상인 경우
    if cnt > 1:
        break

    # 빙하가 모두 녹을 때까지 덩어리가 1개인 경우
    if not sum(map(sum, arr[1:-1])):
        ans = 0
        break

print(ans)