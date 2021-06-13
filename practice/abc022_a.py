# https://atcoder.jp/contests/abc022/tasks/abc022_a
N, S, T = map(int, input().split())
weight = [int(input())]
for i in range(N-1):
    weight.append(weight[i]+int(input()))
# https://note.nkmk.me/python-collections-counter/
print(sum(S<=i and i<=T for i in weight))
