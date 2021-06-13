N = int(input())
A, B, C = {}, {}, {}
for i in map(int, input().split()):
    if i not in A:
        A[i] = 0
    A[i] += 1
for i, j in enumerate(map(int, input().split())):
    if j not in B:
        B[j] = []
    B[j].append(i+1)
for i in map(int, input().split()):
    if i not in C:
        C[i] = 0
    C[i] += 1

for k in B:
    j = 0
    for i in B[k]:
        if i in C:
            j += C[i]
    B[k] = j

ans = 0
for k in A:
    if k in B:
        ans += A[k]*B[k]
print(ans)