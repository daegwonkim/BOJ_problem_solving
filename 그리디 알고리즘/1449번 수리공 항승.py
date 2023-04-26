import sys
input = sys.stdin.readline

N, L = map(int, input().split())
pos = list(map(int, input().split()))

pos.sort()  # 위치 정렬

start = 0   # 테이프 시작위치
cnt = 1     # 필요한 테이프의 최소 갯수
for i in range(1, N):
    if pos[i] - pos[start] < L: # 두 위치 사이의 거리가 테이프의 길이보다 짧을 경우
        continue    # 기존의 테이프를 이용

    # 테이프의 길이가 모자랄 경우
    cnt += 1    # 필요한 테이프 갯수 추가
    start = i   # 새로운 테이프의 시작위치
print(cnt)