N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

a_max = max(A)
b_min = min(B)

ans = b_min - a_max + 1
if ans < 0:
    ans = 0

print(ans)