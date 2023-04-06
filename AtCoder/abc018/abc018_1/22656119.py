# detail: https://atcoder.jp/contests/abc018/submissions/22656119
a, b, c = map(int,input().split())
if(a > b && a > c):
  if(b > c) print(1, 2, 3)
  else print(1, 3, 2)
if(b > a && b > c):
  if(a > c) print(2, 1, 3)
  else print(3, 1, 2)
if(c > a && c > b):
  if(a > b) print(2, 3, 1)
  else print(3, 2, 1)