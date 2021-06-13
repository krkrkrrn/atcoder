# https://atcoder.jp/contests/abc008/tasks/abc008_2
N = int(input())
votes = dict()
for _ in range(N):
    name = input()
    if name not in votes:
        votes[name] = 0
    votes[name] += 1
# https://note.nkmk.me/python-key-sort-sorted-max-min/
print(max(votes, key=votes.get))