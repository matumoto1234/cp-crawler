# detail: https://atcoder.jp/contests/arc117/submissions/23191326
n=int(input())
a=list(map(int,input().split()))

a.append(0)
a.sort()
mod=10**9+7

ans=1
for i in range(1,len(a)):
  ans*=a[i]-a[i-1]+1
  ans%=mod
  
print(ans)