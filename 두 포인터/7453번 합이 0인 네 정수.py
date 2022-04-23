import sys

# 전처리 부분
input = sys.stdin.readline

# 알고리즘 부분
def solve():
    # 투 포인터 알고리즘을 사용하기 위한 인덱스 설정
    # start 변수는 ab 리스트의 첫 번째 인덱스, end 변수는 cd 리스트의 마지막 인덱스를 가리킴
    start, end = 0, len(cd) - 1
    result = 0

    while start < len(ab) and end >= 0:
        if ab[start] + cd[end] == 0:    # 두 포인터가 가리키는 요소의 합이 0이 될 경우
            n_start, n_end = start + 1, end - 1 # 다음 포인터 인덱스 설정
            
            # ab 또는 cd 배열에 중복되는 값이 있을 경우
            while n_start < len(ab) and ab[n_start] == ab[start]:
                n_start += 1
            while n_end >= 0 and cd[n_end] == cd[end]:
                n_end -= 1

            # 전체 쌍의 수를 구하기 위한 연산
            result += (n_start - start) * (end - n_end)

            # 포인터 인덱스 갱신
            start, end = n_start, n_end
        
        # 두 포인터가 가리키는 요소의 합이 0보다 클 경우 or 작을 경우
        elif ab[start] + cd[end] > 0:
            end -= 1    # 합이 0이 되는 요소를 찾기 위해 end 인덱스를 감소시킴
        else: start += 1    # 합이 0이 되는 요소를 찾기 위해 start 인덱스를 증가시킴
    
    print(result)

# 변수 선언 및 초기화 부분
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
ab, cd = [], []

# a와 b, c와 d에 대한 계산 결과를 따로 저장
for i in range(n):
    for j in range(n):
        ab.append(arr[i][0] + arr[j][1])
        cd.append(arr[i][2] + arr[j][3])

# 메인 코드 부분
# 두 리스트 모두 오름차순 정렬
ab.sort()
cd.sort()

solve()