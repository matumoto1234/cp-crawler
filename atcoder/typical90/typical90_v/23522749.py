# detail: https://atcoder.jp/contests/typical90/submissions/23522749
import math

a,b,c=map(int,input().split())
d=math.gcd(a,math.gcd(b,c))
print(a//d-1 + b//d-1 + c//d-1)