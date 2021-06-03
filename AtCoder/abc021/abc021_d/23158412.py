# detail: https://atcoder.jp/contests/abc021/submissions/23158412
def mod_binomial(n,k,mod):
  res=1
  for i in range(1,k+1):
    res*=n-(i-1)
    res%=mod
    res*=pow(i,mod-2,mod)
    res%=mod
  return res

n,k=map(int,input().split())
print(mod_binomial(n+k-1,k-1,10**9_7))