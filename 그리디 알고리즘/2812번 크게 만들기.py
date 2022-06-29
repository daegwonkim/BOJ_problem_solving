import sys

input = sys.stdin.readline

n, k = map(int, input().split())
nums = list(map(int, input().strip()))

# 숫자 제거 횟수, 결과 리스트
del_cnt, stack = k, []

# n자리까지 반복
for i in range(n):
    while del_cnt > 0 and stack:
        # i번째 수보다 작은 리스트의 끝 수를 모두 제거
        if stack[len(stack) - 1] < nums[i]:
            stack.pop()
            del_cnt -= 1
        else:
            break
    stack.append(nums[i])

# 결과 리스트에 담겨있는 수를 전체 자릿수에서 제거할 횟수를 뺀 만큼 출력
for i in range(n - k):
    print(stack[i], end = '')