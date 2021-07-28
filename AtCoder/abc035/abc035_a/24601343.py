# detail: https://atcoder.jp/contests/abc035/submissions/24601343
import math

w,h=map(int,input().split())
d=math.gcd(w,h)
w//=d
h//=d
print(w,h,sep=":")