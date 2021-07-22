# detail: https://atcoder.jp/contests/abc073/submissions/24448875
n=int(input())
ans=0
for i in range(n):
  l,r=map(int,input().split())
  ans+=r-l+1
  
print(ans)