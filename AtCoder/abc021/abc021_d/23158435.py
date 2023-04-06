# detail: https://atcoder.jp/contests/abc021/submissions/23158435
def mod_binomial(n,k,mod):
  res=1
  for i in range(1,k+1):
    res*=n-(i-1)
    res%=mod
    res*=pow(i,mod-2,mod)
    res%=mod
  return res

n=int(input())
k=int(input())
print(mod_binomial(n+k-1,k-1,10**9+7))