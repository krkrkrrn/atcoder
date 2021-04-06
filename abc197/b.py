H, W, X, Y = map(int, input().split())
X -= 1
Y -= 1
ans = 1
rows = [(list(input())) for _ in range(H)]
# print(range(Y+1, W))
# print(rows)
# print("{}{}{}{}".format(H, W, X, Y))
for x in range(Y+1, W):
    if rows[X][x] == "#":
        break
    ans += 1
for x in range(Y-1, -1, -1):
    if rows[X][x] == "#":
        break
    ans += 1
for y in range(X+1, H):
    if rows[y][Y] == "#":
        break
    ans += 1
for y in range(X-1, -1, -1):
    if rows[y][Y] == "#":
        break
    ans += 1
print(ans)
