N, K = map(int, input().split())
friends = [tuple(map(int, input().split())) for _ in range(N)]
friends = sorted(friends)

money = K
for vilage, atm in friends:
    if vilage > money:
        break
    else:
        money += atm
print(money)