x = int(input())

# line: X가 속하는 라인, end: X가 속하는 라인의 끝 값
line = end = 1
while x > end:
    line += 1
    end += line

# X가 속하는 라인에서 X의 위치 = 라인의 끝 값과 X 사이의 거리
diff = end - x

# 분자, 분모
top = bottom = 0

# 짝수번째 라인인 경우
if line % 2 == 0:
    top = line - diff
    bottom = diff + 1

# 홀수번째 라인인 경우
else:
    top = diff + 1
    bottom = line - diff

print(f'{top}/{bottom}')