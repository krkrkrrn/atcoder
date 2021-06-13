MOD = 10**9+7
N = int(input())
numbers = list(map(int, input().split()))
formula_sum = list()
# ans = 0
# start = 0
# for bit_digit in range(N-2):
#     for bit in range(start, 2**bit_digit+2**(bit_digit+1)):
#         s = numbers[0]
#         for i in range(N-1):
#             if i > 0 and (bit & (1<<(i-1))) and (bit & (1<<i)):
#                 s = 0
#                 break
#             if bit & (1<<i):
#                 s -= numbers[i+1]
#             else:
#                 s += numbers[i+1]
#         ans += s%MOD
#         # print(s%MOD, file=open("output.txt", "a"))
#         # formula_sum.append(s%MOD)
#     start = 2**(bit_digit+2)
# print(ans%MOD)
fibonaci = [0, 1]
for i in range(2, N+1):
    fibonaci.append(fibonaci[i-2]+fibonaci[i-1])
print(fibonaci[N])

for bit in range(2**(N-1)):
    s = numbers[0]
    for i in range(N-1):
        if i > 0 and (bit & (1<<(i-1))) and (bit & (1<<i)):
            s = 0
            break
        if bit & (1<<i):
            s -= numbers[i+1]
        else:
            s += numbers[i+1]
    print(s, file=open("output.txt", "a"))
    formula_sum.append(s)
print("ans: {}".format(sum(formula_sum)), file=open("output.txt", "a"))
print(sum(formula_sum))