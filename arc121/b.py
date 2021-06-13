N = int(input())
RGB = [0b001, 0b010, 0b100]
R_count, G_count, B_count = 0, 0, 0
dogs = dict()
for _ in range(2*N):
    a, c = input().split()
    a = int(a)-1
    if a not in dogs:
        dogs[a] = 0
    if c == 'R':
        dogs[a] |= RGB[0]
        R_count += 1
    elif c == 'G':
        G_count += 1
        dogs[a] |= RGB[1]
    else:
        B_count += 1
        dogs[a] |= RGB[2]

if R_count%2 == 0 and G_count%2 == 0 and B_count%2 == 0:
    print(0)
    exit()
elif R_count%2 == 0:
    del RGB[0]
elif G_count%2 == 0:
    del RGB[1]
else:
    del RGB[2]

ans = 10**15
diff = 0
pre_color = 0b000
dogs = sorted(dogs.items())
for k, v in dogs:
    # print(k)
    # print(v)
    if v & RGB[0] or v & RGB[1]:
        if v & RGB[0] and v & RGB[1]:
            ans = 0
            break
        else:
            if (pre_color & RGB[0] or pre_color & RGB[1]) and not v & pre_color:
                j = k-diff
                if ans > j:
                    ans = j
            pre_color = v
            diff = k
print(ans)
