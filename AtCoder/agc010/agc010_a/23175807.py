# detail: https://atcoder.jp/contests/agc010/submissions/23175807
n=int(input())
a=list(map(int,input().split()))

odd,even=0,0
for i in range(n):
  if a[i]%2==0:
    even+=1
  else:
    odd+=1
    
ans=False
if odd==0 or even==0:
  ans=True

if odd%2==0:
  ans=True

if ans:
  print("YES")
else:
  print("NO")