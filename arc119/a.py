N = int(input())

ans = 10**18
for b in range(65):
    a = N//(2**b)
    c = N - (2**b)*a
    if ans > a+b+c:
        ans = a+b+c

print(ans)