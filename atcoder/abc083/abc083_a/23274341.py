# detail: https://atcoder.jp/contests/abc083/submissions/23274341
a,b,c,d=map(int,input().split())
if a+b>c+d:
  print('Left')
elif a+b==c+d:
  print('Balanced')
else:
  print('Right')