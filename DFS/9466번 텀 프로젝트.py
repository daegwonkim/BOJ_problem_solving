import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def dfs(x):
    global result

    visited[x] = True
    cycle.append(x) #현재까지의 사이클에 포함되는 학생 저장

    if visited[arr[x]]: #방문할 수 있는 곳을 모두 방문한 경우
        if arr[x] in cycle: #사이클이 가능한지 확인
            result += cycle[cycle.index(arr[x]):]   # 사이클이 형성되는 구간부터만 팀으로 구성
    else: dfs(arr[x])

for _ in range(int(input())):
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    visited = [False] * (n + 1)
    result = []

    for i in range(1, n + 1):
        if not visited[i]:
            cycle = []
            dfs(i)

    print(n - len(result))