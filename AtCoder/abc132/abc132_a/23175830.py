# detail: https://atcoder.jp/contests/abc132/submissions/23175830
from collections import Counter
s=input()
cnt=Counter(s)
ans=True
if len(cnt.keys())!=2:
  ans=False
  
for val in cnt.values():
  if int(val) != 2:
    ans=False

if ans:
  print("Yes")
else:
  print("No")