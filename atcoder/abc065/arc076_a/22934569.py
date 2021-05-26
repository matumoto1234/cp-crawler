# detail: https://atcoder.jp/contests/abc065/submissions/22934569
import math
mod = 10**9+7

def fact(n):
  if n <= 1:
    return 1
  else:
    return fact(n-1) * n % mod

a,b = map(int,input().split())
if math.abs(a-b)>2:
  print(0)
else:
  print(fact(a) * fact(b) % mod)