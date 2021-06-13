# https://atcoder.jp/contests/abc201/submissions/22637683
# これを参考にしたい。
import math
S = list(str(input()))
num_o = S.count('o')
num_x = S.count('x')
num_q = S.count('?')
# for i, s in enumerate(S):
#     if s == 'o':
#         str_o.append(i)
#     elif s == 'x':
#         str_x.append(i)
#     elif s == '?':
#         str_q.append(i)

ans = 0
if num_o > 4:
    ans = 0
elif num_o == 4:
    # math.factorial(4)
    ans = 24
elif num_o == 3:
    math.factorial(4)
    ans = 36+24*num_q
elif num_o == 2:
    ans = (num_o+num_q)**4-num_q**4
print(ans)
