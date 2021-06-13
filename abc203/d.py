N, K = map(int, input().split())
park = [list(map(int, input().split())) for _ in range(N)]
park_all = []
for l in park:
    park_all += l
park_sort = sorted(park_all)
center_min = (K**2)//2+1
for center_index in range(center_min, N):
    center = park_sort[center_index]
    for y, height_row in enumerate(park):
        for x, height in enumerate(height_row):
            if height == center:
                
                
                
                
    