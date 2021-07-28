# detail: https://atcoder.jp/contests/abc032/submissions/24601297
import math

a=int(input())
b=int(input())
n=int(input())

ans=a*b//math.gcd(a,b) 
ans=(n+ans-1)//ans*ans

print(ans)