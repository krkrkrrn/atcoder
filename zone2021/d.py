from collections import deque

S = list(input())
ans = deque()
flipped = False

for s in S:
    if s == "R":
        flipped = not flipped
    elif flipped:
        if ans[0] == s:
            ans.popleft()
        else:
            ans.appendleft(s)
    else:
        if ans[-1] == s:
            ans.pop()
        else:
            ans.append(s)

print(ans)