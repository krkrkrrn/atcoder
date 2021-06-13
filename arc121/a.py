N = int(input())
x, y = list(), list()
for i in range(N):
    a, b = map(int, input().split())
    x.append([a, i])
    y.append([b, i])
x = sorted(x)
y = sorted(y)
candidate = []
candidate.append([abs(x[0][0]-x[-1][0]), x[0][1], x[-1][1]])
candidate.append([abs(x[1][0]-x[-1][0]), x[1][1], x[-1][1]])
candidate.append([abs(x[0][0]-x[-2][0]), x[0][1], x[-2][1]])
candidate.append([abs(y[0][0]-y[-1][0]), y[0][1], y[-1][1]])
candidate.append([abs(y[1][0]-y[-1][0]), y[1][1], y[-1][1]])
candidate.append([abs(y[0][0]-y[-2][0]), y[0][1], y[-2][1]])
candidate = sorted(candidate, reverse=True)
if candidate[0][1] == candidate[1][1] and candidate[0][2] == candidate[1][2]:
    print(candidate[2][0])
else:
    print(int(candidate[1][0]))