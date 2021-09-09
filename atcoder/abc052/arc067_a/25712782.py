# detail: https://atcoder.jp/contests/abc052/submissions/25712782
from collections import Counter
def factorize(n):
  x=n
  i=2
  ps=[]
  while i*i<=n:
    while x%i==0:
      ps.append(i)
      x//=i
  if x!=1:
    ps.append(x)
  return ps

mod=10**9+7
n=int(input())
ps=[{} for _ in range(n+1)]
for i in range(2,n+1):
  ps[n][i]=0

for i in range(2,n+1):
  newps=Counter(factorize(i))
  for p in newps:
    ps[i][p]=newps[p]
    
for i in range(2,n):
  for p in ps[i]:
    ps[n][p]+=ps[i][p]
    
ans=1
for cnt in ps[n].values():
  ans*=cnt+1
  ans%=mod
  
print(ans)