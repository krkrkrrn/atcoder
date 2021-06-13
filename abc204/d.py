# https://atcoder.jp/contests/abc204/submissions/23225426
N = int(input())
cooktimes = list(map(int, input().split()))
sum_cooktime = sum(cooktimes)
dp = {0}
for t in cooktimes:
    dp_n = set()
    for all_t in dp:
        dp_n.add(t+all_t)
    dp |= dp_n
ans = float("inf")
for all_t in dp:
    ans = min(ans, max(sum_cooktime-all_t, all_t))
print(ans)
