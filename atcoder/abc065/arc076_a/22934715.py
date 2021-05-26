# detail: https://atcoder.jp/contests/abc065/submissions/22934715
mod = 10**9+7

fact = [1 for _ in range(300000)]
for i in range(1, 300000):
  fact[i] = fact[i-1] * i % mod

a,b = map(int,input().split())
ans = 0
if abs(a-b)>1:
  ans = 0
elif a == b:
  ans = fact[a] * fact[b] % mod
  ans = ans * 2 % mod
else:
  ans = fact[a] * fact[b] % mod

print(ans)