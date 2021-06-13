N = int(input())
ts = dict()
t_sort = list()
for _ in range(N):
    s, t = input().split()
    ts[int(t)] = s
    t_sort.append(int(t))

t_sort = sorted(t_sort, reverse=True)
print(ts[t_sort[1]])