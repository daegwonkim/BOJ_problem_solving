import sys

input = sys.stdin.readline

def calc(lst):
    global ans

    if len(lst) % 2 == 0:
        for i in range(0, len(lst), 2):
            ans += lst[i] * lst[i + 1]
    else:
        for i in range(0, len(lst) - 1, 2):
            ans += lst[i] * lst[i + 1]
        ans += lst[len(lst) - 1]

n = int(input())
positive_list = []
negative_list = []

ans = 0
for _ in range(n):
    num = int(input())
    if num > 1:
        positive_list.append(num)
    elif num <= 0:
        negative_list.append(num)
    else:
        ans += 1

positive_list.sort(reverse = True)
negative_list.sort()

calc(positive_list)
calc(negative_list)

print(ans)