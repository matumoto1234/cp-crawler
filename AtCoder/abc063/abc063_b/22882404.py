# detail: https://atcoder.jp/contests/abc063/submissions/22882404
from collections import Counter

s = input()
cnt = Counter(s)

ans = "yes"
for v in cnt.values():
  if v > 1:
    ans = "no"

print(ans)