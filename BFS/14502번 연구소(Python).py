import sys
import copy
from itertools import combinations
input = sys.stdin.readline

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def solve():
    ans = 0

    # 벽을 세울 수 있는 모든 위치를 저장
    enable = [(i, j) for i in range(n) for j in range(m) if graph[i][j] == 0]

    for walls in combinations(enable, 3):   # 위 리스트에 저장되어 있는 위치 중 3가지씩 골라 조합
        c_graph = copy.deepcopy(graph)

        # 조합에 속한 위치에 벽을 만듦
        for y, x in walls:
            c_graph[y][x] = 1
        
        virus = [(i, j) for i in range(n) for j in range(m) if c_graph[i][j] == 2]
        while virus:
            y, x = virus.pop()

            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]

                if 0 <= ny < n and 0 <= nx < m:
                    if c_graph[ny][nx] == 0:
                        c_graph[ny][nx] = 2
                        virus.append((ny, nx))
        
        cnt = 0
        for i in range(n):
            cnt += c_graph[i].count(0)
        ans = max(ans, cnt)

    return ans

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

print(solve())