# https://atcoder.jp/contests/abc202/submissions/22796339
from collections import defaultdict
import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
cnt = defaultdict(lambda : 0)
for i in a:
    cnt[i] += 1
ans = 0
for i in c:
    ans += cnt[b[i - 1]]
print(ans)