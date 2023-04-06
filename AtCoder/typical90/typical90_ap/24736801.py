# detail: https://atcoder.jp/contests/typical90/submissions/24736801
k=int(input())
ans=0
mod=10**9+7
for i in range(0,10000000,9):
  if i%9==k%9:
    ans+=1
    ans%=mod
    
print(ans)