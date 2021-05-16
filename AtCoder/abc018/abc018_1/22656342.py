# detail: https://atcoder.jp/contests/abc018/submissions/22656342
l = [int(input()) for _ in range(3)]
a = l[0]
b = l[1]
c = l[2]

if(a > b and a > c):
  if(b > c): print(1, 2, 3)
  else: print(1, 3, 2)
if(b > a and b > c):
  if(a > c): print(2, 1, 3)
  else: print(3, 1, 2)
if(c > a and c > b):
  if(a > b): print(2, 3, 1)
  else: print(3, 2, 1)