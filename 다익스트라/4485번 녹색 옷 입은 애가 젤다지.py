import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def dijkstra():
    heap = []
    heapq.heappush(heap, [graph[0][0], 0, 0])
    dp[0][0] = 0

    while heap:
        rupee, y, x = heapq.heappop(heap)

        if y == n - 1 and x == n - 1:
            print(f'Problem {cnt}: {dp[y][x]}')
            break
            
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                n_rupee = rupee + graph[ny][nx]

                if n_rupee < dp[ny][nx]:
                    dp[ny][nx] = n_rupee
                    heapq.heappush(heap, [n_rupee, ny, nx])

cnt = 1
while True:
    n = int(input())

    if n == 0: break

    graph = [list(map(int, input().split())) for _ in range(n)]
    dp = [[INF] * n for _ in range(n)]

    dijkstra()
    cnt += 1