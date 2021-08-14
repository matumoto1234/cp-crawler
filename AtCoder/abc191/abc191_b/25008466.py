# detail: https://atcoder.jp/contests/abc191/submissions/25008466
n,x=map(int,input().split())
a=list(map(int,input().split()))
ans=[]
for i in range(n):
  if a[i]==x:
    continue
  ans.append(a[i])
  
print(*ans)