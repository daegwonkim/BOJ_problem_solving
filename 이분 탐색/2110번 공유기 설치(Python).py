import sys
input = sys.stdin.readline

def solve():
    ans = 0
    min_dist, max_dist = 1, x[-1] - x[0]

    while min_dist <= max_dist:
        dist = (min_dist + max_dist) // 2
        prev = x[0]
        cnt = 1

        for i in range(1, n):
            if x[i] - prev >= dist:
                cnt += 1
                prev = x[i]

        if cnt >= c:
            min_dist = dist + 1
            ans = dist
        else:
            max_dist = dist - 1

    return ans

n, c = map(int, input().split())
x = []
for _ in range(n):
    x.append(int(input()))

x.sort()
print(solve())