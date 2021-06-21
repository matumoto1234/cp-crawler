# detail: https://atcoder.jp/contests/abc063/submissions/23663293
from collections import Counter
s=input()
cnt = Counter(s)

ans=True

for v in cnt.values():
  if v>1:
    ans=False
    
print('yes' if ans else 'no')