N = int(input())

while N > 0 and (not N % 10) :
    N = N / 10
s = str(int(N))
s_re = "".join(list(reversed(s)))
if s == s_re:
    print("Yes")
else:
    print("No")
