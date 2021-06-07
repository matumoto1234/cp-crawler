# detail: https://atcoder.jp/contests/abc112/submissions/23273852
n,t=map(int,input().split())
ans=10**10
for i in range(n):
  c,t2=map(int,input().split())
  if t2<=t:
    ans=min(ans,c)
    
print(ans if ans!=10**10 else 'TLE')