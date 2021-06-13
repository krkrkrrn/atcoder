MAX = 10**5
prime_nums = []
prime_bit = [False, False] + [True]*(MAX-1)
for i in range(2, int(10**2.5)+1):
    if prime_bit[i]:
        for j in range(i*2, len(prime_bit), i):
            prime_bit[j] = False
like_2017_bit = [False]*(MAX+1)
for i in range(3, len(prime_bit), 2):
    if prime_bit[i] and prime_bit[(i+1)//2]:
        like_2017_bit[i] = True
like_2017_cumulative_sum = [0]
for i in range(MAX):
    like_2017_cumulative_sum.append(like_2017_cumulative_sum[i]+like_2017_bit[i+1])
q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print(like_2017_cumulative_sum[r]-like_2017_cumulative_sum[l-1])