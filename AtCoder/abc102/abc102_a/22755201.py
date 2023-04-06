# detail: https://atcoder.jp/contests/abc102/submissions/22755201
import math

def lcm(x, y):
  return x * y // math.gcd(x, y)

n = int(input())
print(lcm(2, n))