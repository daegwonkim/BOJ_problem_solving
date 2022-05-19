import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def dfs(node, weight):
    for w, n in tree[node]:
        if dist[n] == -1:
            dist[n] = weight + w
            dfs(n, weight + w)

n = int(input())
tree = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    tree[a].append([c, b])
    tree[b].append([c, a])

dist = [-1] * (n + 1)   # 간선의 합을 저장하기 위한 배열
dist[1] = 0
dfs(1, 0)   # 루트 노드부터 시작해서 간선의 합이 최대 길이가 되는 리프 노드를 찾음

start = dist.index(max(dist))   # 간선의 합이 최대 길이가 되는 리프 노드
dist = [-1] * (n + 1)
dist[start] = 0 # 위에서 구한 리프 노드를 기준으로 dfs를 한 번 더 수행
dfs(start, 0)

print(max(dist))