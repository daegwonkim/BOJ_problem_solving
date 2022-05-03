import sys
import heapq
from collections import deque

# 전처리 부분
input = sys.stdin.readline
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 알고리즘 부분
def bfs():
    eat_fish = []   # 아기 상어가 먹을 수 있는 물고기를 거리 기준으로 저장할 힙
    cnt = [[0] * n for _ in range(n)]   # 아기 상어가 이동한 거리를 저장하기 위한 배열

    que = deque([])
    que.append([pos_y, pos_x])

    while que:
        y, x = que.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                if cnt[ny][nx] == 0 and size >= arr[ny][nx]:    # 이전에 지나간 칸이 아니며, 현재 사이즈가 해당 칸의 값보다 큰 경우
                    cnt[ny][nx] = cnt[y][x] + 1 # 이전 칸까지 이동한 거리 + 1

                    if arr[ny][nx] != 0 and size > arr[ny][nx]: # 해당 칸에 물고기가 존재하며 해당 물고기보다 아기 상어의 크기가 더 클 경우
                        heapq.heappush(eat_fish, [cnt[ny][nx], ny, nx]) # 문제에 제시된 조건에 따라 [거리, y축, x축] 순으로 힙에 저장

                    que.append([ny, nx])
    
    return eat_fish

# 메인 코드 부분
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
pos_y, pos_x = 0, 0
for i in range(n):
    for j in range(n):
        if arr[i][j] == 9:
            arr[i][j] = 0       # 0으로 초기화해주지 않으면 이후 bfs를 수행할 때 문제가됨
            pos_y, pos_x = i, j # 아기 상어의 초기 위치 저장

size = 2    # 아기 상어의 현재 사이즈
ans, eat_cnt = 0, 0
while True:
    eat_fish = bfs()    # 아기 상어가 잡아 먹을 수 있는 물고기 배열을 받아옴

    if not eat_fish: break  # 잡아 먹을 수 있는 물고기가 없는 경우

    cnt, pos_y, pos_x = eat_fish[0] # 힙에서 첫 번째 인덱스는 아기 상어가 먹을 수 있는 가장 가까운 물고기를 의미함
    ans += cnt      # 거리(시간) 더해주기
    eat_cnt += 1    # 물고기를 먹은 횟수 증가
    arr[pos_y][pos_x] = 0   # 물고기를 먹었으므로 해당 인덱스 0으로 초기화

    if size == eat_cnt: # 현재 아기 상어가 물고기를 먹은 횟수가 자신의 크기와 같은 경우
        size += 1       # 아기 상어 사이즈 증가
        eat_cnt = 0     # 횟수 초기화

print(ans)