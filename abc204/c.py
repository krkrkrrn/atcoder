N, M = map(int, input().split())
road_to = set()
for _ in range(M):
    a, b = map(int, input().split())
    road_to.add(b)

print(N+(N-len(set(range(1,N+1))-road_to))*(N-1))
