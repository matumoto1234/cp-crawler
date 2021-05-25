# detail: https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/22920076
n,k=map(int,input().split())
k-=1
if k*2+1<=n:
  print("YES")
else:
  print("NO")