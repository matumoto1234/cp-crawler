# detail: https://atcoder.jp/contests/abc127/submissions/24578268
r,d,x=map(int,input().split())
for i in range(10):
  x=r*x-d
  print(x)