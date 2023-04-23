import sys
input = sys.stdin.readline

n = int(input())
meetings = [list(map(int, input().split())) for _ in range(n)]

meetings.sort(key=lambda x: (x[1], x[0]))

cnt = 1
end = meetings[0][1]
for i in range(1, n):
    start = meetings[i][0]

    if end <= start:
        cnt += 1
        end = meetings[i][1]

print(cnt)