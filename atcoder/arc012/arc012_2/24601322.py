# detail: https://atcoder.jp/contests/arc012/submissions/24601322
n,a,b,l=map(int,input().split())

for i in range(n):
  l*=b/a
  
print(l)