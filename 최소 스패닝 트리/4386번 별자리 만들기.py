from math import sqrt
import sys

# 전처리 부분
input = sys.stdin.readline

def get_distance(x, y, xx, yy):
    dx = pow((x - xx), 2)
    dy = pow((y - yy), 2)

    return sqrt(dx + dy)

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

    print(round(ans, 2))

# 변수 선언 및 초기화 부분
n = int(input())
points = []
for _ in range(n):
    x, y = map(float, input().split())
    points.append([x, y])
parent = [0] * n
for i in range(n):
    parent[i] = i
edges = []

# 메인 코드 부분
for i in range(n):
    x = points[i][0]
    y = points[i][1]

    for j in range(i + 1, n):
        xx = points[j][0]
        yy = points[j][1]

        dist = get_distance(x, y, xx, yy)
        edges.append([dist, i, j])

edges.sort()
kruskal()