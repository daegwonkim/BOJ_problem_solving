import sys
input = sys.stdin.readline

def bt(start, vowel, cons, cnt):
    if cnt == l:
        if vowel >= 1 and cons >= 2:
            print("".join(result))
        return

    for i in range(start, c):
        result[cnt] = alp[i]
        if alp[i] in 'aeiou':
            bt(i + 1, vowel + 1, cons, cnt + 1)
        else: bt(i + 1, vowel, cons + 1, cnt + 1)

l, c = map(int, input().split())
alp = list(map(str, input().split()))
result = [None] * l

alp.sort()
bt(0, 0, 0, 0)