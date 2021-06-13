# https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516
n, k = map(int, input().split())
a = [int(input()) for _ in range(n)]
cumulative_sum = [0]
for i in range(n):
    cumulative_sum.append(cumulative_sum[i]+a[i])
# print(cumulative_sum)
ans = -10**4
for i in range(n-k+1):
    # print(cumulative_sum[k+i]-cumulative_sum[i])
    ans = max(ans, cumulative_sum[k+i]-cumulative_sum[i])
print(ans)
