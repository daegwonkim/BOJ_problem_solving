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
    
    for d, a, b in edges:
        if find_parent(a) != find_parent(b):
            union_parent(a, b)
            ans += d

    print(ans)

# 변수 선언 및 초기화 부분
n = int(input())
planet = []
for i in range(n):
    x, y, z = map(int, input().split())
    planet.append([x, y, z, i])
edges = []
for i in range(3):
    planet.sort(key = lambda x:x[i])
    for j in range(1, n):
        edges.append([abs(planet[j - 1][i] - planet[j][i]), planet[j - 1][3], planet[j][3]])
parent = [i for i in range(n)]

# 메인 코드 부분
edges.sort()
kruskal()