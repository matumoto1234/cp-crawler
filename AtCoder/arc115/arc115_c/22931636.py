# detail: https://atcoder.jp/contests/arc115/submissions/22931636
n = int(input())
sieve = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
  for j in range(i, n + 1, i):
    sieve[j] += 1

ans = []
for i in range(1, n + 1):
  ans.append(sieve[i])
  
for i in range(0, n):
  print(ans[i], end=" ")
print()