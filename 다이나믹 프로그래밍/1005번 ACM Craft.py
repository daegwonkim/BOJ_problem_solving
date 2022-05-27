import sys
from collections import deque

input = sys.stdin.readline

# 위상 정렬
def topology_sort():
    que = deque()
    for i in range(1, n + 1):
        # 진입차수가 0인 노드 큐에 삽입
        if in_degree[i] == 0:
            que.append(i)
            dp[i] = delay[i]    # 시작 노드 dp배열 초기화
    
    # 큐가 빌 때까지 수행
    while que:
        b = que.popleft()
        for i in seq[b]:
            in_degree[i] -= 1   # 진입차수 줄이기
            dp[i] = max(dp[i], dp[b] + delay[i])    # 건설 시간 갱신
            if in_degree[i] == 0:
                que.append(i)

def init():
    # 건물 건설 순서 및 진입차수 초기화
    for _ in range(k):
        x, y = map(int, input().split())
        seq[x].append(y)    # x를 지어야 y를 건설할 수 있음
        in_degree[y] += 1

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    delay = [0] + list(map(int, input().split()))   # 각 건물 건설에 걸리는 시간
    seq = [[] for _ in range(n + 1)]    # 건설 순서/규칙
    in_degree = [0] * (n + 1)   # 진입차수
    dp = [0] * (n + 1)  # 해당 건물까지 건설에 걸리는 시간

    init()
    topology_sort()

    w = int(input())
    print(dp[w])