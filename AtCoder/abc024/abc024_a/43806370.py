# detail: https://atcoder.jp/contests/abc024/submissions/43806370
a,b,c,k = map(int,input().split())
s,t = map(int,input().split())

sum = 0
sum += a*s + b*t

if s+t >= k:
  sum -= (s+t)*c
  
print(sum)