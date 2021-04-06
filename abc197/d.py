import numpy as np
import math
N = int(input())
x_0, y_0 = map(int, input().split())
x_2, y_2 = map(int, input().split())
# 回転の公式
# (x-a, y-b) = ((cosθ, -sinθ), (sinθ, cosθ)) (x-a, y-b)
# 中心を求める
x_center = (x_0 + x_2) / 2
y_center = (y_0 + y_2) / 2
rad = math.pi / (N / 2)
ans = \
np.array([[math.cos(rad), -math.sin(rad)], \
[math.sin(rad), math.cos(rad)]]) @ \
np.array([[x_0 - x_center], [y_0 - y_center]]) + \
np.array([[x_center], [y_center]])

print("{} {}".format(ans[0][0], ans[1][0]))
