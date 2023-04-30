import sys
from itertools import combinations
input = sys.stdin.readline
INF = sys.maxsize

n, m = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(n)]

# 집과 치킨집 위치 저장
home = [(i, j) for i in range(n) for j in range(n) if city[i][j] == 1]
chicken = [(i, j) for i in range(n) for j in range(n) if city[i][j] == 2]

ans = INF

# 최대 m개의 치킨집을 고르는 모든 경우의 수 고려
for coms in combinations(chicken, m):
    total = 0   # 도시의 치킨 거리

    # 각각의 집에 대해 주어진 조합에 따라 가장 작은 치킨 거리를 구함
    for hy, hx in home:
        dist = INF  # 집의 치킨 거리
        for cy, cx in coms:
            dist = min(dist, abs(hy - cy) + abs(hx - cx))

        total += dist
    ans = min(ans, total)   # 더 작은 치킨 거리로 갱신

print(ans)