import sys

input = sys.stdin.readline
MAX = 9876543210

def solve():
    cnt = num = 0
    while True:
        if num > MAX:
            return -1

        flag = True
        str_num = str(num)

        for i in range(1, len(str_num)):
            if int(str_num[i - 1]) <= int(str_num[i]):
                left = str_num[:i - 1]
                mid = str(int(str_num[i - 1]) + 1)
                right = '0' + str_num[i + 1:]
                num = int(left + mid + right)
                flag = False
                break
        
        if flag:
            if cnt == n:
                return num
            cnt += 1
            num += 1

n = int(input())

print(solve())