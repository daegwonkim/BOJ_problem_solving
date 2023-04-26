s = input()

prev = ''
cnt = 0

for i in s:
    if i != prev:
        cnt += 1
        prev = i
print(cnt // 2)