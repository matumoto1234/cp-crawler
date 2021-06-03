# detail: https://atcoder.jp/contests/arc004/submissions/23158630
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
ps=primefactor(abs(n))
mod=10**9+7
sum=1
for cnt in ps.values():
  sum*=mod_binomial(m+cnt-1,m-1,mod)
  # print(cnt,mod_binomial(m+cnt-1,m-1,mod))
  sum%=mod

# print(sum)

s=0
if n<0:
  s=1
sum2=0
#for i in range(s,m+1,2):
#  sum2+=mod_binomial(m,i,mod)
#  sum2%=mod
sum2=pow(2,m-1,mod)
sum%=mod
sum2%=mod
ans=(sum*sum2)%mod
print(ans)