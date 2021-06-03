# detail: https://atcoder.jp/contests/arc004/submissions/23158693
from collections import Counter
def mod_binomial(n,k,mod):
  res=1
  mother=1
  for i in range(1,k+1):
    res*=n-(i-1)
    res%=mod
    mother*=i
    mother%=mod
  return res*pow(mother,mod-2,mod)

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
ps=primefactor(abs(n))
mod=10**9+7
sum1=1
for cnt in ps.values():
  sum1*=mod_binomial(m+cnt-1,m-1,mod)
  sum1%=mod

sum2=pow(2,m-1,mod)
ans=(sum1*sum2)%mod
print(ans)