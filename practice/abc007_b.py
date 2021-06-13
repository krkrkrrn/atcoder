# https://atcoder.jp/contests/abc007/tasks/abc007_2
a = input()
s = -1
if len(a) > 1:
    s = a[0:-1]
else:
    if a != "a":
        s = "a"
print(s)