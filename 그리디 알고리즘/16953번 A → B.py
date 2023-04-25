a, b = map(int, input().split())

cnt = 0
while b > a:
    if b % 10 == 1:
        b //= 10
    elif b % 2 == 0:
        b //= 2
    else: break
    
    cnt += 1

print(cnt + 1 if a == b else -1)