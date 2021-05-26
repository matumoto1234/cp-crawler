# detail: https://atcoder.jp/contests/abc178/submissions/22928200
mod = 1000000000 + 7
n = int(input())
ans = 1
for i in range(1,n+1):
  ans *= i
  ans %= mod

ans *= pow(10,n-2,mod)

if n == 1:
  ans = 0
print(ans)