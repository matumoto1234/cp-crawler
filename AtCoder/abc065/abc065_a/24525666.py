# detail: https://atcoder.jp/contests/abc065/submissions/24525666
x,a,b=map(int,input().split())

a,b,x
if a>=b:
  print("delicious")
elif b<=a+x:
  print("safe")
else:
  print("dangerous")