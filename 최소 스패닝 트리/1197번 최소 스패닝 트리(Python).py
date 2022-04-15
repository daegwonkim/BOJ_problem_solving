import sys
import heapq

input = sys.stdin.readline

def solve():
    heap = [[0, 1]]

    while heap:
        global ans

        edge, node = heapq.heappop(heap)

        if visited[node] == False:
            visited[node] = True
            ans += edge

            for next_edge in edges[node]:
                if visited[next_edge[1]] == False:
                    heapq.heappush(heap, next_edge)

v, e = map(int, input().split())
edges = [[] for _ in range(v + 1)]
visited = [0] * (v + 1)
ans = 0

for i in range(e):
    a, b, c = map(int, input().split())
    edges[a].append([c, b])
    edges[b].append([c, a])

solve()
print(ans)