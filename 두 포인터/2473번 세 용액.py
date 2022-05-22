import sys

input = sys.stdin.readline
INF = sys.maxsize

def solve():
    tmp = INF

    for i in range(n - 2):
        left, right = i + 1, n - 1

        while left < right:
            sum = arr[i] + arr[left] + arr[right]

            if sum == 0:
                return arr[i], arr[left], arr[right]

            if tmp > abs(sum):
                result = [arr[i], arr[left], arr[right]]
                tmp = abs(sum)

            if sum < 0:
                left += 1
            else:
                right -= 1

    return result

n = int(input())
arr = sorted(list(map(int, input().split())))

ans = solve()
print(ans[0], ans[1], ans[2])