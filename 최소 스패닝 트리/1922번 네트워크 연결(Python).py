import sys
import heapq
input = sys.stdin.readline

def solve():
    ans = 0
    heap = [[0, 1]]

    while heap:
        edge, node = heapq.heappop(heap)

        if visited[node] == False:
            visited[node] = True
            ans += edge

            for next_edge in edges[node]:
                if visited[next_edge[1]] == False:
                    heapq.heappush(heap, next_edge)
    
    print(ans)

n = int(input())
m = int(input())
edges = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)

for i in range(m):
    a, b, c = map(int, input().split())
    edges[a].append([c, b])
    edges[b].append([c, a])

solve()