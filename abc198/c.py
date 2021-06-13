import math
R, X, Y = map(int, input().split())
L = math.sqrt(math.pow(X, 2) + math.pow(Y, 2))
if L / R < 1:
    print(2)
elif L % R == 0:
    print(math.floor(L / R))
else:
    print(math.floor(L / R) + 1)