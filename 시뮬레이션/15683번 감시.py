import sys
import copy

input = sys.stdin.readline
INF = sys.maxsize

# 북, 동, 남, 서
dy = (-1, 0, 1, 0)
dx = (0, 1, 0, -1)
dir = [
    [],
    [[0], [1], [2], [3]],   # 한 쪽 방향 이동
    [[0, 2], [1, 3]],   # 양쪽 방향 이동
    [[0, 1], [1, 2], [2, 3], [0, 3]],   # 직각 방향 이동
    [[0, 1, 2], [0, 1, 3], [1, 2, 3], [0, 2, 3]],   # 세 방향 이동
    [[0, 1, 2, 3]]  # 네 방향 이동
]

def detect(_office, move, y, x):
    for point in move:
        ny, nx = y, x
        while True:
            ny += dy[point]
            nx += dx[point]

            if not 0 <= ny < n or not 0 <= nx < m:  # 맵의 끝인 경우
                break
            if _office[ny][nx] == 6:  # 벽으로 막힌 경우
                break
            elif _office[ny][nx] == 0:
                _office[ny][nx] = 7

def dfs(cnt, _office):
    global ans

    if cnt == len(cctv):    # 모든 cctv를 확인했다면
        tmp = 0
        for i in range(n):
            tmp += _office[i].count(0)  # 사각 지대의 갯수 구하기
        
        ans = min(ans, tmp)
        return

    copy_office = copy.deepcopy(_office)    # 배열 복사
    num, y, x = cctv[cnt]
    for move in dir[num]:
        detect(copy_office, move, y, x)
        dfs(cnt + 1, copy_office)
        copy_office = copy.deepcopy(_office)    # 배열 초기화

n, m = map(int, input().split())
office = [list(map(int, input().split())) for _ in range(n)]
ans = INF

# cctv번호 및 위치 저장
cctv = []
for i in range(n):
    for j in range(m):
        if office[i][j] in (1, 2, 3, 4, 5):
            cctv.append((office[i][j], i, j))

dfs(0, office)
print(ans)