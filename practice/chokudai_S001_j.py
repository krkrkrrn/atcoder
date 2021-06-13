# https://atcoder.jp/contests/chokudai_s001/tasks/chokudai_S001_j
# BIT
N = int(input())
sequence = list(map(int, input().split()))
bit = [0]*(N+1)
ans = 0

for i, n in enumerate(sequence):
    bit[n] += 1
    ans += i - sum(bit[:n])
print(ans)