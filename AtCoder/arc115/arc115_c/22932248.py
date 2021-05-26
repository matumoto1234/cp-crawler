# detail: https://atcoder.jp/contests/arc115/submissions/22932248
n = int(input())
sieve = [0 for _ in range(n + 1)]
for i in range(2, n + 1):
  if sieve[i] != 0:
    continue
  for j in range(i, n + 1, i):
    if sieve[j] == 0:
      sieve[j] = i

ans = [1]
sieve[1] = 1
for i in range(2, n + 1):
  v = i
  # print(v//sieve[v])
  ans.append(ans[v // sieve[v] - 1] + 1)

for i in range(n):
  print(ans[i], end=" ")
print()