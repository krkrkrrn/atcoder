x, y = map(int, input().split())
if x == y:
    print(x)
else:
    for i in range(3):
        if i != x and i != y:
            print(i)