import sys
input = sys.stdin.readline

n = int(input())
score = [int(input()) for _ in range(n)]

ans = 0
for i in range(n - 1, 0, -1):
    if score[i] <= score[i - 1]:
        ans += score[i - 1] - score[i] + 1
        score[i - 1] -= score[i - 1] - score[i] + 1
print(ans)