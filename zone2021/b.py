N, D, H = map(int, input().split())
angle = H/D
for _ in range(N):
    d, h = map(int, input().split())
    angle = min(angle, (H-h)/(D-d))

print(max(H-angle*D, 0))