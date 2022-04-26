import sys
import heapq

# 전처리 부분
input = sys.stdin.readline

# 변수 선언 및 초기화 부분
n, k = map(int, input().split())
jewel = [list(map(int, input().split())) for _ in range(n)]
bag = [int(input()) for _ in range(k)]

# 메인 코드 부분
jewel.sort()
bag.sort()

heap = []
ans = 0
for weight in bag:
    while jewel and jewel[0][0] <= weight:
        heapq.heappush(heap, -jewel[0][1])  # Max heap
        heapq.heappop(jewel)
    
    if heap:
        ans += heapq.heappop(heap)

print(-ans)