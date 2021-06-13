N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

if sum(A) != sum(B):
    print(-1)
    exit()
all_equal = True
for i in range(N):
    if A[i] != B[i]:
        all_equal = False
if all_equal:
    print(0)
    exit()

ans = 0
for i in range(N):
    if A[i] == B[i]:
        continue
    for j in range(i+1, N):
        # print("i: {}, j:{}".format(i,j))
        # print("A[j]-j+i: {}, B[i]:{}".format(A[j]-j+i,B[i]))
        if A[j]+j-i == B[i]:
            for k in range(j, i, -1):
                A[k] = A[k-1]-1
            A[i]=B[i]
            ans += j-i
            break
if ans == 0:
    print(-1)
    exit()
print(ans)