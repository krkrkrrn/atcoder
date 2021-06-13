N, Q = map(int, input().split())
formula = list(map(int, input().split()))
query = [(int(input()), i) for i in range(Q)]
query = sorted(query)
# print(query)
count_excluded = 0
ans = []
for k, i in query:
    while(count_excluded < N and formula[count_excluded] <= k+count_excluded):
        count_excluded += 1
    ans.append((i, k+count_excluded))
    
for i, answer in sorted(ans):
    print(answer)