import sys

input = sys.stdin.readline

n, k = map(int, input().split())
use = list(map(int, input().split()))

ans = idx = 0
multitap = [0] * n  # 사용중인 전자 용품 현황
for prod in use:
    swap_prod = max_idx = 0

    if prod in multitap:    # 용품이 현재 멀티탭을 사용하고 있는 경우
        pass
    elif 0 in multitap:     # 멀티탭에 빈 공간이 있는 경우
        multitap[multitap.index(0)] = prod
    else:   # 멀티탭에 빈 공간이 없는 경우
        for used_prod in multitap:  # 현재 멀티탭을 사용중인 용품에 대해
            if used_prod not in use[idx:]:  # 해당 용품이 이후에 사용되지 않는 경우
                swap_prod = used_prod
                break
            # 해당 용품이 이후에 사용되는데 순서가 가장 나중인 경우
            elif use[idx:].index(used_prod) > max_idx:
                max_idx = use[idx:].index(used_prod)
                swap_prod = used_prod
        multitap[multitap.index(swap_prod)] = prod  # 용품 교체
        ans += 1    # 플러그 빼는 횟수 증가
    idx += 1    # 조사 범위 축소

print(ans)