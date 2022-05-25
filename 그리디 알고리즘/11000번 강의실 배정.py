import sys
import heapq

input = sys.stdin.readline

n = int(input())
time = [list(map(int, input().split())) for _ in range(n)]

time.sort() # 시작 시간 순으로 정렬

# 큐 내부적으로도 시작 시간 순서대로 정렬되도록 우선순위 큐 사용
heap = []
heapq.heappush(heap, time[0][1])

for i in range(1, n):
    # 현재 수업의 종료 시간보다 다음 수업의 시작 시간이 더 빠른 경우
    if time[i][0] < heap[0]:
        heapq.heappush(heap, time[i][1])    # 새 강의실 추가
    # 위 경우가 아닌 경우 즉, 기존 강의실을 그대로 사용할 수 있는 경우
    else:
        # 현재 수업의 종료 시간을 다음 수업의 종료 시간으로 교체
        heapq.heappop(heap)
        heapq.heappush(heap, time[i][1])    

# 필요한 강의실의 개수 = 큐에 들어가 있는 수업 종료 시간의 개수
print(len(heap))