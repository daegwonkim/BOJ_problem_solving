import sys
from collections import deque

input = sys.stdin.readline

# 해당 중량일 때 두 섬 사이로 물품을 옮길 수 있는지 확인
def bfs(mid):
    visited[start] = True   # 시작 섬
    que = deque()
    que.append(start)

    while que:
        now = que.popleft()

        if now == end:  # 도착 섬에 도달했다면
            return True # 해당 중량일 때 물품 이동이 가능하다는 것

        for nc, ni in bridge[now]:
            # 섬을 방문한 적이 없으며 다음 다리의 중량이 현재 물품의 중량보다 크거나 같을 때
            if not visited[ni] and mid <= nc:
                visited[ni] = True
                que.append(ni)
    
    return False    # 도착 섬에 도달하지 못한 경우

n, m = map(int, input().split())
bridge = [[] for _ in range(n + 1)]

# 다리 정보를 연결 리스트로 저장
for _ in range(m):
    a, b, c = map(int, input().split())
    bridge[a].append([c, b])
    bridge[b].append([c, a])

start, end = map(int, input().split())

# 중량 제한에 따라 내림차순 정렬
for i in range(1, n + 1):
    bridge[i].sort(reverse=True)

# 최소 중량과 최대 중량 초기화
left, right = 1, 1000000000

# 이분 탐색으로 최대 중량 찾기
while left <= right:
    visited = [False] * (n + 1)
    mid = (left + right) // 2

    if bfs(mid):    # 옮길 수 있는 중량인 경우
        left = mid + 1  # 중량을 더 올려봄
    else:           # 옮길 수 없는 중량인 경우
        right = mid - 1 # 중량을 더 내려봄

print(right)