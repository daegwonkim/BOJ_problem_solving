from collections import Counter
import sys
input = sys.stdin.readline

def get_mode():
    counter = Counter(nums)
    elements = counter.most_common()

    modes = []
    for num, cnt in elements:
        if cnt == elements[0][1]:
            modes.append(num)
    
    return modes[0] if len(modes) == 1 else modes[1]

n = int(input())
nums = [int(input()) for _ in range(n)]

# 산술평균
print(round(sum(nums) / n))

# 중앙값
nums.sort()
print(nums[n // 2])

# 최빈값
print(get_mode())

# 범위
print(nums[-1] - nums[0])