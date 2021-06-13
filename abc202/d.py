import math
A, B, K = map(int, input().split())

ans = 0
U = math.factorial(A+B)//math.factorial(A)//math.factorial(B)
dp = [[0]*30]*30
# メモ化再帰でやってみる。
def Decide_AorB(n, left_a, left_b):
    global K, dp
    if dp[left_a][left_b] == 0:
        dp[left_a][left_b] = \
        math.factorial(left_a+left_b)\
        //math.factorial(left_a)//math.factorial(left_b)
    if n+dp[left_a][left_b] < K:
        return "b" + Decide_AorB(n+dp[left_a][left_b], left_a, left_b-1)
    elif n+dp[left_a][left_b] > K:
        return "a" + Decide_AorB(n, left_a-1, left_b)
    else:
        return "a"*left_a + "b"*left_b
print(Decide_AorB(0, A, B))
