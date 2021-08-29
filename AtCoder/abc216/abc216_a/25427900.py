# detail: https://atcoder.jp/contests/abc216/submissions/25427900
x,y=map(int,input().split('.'))

if y<=2:
  print(x,"-",sep="")
elif y<=6:
  print(x,sep="")
else:
  print(x,"+",sep="")
  
