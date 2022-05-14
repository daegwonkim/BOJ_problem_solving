import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

def dijkstra():
    heap = []
    heapq.heappush(heap, [0, n])

    while heap:
        sec, x = heapq.heappop(heap)

        for nx in [x + 1, x - 1, x * 2]:
            if 0 <= nx <= 100000:
                if nx == x * 2 and dp[nx] == INF:
                    dp[nx] = sec
                    heapq.heappush(heap, [sec, nx])
                elif dp[nx] == INF:
                    dp[nx] = sec + 1
                    heapq.heappush(heap, [sec + 1, nx])

n, k = map(int, input().split())
dp = [INF] * 100001

if k <= n:
    print(n - k)
else:
    dijkstra()
    print(dp[k])