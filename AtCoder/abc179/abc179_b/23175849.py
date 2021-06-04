# detail: https://atcoder.jp/contests/abc179/submissions/23175849
n=int(input())
d=[list(map(int,input().split())) for _ in range(n)]

ans=False
for i in range(2,n):
  cnt=[0 for _ in range(6)]
  for j in range(3):
    if d[i-j][0]==d[i-j][1]:
      cnt[d[i-j][0]-1]+=1
      
  sum=0
  for j in range(6):
    sum+=cnt[j]
  if sum>=3:
    ans=True
    
if ans:
  print("Yes")
else:
  print("No")