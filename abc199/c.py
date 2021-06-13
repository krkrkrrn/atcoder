N = int(input())
S = list(str(input()))
Q = int(input())
flipped = False

for _ in range(Q):
    T, A, B = map(int, input().split())
    if T == 1:
        A -= 1
        B -= 1
        if flipped:
            A = (A+N)%(2*N)
            B = (B+N)%(2*N)
        S[A], S[B] = S[B], S[A]
    else:
        flipped = not flipped

if flipped:
    S = S[N:] + S[:N]

print("".join(S))

