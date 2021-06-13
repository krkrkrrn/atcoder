# https://atcoder.jp/contests/arc118/submissions/22249102
import numpy as np

K, N, M = map(int, input().split())
A = np.array(input().split(), np.int64)

B = A*M//N
C = B*N-A*M
n = M - np.sum(B)

ids = np.argpartition(C, n)[:n]
B[ids] += 1

print(*B)