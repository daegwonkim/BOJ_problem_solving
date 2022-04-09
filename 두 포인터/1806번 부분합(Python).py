import sys
input = sys.stdin.readline

def solve():
    global ans
    sum, left, right = 0, 0, 0

    while left <= right:
        if sum >= s:
            ans = min(ans, right - left)
            sum -= arr[left]
            left += 1
        else:
            if right >= n:
                break
            sum += arr[right]
            right += 1

n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = 100000

solve()
if ans == 100000:
    print(0)
else: print(ans)