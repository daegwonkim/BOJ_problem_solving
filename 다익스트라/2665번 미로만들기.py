import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize
dy = (1, -1, 0, 0)
dx = (0, 0, 1, -1)

def dijkstra():
    heap = []
    heapq.heappush(heap, (0, 0, 0))
    visited[0][0] = True

    while heap:
        cnt, y, x = heapq.heappop(heap)

        if y == n - 1 and x == n - 1:
            return cnt
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if not 0 <= ny < n or not 0 <= nx < n or visited[ny][nx]:
                continue

            visited[ny][nx] = True
            if room[ny][nx] == 1:
                heapq.heappush(heap, (cnt, ny, nx))
            else:
                heapq.heappush(heap, (cnt + 1, ny, nx))

n = int(input())
room = [list(map(int, input().strip())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]

print(dijkstra())