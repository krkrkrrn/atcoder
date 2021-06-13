N = int(input())
S = input()
A = list(map(int, input().split()))
a_min = min(A)
ans = 0

def judge(s, a, b):
    if s == "<":
        return 1
    else:
        return -1

def again(s, i, k):
    global ans
    if i == N:
        if ans < k:
            ans = k
        return
    if not judge(s, A[i], A[i+1]):
        return
    for i_k in range(1, A[i] - a_min + 1):

def hoge(sum, n):
    for i in range(n):

print(not judge(">", 2, 4))