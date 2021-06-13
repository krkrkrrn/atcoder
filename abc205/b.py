N = int(input())
formula = list(map(int, input().split()))
if set(range(1, N+1)) - set(formula):
    print("No")
else:
    print("Yes")