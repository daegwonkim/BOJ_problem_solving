import sys

input = sys.stdin.readline
INF = sys.maxsize

def solve():
    left, right = 0, 1

    result = INF
    while left < n and right < n:
        tmp = arr[right] - arr[left]
        if tmp == m:
            print(tmp)
            exit(0)
        elif tmp > m:
            result = min(result, tmp)
            left += 1
        else:
            right += 1

    return result

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

arr.sort()
print(solve())