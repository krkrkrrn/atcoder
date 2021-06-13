N = int(input())
A = list(map(lambda n: int(n)%200, input().split()))
ans = 0
for i in range(200):
    c = A.count(i)
    ans += c*(c-1)//2
print(ans)