import sys

input = sys.stdin.readline

def floyd():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j or i == k or j == k:
                    continue
                if time[i][j] == time[i][k] + time[k][j]:
                    road[i][j] = False
                elif time[i][j] > time[i][k] + time[k][j]:
                    print(-1)
                    exit(0)

n = int(input())
time = [list(map(int, input().split())) for _ in range(n)]  # 도로의 시간
road = [[True] * n for _ in range(n)]   # 도로 존재 여부

floyd()

ans = 0
for i in range(n):
    for j in range(i, n):
        if road[i][j]:  # 도로가 존재할 경우
            ans += time[i][j]
print(ans)