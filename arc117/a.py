A, B = map(int, input().split())

if A < B:
    b_ans = range(1, 1 + B)
    k = sum(b_ans)
    a_ans = list()
    for i in range(1, A):
       k = k - i
       a_ans.append(i)
    a_ans.append(k)
    # print(a_ans)
else:
    a_ans = range(1, 1 + A)
    k = sum(a_ans)
    b_ans = list()
    for i in range(1, B):
       k = k - i
       b_ans.append(i)
    b_ans.append(k)
    # print(b_ans)

b_ans = list(map(lambda x: -x, b_ans))

# print(" ".join(map(str, a_ans)))
# print(" ".join(map(str, b_ans)))

print(" ".join(map(str, a_ans)) + " " + " ".join(map(str, b_ans)))