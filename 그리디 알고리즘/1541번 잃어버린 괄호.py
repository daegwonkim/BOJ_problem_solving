s = input().split('-')
nums = []

for i in s:
    sum = 0
    exp = i.split('+')

    for j in exp:
        sum +=int(j)
    nums.append(sum)

ans = nums[0]
for i in range(1, len(nums)):
    ans -= nums[i]
print(ans)