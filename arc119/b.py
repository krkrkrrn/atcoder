N = int(input())
S = input()
T = input()

if not S.count('1') == T.count('1'):
    print(-1)
    exit()

s_0 = list()
t_0 = list()

for i in range(N):
    if S[i] == '0':
        s_0.append(i)
    if T[i] == '0':
        t_0.append(i)
ans = 0
for i in range(len(s_0)):
    if s_0[i] != t_0[i]:
        ans += 1

print(ans)

