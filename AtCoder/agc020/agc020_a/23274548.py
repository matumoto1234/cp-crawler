# detail: https://atcoder.jp/contests/agc020/submissions/23274548
n,a,b=map(int,input().split())
if abs(a-b)%2==1:
  print('Borys')
else:
  print('Alice')