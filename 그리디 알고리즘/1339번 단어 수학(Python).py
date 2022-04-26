import sys

#전처리 부분
input = sys.stdin.readline

# 변수 선언 및 초기화 부분
n = int(input())
alp = [0] * 26

# 메인 코드 부분
for i in range(n):
    word = list(input().rstrip())
    for j in range(len(word)):
        alp[ord(word[j]) - ord('A')] += pow(10, len(word) - j - 1)

alp.sort()
alp.reverse()

num = 9
ans = 0
for i in range(26):
    if alp[i] != 0:
        ans += alp[i] * num
        num -= 1

print(ans)