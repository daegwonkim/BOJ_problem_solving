import sys
import heapq

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def dijkstra():
    while heap:
        distance, start, end = heapq.heappop(heap)

        # 출발점과 도착점이 같다면 사이클이며, 힙에서 뽑은 경로이기 때문에 해당 값이 최소 경로가 됨
        if start == end:
            print(distance)
            break

        if dist[start][end] < distance: continue

        for n_dist, n_node in graph[end]:
            if dist[start][n_node] > distance + n_dist:
                dist[start][n_node] = distance + n_dist
                heapq.heappush(heap, [dist[start][n_node], start, n_node])

# 변수 선언 및 초기화 부분
v, e = map(int, input().split())
graph = [[] for _ in range(v + 1)]
dist = [[INF] * (v + 1) for _ in range(v + 1)]
heap = []

# 메인 코드 부분
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append([c, b])
    heapq.heappush(heap, [c, a, b]) # 유효한 경로를 미리 힙에 저장

dijkstra()