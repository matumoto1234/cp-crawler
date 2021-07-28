# detail: https://atcoder.jp/contests/arc034/submissions/24601336
n=int(input())
ans=0
for i in range(n):
  a,b,c,d,e=map(int,input().split())
  sum=a+b+c+d+(e*110/900)
  ans=max(ans,sum)
  
print(ans)