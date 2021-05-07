# detail: https://atcoder.jp/contests/abc188/submissions/22365994
x, y = map(int,input().split())

if max(x,y) - min(x,y) < 3:
  print("Yes")
else:
  print("No")