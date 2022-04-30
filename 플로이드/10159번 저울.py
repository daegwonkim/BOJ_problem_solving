import sys

# 전처리 부분
input = sys.stdin.readline

# 알고리즘 부분
def floyd():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                if not comp[j][k] and comp[j][i] and comp[i][k]:
                    comp[j][k] = 1

# 변수 선언 및 초기화 부분
n, m = int(input()), int(input())
comp = [[0] * (n + 1) for _ in range(n + 1)]

# 메인 코드 부분
for _ in range(m):
    a, b = map(int, input().split())
    comp[a][b] = 1

floyd()

for i in range(1, n + 1):
    cnt = 0
    for j in range(1, n + 1):
        if not comp[i][j] and not comp[j][i]:
            cnt += 1
    print(cnt - 1)