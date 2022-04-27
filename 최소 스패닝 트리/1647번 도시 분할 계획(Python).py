import sys

# 전처리 부분
input = sys.stdin.readline

# 알고리즘 부분
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a != b:
        parent[a] = b

def kruskal():
    ans = 0

    for c, a, b in graph:
        if find_parent(a) != find_parent(b):
            union_parent(a, b)
            ans += c
            selected.append(c)

    ans -= selected.pop()
    print(ans)

# 변수 선언 및 초기화 부분
n, m = map(int, input().split())
graph = []
for _ in range(m):
    a, b, c = map(int, input().split())
    graph.append([c, a, b])
parent = [0] * (n + 1)
for i in range(1, n + 1):
    parent[i] = i
selected = []

# 메인 코드 부분
graph.sort()
kruskal()