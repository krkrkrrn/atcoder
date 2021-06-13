N, M = map(int, input().split())
variance = [3] * N
for _ in range(M):
    A, B = map(int, input().split())
    if A == N or B == N:
        variance[min(A, B)] -= 1
    else:
        if variance[A] > variance[B]:
            variance[A] -= 1
        else:
            variance[B] -= 1

ans = 1
for i in variance:
    ans *= i
if ans < 0:
    ans = 0
print(ans)
