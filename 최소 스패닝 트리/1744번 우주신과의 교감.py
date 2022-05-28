import sys

input = sys.stdin.readline

# 크루스칼 알고리즘
def find(x):
    if parent[x] == x:
        return x

    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a, b = find(a), find(b)
    parent[max(a, b)] = min(a, b)

# 거리 계산을 위한 함수
def calc(a, b):
    # a^2 + b^2 = c^2
    return ((a[0] - b[0])**2 + (a[1] - b[1])**2)**(1/2)

n, m = map(int, input().split())
point = [list(map(int, input().split())) for _ in range(n)]
parent = [i for i in range(n)]

# 이미 연결되어 있는 통로 합치기
for _ in range(m):
    a, b = map(int, input().split())
    union(a - 1, b - 1)

# 거리 구하기
dist = []
for i in range(n - 1):
    for j in range(i + 1, n):
        dist.append((calc(point[i], point[j]), i, j))

# 거리를 기준으로 오름차순 정렬
dist.sort()

ans = 0
for d, a, b in dist:
    if find(a) != find(b):
        union(a, b)
        ans += d

print('%.2f' %(ans))