# detail: https://atcoder.jp/contests/arc105/submissions/22242009
import math

n = int(input())

vs =list(map(int,input().split()))

ans = vs[0]
for i in range(n):
  if i == 0:
    continue
  ans = math.gcd(ans, vs[i])

print(ans)