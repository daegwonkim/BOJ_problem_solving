import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

def dijkstra():
    # 방문 경로 체크를 위해 배열 추가
    que = [(0, start, [start])]
    dist[start] = 0

    while que:
        cost, node, path = heapq.heappop(que)

        if dist[node] < cost: continue

        for n_cost, n_node in graph[node]:
            if dist[n_node] > cost + n_cost:
                dist[n_node] = cost + n_cost
                visited[n_node] = path + [n_node]   # 경로 갱신
                heapq.heappush(que, (cost + n_cost, n_node, path + [n_node]))

n, m = int(input()), int(input())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
start, end = map(int, input().split())

dist = [INF] * (n + 1)  # 최소 비용 저장
visited = [[] for _ in range(n + 1)]    # 각 노드 별로 경로 저장

dijkstra()

print(dist[end])    # 도착 도시까지 가는데 드는 최소 비용
print(len(visited[end]))    # 도착 도시까지 가는 경로에 포함되어 있는 도시의 개수
for city in visited[end]:   # 도착 도시까지 가는 경로에 포함되어 있는 도시
    print(city, end = " ")