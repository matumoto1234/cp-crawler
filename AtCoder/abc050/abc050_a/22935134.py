# detail: https://atcoder.jp/contests/abc050/submissions/22935134
a,op,b = input().split()
A = map(int,a)
B = map(int,b)
if op == '+':
  print(A+B)
else:
  print(A-B)