import sys
import heapq

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def dijkstra():
    heap = [[0, start]]
    dist[start] = 0

    while heap:
        cost, city = heapq.heappop(heap)

        if dist[city] < cost: continue

        for n_cost, n_city in bus[city]:
            if dist[n_city] > cost + n_cost:
                dist[n_city] = cost + n_cost
                heapq.heappush(heap, [dist[n_city], n_city])

# 변수 선언 및 초기화 부분
n = int(input())
m = int(input())

bus = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    bus[a].append([c, b])

start, end = map(int, input().split())
dist = [INF] * (n + 1)

# 메인 코드 부분
dijkstra()
print(dist[end])