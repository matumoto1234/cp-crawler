# detail: https://atcoder.jp/contests/abc197/submissions/23267986
n=int(input())
a=list(map(int,input().split()))

ans=10**18
for i in range(2**(n-1)):
  temp=0
  s=0
  for j in range(n):
    temp|=a[j]
    if (i>>j)&1:
      s^=temp
      temp=0
  s^=temp
  ans=min(ans,s)

print(ans)