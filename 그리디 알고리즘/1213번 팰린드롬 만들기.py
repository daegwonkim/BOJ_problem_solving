from collections import Counter

name = list(input().rstrip())

name.sort() # 사전순 출력을 위한 오름차순 정렬
counter = Counter(name) # 각 단어의 빈도수 체크

cnt = 0
mid = ''  # 팰린드롬의 중앙에 위치할 문자
for i in counter:
    if counter[i] % 2 != 0: # 빈도수가 홀수인 경우
        cnt += 1
        mid = i
        name.remove(i)  # 해당 문자를 문자열에서 제거
    
    # 빈도수가 홀수인 문자가 여러개일 경우 팰린드롬을 만드는게 불가능함
    if cnt > 1:
        print("I'm Sorry Hansoo")
        exit(0)

result = ''
for i in range(0, len(name), 2):
    result += name[i]
print(result + mid + result[::-1])