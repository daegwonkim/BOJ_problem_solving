import sys
input = sys.stdin.readline

n, m = map(int, input().split())
matrix_A = [list(map(int, list(input().rstrip()))) for _ in range(n)]
matrix_B = [list(map(int, list(input().rstrip()))) for _ in range(n)]

cnt = 0
for i in range(n - 2):
    for j in range(m - 2):
        if matrix_A[i][j] != matrix_B[i][j]:
            for k in range(i, i + 3):
                for l in range(j, j + 3):
                    matrix_A[k][l] = 1 - matrix_A[k][l]
            cnt += 1

for i in range(n):
    for j in range(m):
        if matrix_A[i][j] != matrix_B[i][j]:
            print(-1)
            exit(0)
print(cnt)