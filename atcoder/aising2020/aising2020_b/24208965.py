# detail: https://atcoder.jp/contests/aising2020/submissions/24208965
n=int(input())
a=list(map(int,input().split()))

ans=0
for i in range(n):
  if a[i]%2==1 and i%2==0:
    ans+=1
    
print(ans)