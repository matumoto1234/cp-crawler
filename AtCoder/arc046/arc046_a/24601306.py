# detail: https://atcoder.jp/contests/arc046/submissions/24601306
from collections import Counter
n=int(input())
for i in range(1,10**6):
  s=str(i)
  cnt=Counter(s)
  if len(cnt)==1:
    n-=1
    if n==0:
      print(i)
      exit()
    