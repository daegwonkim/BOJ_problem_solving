import sys
from collections import deque

input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def _numbering(i, j, num, visited):
    que = deque()
    que.append([i, j])

    while que:
        y, x = que.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if not 0 <= ny < n or not 0 <= nx < m: continue

            if country[ny][nx] and not visited[ny][nx]:
                country[ny][nx] = num
                visited[ny][nx] = True
                island_spot.append([ny, nx, num])
                que.append([ny, nx])

# 각 섬마다 서로 다른 번호를 부여하기 위함
def numbering():
    visited = [[0] * m for _ in range(n)]

    num = 1
    for i in range(n):
        for j in range(m):
            if country[i][j] and not visited[i][j]:
                visited[i][j] = True
                country[i][j] = num

                # 섬이 있는 위치와 번호 저장(이후 다리를 만들어 섬을 연결할 때 다리의 시작점이 됨)
                island_spot.append([i, j, num])

                _numbering(i, j, num, visited)
                num += 1
    
    return num - 1

# 섬을 연결하는 다리 만들기
def make_bridge(y, x, c):
    que = deque()

    # 한쪽 방향으로만 이동하는 BFS
    for i in range(4):
        que.append([y, x])
        visited = [[0] * m for _ in range(n)]
        temp = [[0] * m for _ in range(n)]  # 다리의 길이를 저장하기 위함
        visited[y][x] = True

        while que:
            yy, xx = que.popleft()
            ny = yy + dy[i]
            nx = xx + dx[i]

            if not 0 <= ny < n or not 0 <= nx < m: continue

            if not visited[ny][nx]:
                if country[ny][nx] == 0:    # 다음 위치가 바다인 경우 다리 생성
                    temp[ny][nx] = temp[yy][xx] + 1
                    que.append([ny, nx])

                # 다음 위치가 바다가 아니며(위 조건에 의해 걸러짐) 다리의 시작점 섬이 아니고, 다리의 길이가 2이상인 경우
                elif country[ny][nx] != c and temp[yy][xx] >= 2:
                    # 문제에 제시된 다리 연결 조건을 만족하므로 이후 크루스칼 알고리즘을 위해 사용할 bridges 배열에 추가
                    # [다리의 길이, 시작섬, 도착섬]
                    bridges.append([temp[yy][xx], c, country[ny][nx]])

# 크루스칼 알고리즘
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
    ans, cnt = 0, 0

    for dist, a, b in bridges:
        if find_parent(a) != find_parent(b):
            union_parent(a, b)
            ans += dist
            cnt += 1
            if cnt == num - 1: break

    return ans, cnt

n, m = map(int, input().split())
country = [list(map(int, input().split())) for _ in range(n)]
island_spot = []
bridges = []

num = numbering()

for y, x, c in island_spot: # 섬의 위치를 기준으로 다리 생성
    make_bridge(y, x, c)

parent = [i for i in range(num + 1)]
bridges.sort()  # 다리의 길이를 기준으로 오름차순 정렬

ans, cnt = kruskal()

if cnt == num - 1:  # 모든 섬을 연결했을 경우 즉, 다리 연결 횟수 = 섬의 개수 - 1
    print(ans)
else: print(-1)