# detail: https://atcoder.jp/contests/abc166/submissions/22530657
import collections
n = int(input())
a = list(map(int,input().split()))

b = []
for i in range(n):
  b.append(i-a[i])

c = []
for i in range(n):
  c.append(i+a[i])

cntb = collections.Counter(b)

ans = 0
for i in range(n):
  ans += cntb[c[i]]
print(ans)