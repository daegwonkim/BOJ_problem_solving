import sys

input = sys.stdin.readline

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return left

n, h = map(int, input().split())

up, down = [], []
for i in range(n):
    if i % 2 == 0:
        up.append(int(input()))
    else:
        down.append(int(input()))

up.sort()
down.sort()

obs_cnt, sec_cnt = n, 0
for i in range(1, h + 1):
    up_cnt = len(up) - binary_search(up, h - i + 0.5)
    down_cnt = len(down) - binary_search(down, i - 0.5)
    total_cnt = up_cnt + down_cnt

    if obs_cnt == total_cnt:
        sec_cnt += 1
    elif obs_cnt > total_cnt:
        obs_cnt = total_cnt
        sec_cnt = 1

print(obs_cnt, sec_cnt)