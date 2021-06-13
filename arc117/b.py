N = int(input())
A = list(map(int, input().split()))

a_list = list(set(A))
a_list.sort()
diff = 0
ans = 1
con = 1000000007
for a in a_list:
    ans = (ans * (a - diff + 1)) % con
    diff = a
print(ans)