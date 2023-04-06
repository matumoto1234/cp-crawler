# detail: https://atcoder.jp/contests/arc004/submissions/23158668
from collections import Counter
n = 10 ** 9
k = 2 * 10 ** 5
mod = 10**9 + 7
 
# x ** a をmodで割った余りを、O(log(a))時間で求める。
def power(x, a):
    if a == 0:
        return 1
    elif a == 1:
        return x
    elif a % 2 == 0:
        return power(x, a//2) **2 % mod
    else:
        return power(x, a//2) **2 * x % mod
 
# xの逆元を求める。フェルマーの小定理より、 x の逆元は x ^ (mod - 2) に等しい。計算時間はO(log(mod))程度。
# https://qiita.com/Yaruki00/items/fd1fc269ff7fe40d09a6
def modinv(x):
    return power(x, mod-2)
 
def binomial_coefficients(n, k):
    numera = 1  # 分子
    denomi = 1  # 分母
 
    for i in range(k):
        numera *= n-i
        numera %= mod
        denomi *= i+1
        denomi %= mod
    return numera * modinv(denomi) % mod

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
  sum1*=binomial_coefficients(m+cnt-1,m-1)
  sum1%=mod

sum2=pow(2,m-1,mod)
ans=(sum1*sum2)%mod
print(ans)