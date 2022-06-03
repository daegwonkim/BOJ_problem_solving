import sys

input = sys.stdin.readline

def binary_search(left, right, target):
    while left <= right:
        pivot = (left + right) // 2
        if result[pivot] == target:
            return pivot
        elif result[pivot] < target:
            left = pivot + 1
        else:
            right = pivot - 1

    return left

n = int(input())
arr = list(map(int, input().split()))

result = [arr[0]]
for i in range(1, n):
    if result[-1] < arr[i]:
        result.append(arr[i])
    else:
        idx = binary_search(0, len(result), arr[i])
        result[idx] = arr[i]

print(len(result))