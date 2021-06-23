# detail: https://atcoder.jp/contests/abc065/submissions/23698590
x,a,b=map(int,input().split())

if b<=a:
  print('delicious')
elif b<=a+x:
  print('safe')
else:
  print('dangerous')
