import sys
from collections import deque

input = sys.stdin.readline

def check_left(idx, dir):   # 왼쪽 톱니바퀴 체크
    # 왼쪽에 더 이상 톱니바퀴가 없거나 서로 맞닿은 톱니의 극이 같을 때
    if idx < 0 or gear[idx][2] == gear[idx + 1][6]:
        return

    # 서로 맞닿은 톱니의 극이 다르다면 회전
    if gear[idx][2] != gear[idx + 1][6]:
        # 현재 톱니바퀴를 회전시키기 전에 왼쪽 톱니바퀴를 회전시킬 수 있는지 확인
        check_left(idx - 1, -dir)

        # 현재 톱니바퀴 회전
        gear[idx].rotate(dir)

def check_right(idx, dir):  # 오른쪽 톱니바퀴 체크

    # 오른쪽에 더 이상 톱니바퀴가 없거나 서로 맞닿은 톱니의 극이 같을 때
    if idx > 3 or gear[idx - 1][2] == gear[idx][6]:
        return

    # 서로 맞닿은 톱니의 극이 다르다면 회전
    if gear[idx - 1][2] != gear[idx][6]:
        # 현재 톱니바퀴를 회전시키기 전에 오른쪽 톱니바퀴를 회전시킬 수 있는지 확인
        check_right(idx + 1, -dir)

        # 현재 톱니바퀴 회전
        gear[idx].rotate(dir)

gear = [deque(map(int, input().rstrip())) for _ in range(4)]
k = int(input())
for _ in range(k):
    num, dir = map(int, input().split())

    # 톱니바퀴의 번호가 1 ~ 4 사이의 숫자로 입력되므로 배열의 인덱스 형식으로 사용하기 위함
    num -= 1
    
    # 톱니바퀴를 회전시키기 전 해당 톱니바퀴와 인접해 있는 톱니바퀴들이 회전할 수 있는지 검사
    # 이때 인접한 톱니바퀴와 인접한 톱니바퀴도 전부 검사해야 함
    check_left(num - 1, -dir)   # 인접한 톱니바퀴는 주어진 톱니바퀴와 반대 방향으로 회전함
    check_right(num + 1, -dir)

    # 인접한 톱니바퀴를 모두 검사한 후 현재 톱니바퀴 회전
    gear[num].rotate(dir)

ans = 0
for i in range(4):
    ans += (2 ** i) * gear[i][0]

print(ans)