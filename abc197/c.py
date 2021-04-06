# 参考: https://atcoder.jp/contests/abc197/submissions/21294461
N = int(input())
A = list(map(int, input().split()))
ans = 1 << 30

def orxor(ored, xored, i):
    global ans
    if i == N:
        ans = min(ans, ored ^ xored)
    else:
        orxor(ored | A[i], xored, i+1)
        orxor(0, xored ^ (ored | A[i]), i+1)

orxor(0, 0, 0)
print(ans)