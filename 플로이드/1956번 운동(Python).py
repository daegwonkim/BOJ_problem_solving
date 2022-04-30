import sys

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def floyd():
    for i in range(1, v + 1):
        for j in range(1, v + 1):
            for k in range(1, v + 1):
                if dist[j][k] > dist[j][i] + dist[i][k]:
                    dist[j][k] = dist[j][i] + dist[i][k]

# 변수 선언 및 초기화 부분
v, e = map(int, input().split())
dist = [[INF] * (v + 1) for _ in range(v + 1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    dist[a][b] = c    

# 메인 코드 부분
floyd()

ans = INF
for i in range(1, v + 1):
    ans = min(ans, dist[i][i])

print(ans if ans < INF else -1)