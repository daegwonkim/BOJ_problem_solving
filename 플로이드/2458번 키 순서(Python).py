import sys

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def floyd():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                if graph[j][k] != 1 and (graph[j][i] == 1 and graph[i][k] == 1):
                    graph[j][k] = 1

# 변수 선언 및 초기화 부분
n, m = map(int, input().split())
graph = [[0] * (n + 1) for _ in range(n + 1)]
ans = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1

# 메인 코드 부분
floyd()

for i in range(1, n + 1):
    cnt  = 0

    for j in range(1, n + 1):
        cnt += graph[i][j] + graph[j][i]

    if cnt == n - 1:
        ans += 1

print(ans)