import sys

# 전처리 부분
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# 알고리즘 부분
def dfs(node, color):
    check[node] = color

    for n_node in edges[node]:
        if not check[n_node]:
            rtn = dfs(n_node, -color)
            if not rtn:
                return False
        elif check[node] == check[n_node]:
            return False
    return True

# 메인 코드 부분
k = int(input())

for _ in range(k):
    v, e = map(int, input().split())
    edges = [[] for _ in range(v + 1)]
    check = [0] * (v + 1)
    for _ in range(e):
        a, b = map(int, input().split())
        edges[a].append(b)
        edges[b].append(a)

    for i in range(1, v + 1):
        if not check[i]:
            result = dfs(i, 1)
            if not result:
                break

    print("YES" if result else "NO")