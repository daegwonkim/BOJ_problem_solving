import sys
import heapq

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def dijkstra(start):
    heap = [[0, start]]
    time[start] = 0

    while heap:
        cost, node = heapq.heappop(heap)

        for n_cost, n_node in edges[node]:
            if time[n_node] > cost + n_cost:
                time[n_node] = cost + n_cost
                heapq.heappush(heap, [time[n_node], n_node])

# 변수 선언 및 초기화 부분
n, m, x = map(int, input().split())
edges = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    edges[a].append([c, b])
result = [0] * (n + 1)
ans = 0

# 메인 코드 부분
for i in range(1, n + 1):
    time = [INF] * (n + 1)
    dijkstra(i)
    result[i] = time[x]

time = [INF] * (n + 1)
dijkstra(x)

for i in range(1, n + 1):
    result[i] += time[i]
    ans = max(ans, result[i])

print(ans)