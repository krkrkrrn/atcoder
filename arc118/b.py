K, N, M = map(int, input().split())
A = list(map(int, input().split()))
int_B = list(map(lambda a: a*M//N, A))
# print(decimal_B)
sort_B = list()
for i, a in enumerate(A):
    sort_B.append([a*M-int_B[i]*N, i])
# print(div_B)
diff_int = M - sum(int_B)
for i, j in enumerate(sorted(sort_B, key=lambda i: i[0], reverse=True)):
    if i < diff_int:
        int_B[j[1]] += 1
    else:
        break
print(" ".join(map(str, int_B)))