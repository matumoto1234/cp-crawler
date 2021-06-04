# detail: https://atcoder.jp/contests/abc190/submissions/23175872
n,s,d=map(int,input().split())
vs=[list(map(int,input().split())) for _ in range(n)]
ans=False
for i in range(n):
  if vs[i][0]<s and vs[i][1]>d:
    ans=True
    
if ans:
  print("Yes")
else:
  print("No")