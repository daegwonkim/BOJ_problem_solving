import sys

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def solve():
    start, end = 0, n - 1

    ans = []
    crt_diff = INF

    while start != end:
        sum = arr[start] + arr[end]
        if abs(sum) < crt_diff:
            crt_diff = abs(sum)
            ans = [arr[start], arr[end]]
        
        if sum >= 0: end -= 1
        else: start += 1

    print(ans[0], ans[1])

# 변수 선언 및 초기화 부분
n = int(input())
arr = list(map(int, input().split()))

# 메인 코드 부분
arr.sort()
solve()