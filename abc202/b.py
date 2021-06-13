s = list(input())
re_s = list(reversed(s))
ans = []
for i in re_s:
    if i == '6':
        ans.append('9')
    elif i == '9':
        ans.append('6')
    else:
        ans.append(i)
print("".join(ans))

# https://atcoder.jp/contests/abc202/submissions/22793538
# read = lambda: map(int, input().split())
# s = list(input()[::-1])
# for i in range(len(s)):
#     if s[i] == '6':
#         s[i] = '9'
#     elif s[i] == '9':
#         s[i] = '6'
# print(''.join(s))
