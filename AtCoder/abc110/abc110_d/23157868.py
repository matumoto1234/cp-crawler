# detail: https://atcoder.jp/contests/abc110/submissions/23157868
from collections import Counter
def mod_binomial(n,k,mod):
  res=1
  for i in range(1,k+1):
    res*=n-(i-1)
    res%=mod
    res*=pow(i,mod-2,mod)
    res%=mod
  return res

def primefactor(n):
  ps=[]
  i=2
  x=n
  while i*i<=n:
    while(x%i==0):
      ps.append(i)
      x//=i
    i+=1
  if x>1:
    ps.append(x)
  return Counter(ps)
  

# main

n,m=map(int,input().split())
ps=primefactor(m)
mod=10**9+7
ans=1
for cnt in ps.values():
  ans*=mod_binomial(n+cnt-1,n-1,mod)
  # print(cnt,mod_binomial(n+cnt-1,n-1,mod))
  ans%=mod

print(ans)