# https://atcoder.jp/contests/abc026/tasks/abc026_b
import math
N = int(input())
r = []
for _ in range(N):
    r.append(int(input()))
r = sorted(r, reverse=True)
ans = 0
for i, j in enumerate(r):
    if i%2 == 0:
        ans += j**2
    else:
        ans -= j**2
print(ans*math.pi)