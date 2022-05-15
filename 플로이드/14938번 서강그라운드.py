import sys

input = sys.stdin.readline
INF = sys.maxsize

def floyd():
    for i in range(1, n + 1):
        graph[i][i] = 0

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

n, m, r = map(int, input().split())
items = list(map(int, input().split()))
graph = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a][b] = min(graph[a][b], l)
    graph[b][a] = min(graph[b][a], l)

floyd()

ans = 0
for i in range(1, n + 1):
    sum = 0
    for j in range(1, n + 1):
        if graph[i][j] <= m:
            sum += items[j - 1]
    ans = max(ans, sum)

print(ans)