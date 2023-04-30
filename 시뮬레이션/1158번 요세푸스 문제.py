from collections import deque

n, k = map(int, input().split())
que = deque()

for i in range(1, n + 1):
    que.append(i)

result = []
while que:
    for _ in range(k - 1):
        n = que.popleft()
        que.append(n)
    
    result.append(str(que.popleft()))

print('<', ', '.join(result), '>', sep='')