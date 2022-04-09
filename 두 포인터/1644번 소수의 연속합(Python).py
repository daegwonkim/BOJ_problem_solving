import sys
input = sys.stdin.readline

def find_prime():
    chk = [False, False] + [True] * (n - 1)

    for i in range(2, n + 1):
        if chk[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                chk[j] = False

def solve():
    cnt, sum, left, right = 0, 0, 0, 0

    while True:
        if sum > n:
            sum -= primes[left]
            left += 1
        else:
            if sum == n:
                cnt += 1
            if right >= len(primes):
                break
            sum += primes[right]
            right += 1

    return cnt

n = int(input())
primes = []

find_prime()
print(solve())