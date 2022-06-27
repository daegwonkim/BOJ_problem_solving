import sys

input = sys.stdin.readline

def is_palindrome():
    left, right = 0, len(word) - 1

    while left < right:
        # 대치되는 두 문자가 동일한 경우
        if word[left] == word[right]:
            left += 1
            right -= 1
        else:
            if left + 1 < right:    # 왼쪽 문자 제거 후 회문 확인
                tmp = word[:left] + word[left + 1:]
                if tmp[:] == tmp[::-1]:
                    return 1
            if left < right - 1:    # 오른쪽 문자 제거 후 회문 확인
                tmp = word[:right] + word[right + 1:]
                if tmp[:] == tmp[::-1]:
                    return 1

            # 대치되는 두 문자가 동일하지 않으며, 문자 제거 후에도 회문이 되지 않는 경우
            return 2
    
    # 문자열 그대로 회문일 경우
    return 0

for _ in range(int(input())):
    word = list(input().rstrip())
    print(is_palindrome())