# detail: https://atcoder.jp/contests/abc063/submissions/22881747
from collections import Counter
s = input()

cnt = Counter(s)

ans = True
for v in cnt.values():
  if v > 1:
    ans = False

if ans == True:
  print("yes")
else:
  print("no")