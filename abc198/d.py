import itertools
S = [str(input()) for _ in range(3)]

# print(S)



dict_char = {}
for S_x in S:
    for s in list(S_x):
        dict_char[s] = 0
        # print(s)

def to_number(s, i):
    if len(s) <= i:
        return ""
    else:
        return str(dict_char[s[i]]) + to_number(s, i + 1)

if len(dict_char) > 10:
    print("UNSOLABLE")
    exit()

for comb in itertools.permutations(range(9), len(dict_char)):
    for n in comb:
        

print(len(dict_char))


print(to_number(S[0], 0))