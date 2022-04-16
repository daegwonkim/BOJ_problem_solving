import sys
import heapq

# 전치리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def dijkstra():
    heap = [[0, k]]
    dist[k] = 0

    while heap:
        cost, node = heapq.heappop(heap)

        if dist[node] < cost: continue
        
        for n_cost, n_node in edges[node]:
            if dist[n_node] > cost + n_cost:
                dist[n_node] = cost + n_cost
                heapq.heappush(heap, [dist[n_node], n_node])

# 변수 선언 및 초기화 부분
v, e = map(int, input().split())
k = int(input())
edges = [[] for _ in range(v + 1)]
dist = [INF] * (v + 1)

for _ in range(e):
    a, b, c = map(int, input().split())
    edges[a].append([c, b])

# 메인 코드 부분
dijkstra()

for i in range(1, v + 1):
    print("INF" if dist[i] == INF else dist[i])