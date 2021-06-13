N = int(input())
A = list(map(int, input().split()))
a_sum = 0
a_max = 0
a_tmp = 0

for i, a in enumerate(A):
    if a_max < a:
        a_max = a
    a_sum += a+a_tmp
    a_tmp += a
    print(a_sum+a_max*(i+1))