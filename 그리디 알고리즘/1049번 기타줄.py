import sys
input = sys.stdin.readline

n, m = map(int, input().split())
package, single = [], []
for _ in range(m):
    p, s = map(int, input().split())
    package.append(p)
    single.append(s)

package_min = min(package)
single_min = min(single)

if package_min > single_min * 6:
    print(single_min * n)
else:
    a = ((n // 6) * package_min) + ((n % 6 != 0) * package_min)
    b = ((n // 6) * package_min) + ((n % 6) * single_min)

    print(min(a, b))