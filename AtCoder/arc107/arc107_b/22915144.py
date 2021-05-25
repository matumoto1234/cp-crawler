# detail: https://atcoder.jp/contests/arc107/submissions/22915144
def f(M,N):
  return min(M-1,N)-max(1,M-N)+1

n,k=map(int,input().split())
ans=0
for i in range(1,n+1):
  j=i-k;
  if 1<=j<=n:
    ans+=f(i,n)*f(j,n)

print(ans)