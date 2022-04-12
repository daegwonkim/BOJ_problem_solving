import sys
import heapq
input = sys.stdin.readline

def solve():
    ans = 0 # 출력할 값

    while len(heap) > 1:    # 원소의 개수가 2개 이상인 경우 동작
        a = heapq.heappop(heap)
        b = heapq.heappop(heap)

        ans += a + b    # 출력 값 갱신
        heapq.heappush(heap, a + b) # 앞의 두 수의 합을 힙에 추가

    return ans

n = int(input())
heap = []   # 힙 자료구조

if n == 1:  # 카드 묶음이 1개인 경우 비교 X
    print(0)
    exit()

for _ in range(n):
    heapq.heappush(heap, int(input()))

print(solve())