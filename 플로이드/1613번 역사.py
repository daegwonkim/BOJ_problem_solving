import sys

# 전처리 부분
input = sys.stdin.readline

# 알고리즘 부분
def floyd():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                if not arr[j][k] and arr[j][i] and arr[i][k]:
                    arr[j][k] = 1

# 메인 코드 부분
n, k = map(int, input().split())
arr = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(k):
    a, b = map(int, input().split())
    arr[a][b] = 1

floyd()

s = int(input())
temp = [list(map(int, input().split())) for _ in range(s)]

for a, b in temp:
    if arr[a][b] == 1:
        print(-1)
    elif arr[b][a] == 1:
        print(1)
    else:
        print(0)