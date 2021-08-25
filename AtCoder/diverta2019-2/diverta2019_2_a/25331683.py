# detail: https://atcoder.jp/contests/diverta2019-2/submissions/25331683
n,k=map(int,input().split())
if k==1:
  print(0)
  exit()
print(max(0,n-k))