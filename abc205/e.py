import sys
sys.setrecursionlimit(10000)

N, M, K = map(int, input().split())
memo = dict()

def search(i, w, b):
    # if i in memo and k in memo[i]:
    #     return memo[i][k]
    if w > N or b > M or w-b > K:
        return 0
    if i == N+M:
        return 1
    else:
        return search(i+1, w+1, b)+search(i+1, w, b+1)
print(search(0, 0, 0))