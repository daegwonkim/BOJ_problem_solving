import sys
import copy
from collections import deque
input = sys.stdin.readline

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

n, m = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(n)]
virus = list(())
ans = 0

def bfs():
    global ans

    queue = deque(())
    copy_map = copy.deepcopy(map)

    for point in virus:
        queue.append(point)

    while queue:
        y, x = queue.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m and copy_map[ny][nx] == 0:
                copy_map[ny][nx] = 2
                queue.append((ny, nx))

    cnt = 0

    for i in range(n):
        for j in range(m):
            if copy_map[i][j] == 0:
                cnt += 1

    ans = max(ans, cnt)

def make_wall(cnt):
    if cnt == 3:
        bfs()
        return

    for i in range(n):
        for j in range(m):
            if map[i][j] == 0:
                map[i][j] = 1
                make_wall(cnt + 1)
                map[i][j] = 0

for i in range(n):
    for j in range(m):
        if map[i][j] == 2:
            virus.append((i, j))

make_wall(0)
print(ans)