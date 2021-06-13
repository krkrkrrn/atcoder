# https://atcoder.jp/contests/abc006/tasks/abc006_2
from typing import Sequence

n = int(input())

sequence = [0, 0, 1]

for i in range(3, n):
    sequence.append((sequence[i-3]+sequence[i-2]+sequence[i-1])%10007)

print(sequence[n-1])
