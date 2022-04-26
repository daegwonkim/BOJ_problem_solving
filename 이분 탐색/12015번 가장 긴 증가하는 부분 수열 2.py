import sys

input = sys.stdin.readline

def binary_search(num):
    left, right = 0, len(result) - 1

    while(left <= right):
        mid = (left + right) // 2
        if result[mid] >= num:
            right = mid - 1            
        else: left = mid + 1
    
    return right + 1

n = int(input())
arr = list(map(int, input().split()))
result = [0]

for num in arr:
    if result[-1] < num:
        result.append(num)
    else: result[binary_search(num)] = num

print(len(result) - 1)