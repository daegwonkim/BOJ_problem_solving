import sys

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def binary_search():
    tmp = INF
    left, right = 0, n - 1

    while left < right:
        sum = arr[left] + arr[right]

        if sum == 0:
            return arr[left], arr[right]

        if tmp > abs(sum):
            tmp = abs(sum)
            result = [arr[left], arr[right]]
        
        if sum < 0:
            left += 1
        else:
            right -= 1

    return result

# 메인 코드 부분
n = int(input())
arr = sorted(list(map(int, input().split())))

ans = binary_search()
print(ans[0], ans[1])