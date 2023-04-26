import sys
import heapq
input = sys.stdin.readline

n, k = map(int, input().split())
jewels = [list(map(int, input().split())) for _ in range(n)]
bags = [int(input()) for _ in range(k)]

# 무게 순으로 정렬
jewels.sort()
bags.sort()

ans = 0
max_heap = []

# 모든 가방에 대해서 반복
for weight in bags:
    # 현재 가방에 들어갈 수 있는 보석을 모두 최대힙에 저장
    while jewels and jewels[0][0] <= weight:
        heapq.heappush(max_heap, -jewels[0][1])
        heapq.heappop(jewels)   # 최대힙에 저장된 보석은 배열에서 제거
    if max_heap:    # 이전 가방에 들어갈 수 있는 보석은 현재 가방에도 들어갈 수 있음
        # 현재 가방에 들어갈 수 있는 보석들 중 가치가 최대인 보석을 넣음
        ans += heapq.heappop(max_heap)

print(-ans)