# detail: https://atcoder.jp/contests/abc144/submissions/30339721
a,b = map(int,input().split())
if a >= 10 or b >= 10:
  print(-1)
else:
  print(a*b)
