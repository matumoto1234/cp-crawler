# detail: https://atcoder.jp/contests/apc001/submissions/22931139
import math
x, y = map(int,input().split())
if math.gcd(x, y) == y:
  print(-1)
else:
  print(x)