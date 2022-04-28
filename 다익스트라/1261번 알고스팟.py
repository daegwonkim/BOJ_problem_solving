import sys
import heapq

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def dijkstra():
    dist[0][0] = 0
    heap = [[0, 0]]

    while heap:
        y, x = heapq.heappop(heap)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m:
                if maze[ny][nx] == 1:
                    if dist[ny][nx] > dist[y][x] + 1:
                        dist[ny][nx] = dist[y][x] + 1
                        heapq.heappush(heap, [ny, nx])
                else:
                    if dist[ny][nx] > dist[y][x]:
                        dist[ny][nx] = dist[y][x]
                        heapq.heappush(heap, [ny, nx])

# 변수 선언 및 초기화 부분
m, n = map(int, input().split())
maze = [list(map(int, input().rstrip())) for _ in range(n)]
dist = [[INF] * m for _ in range(n)]

# 메인 코드 부분
dijkstra()
print(dist[n - 1][m - 1])