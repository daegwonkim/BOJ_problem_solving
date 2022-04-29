import sys
import heapq

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def dijkstra(start):
    dist = [INF] * (n + 1)

    heap = [[0, start]]
    dist[start] = 0

    while heap:
        distance, node = heapq.heappop(heap)

        for n_dist, n_node in edges[node]:
            if dist[n_node] > distance + n_dist:
                dist[n_node] = distance + n_dist
                heapq.heappush(heap, [dist[n_node], n_node])

    return dist

# 변수 선언 및 초기화 부분
n, e = map(int, input().split())
edges = [[] for _ in range(n + 1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    edges[a].append([c, b])
    edges[b].append([c, a])
v1, v2 = map(int, input().split())

# 메인 코드 부분
rst_one = dijkstra(1)
rst_v1 = dijkstra(v1)
rst_v2 = dijkstra(v2)

ans = min((rst_one[v1] + rst_v1[v2] + rst_v2[n]), (rst_one[v2] + rst_v2[v1] + rst_v1[n]))
print(ans if ans < INF else -1)