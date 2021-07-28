# detail: https://atcoder.jp/contests/arc008/submissions/24601357
n=int(input())

ans=10**9
for i in range(6):
  sum=i*100
  cnt=i*10
  if cnt<n:
    sum+=(n-cnt)*15
  ans=min(ans,sum)
  
print(ans)