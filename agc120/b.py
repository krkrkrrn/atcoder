mod = 998244353

H, W = map(int, input().split())
S = [list(input()) for i in range(H)]
ans = 1

for d in range(H+W-1):
    count_white = 0
    count_all = 0
    flg_red = False
    flg_blue = False
    for h in range(d+1):
        w = d-h
        if h >= H or w >= W:
            continue
        # print("h: {}, w: {}".format(h, w))
        count_all += 1
        if S[h][w] == '.':
            count_white += 1
        elif S[h][w] == 'R':
            flg_red = True
        elif S[h][w] == 'B':
            flg_blue = True
    if flg_blue and flg_red:
        print(0)
        exit()
    else:
        if count_white == count_all:
            ans = ans*2%mod
print(ans)

