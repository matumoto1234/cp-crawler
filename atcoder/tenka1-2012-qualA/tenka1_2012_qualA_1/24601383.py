# detail: https://atcoder.jp/contests/tenka1-2012-qualA/submissions/24601383
n=int(input())
a=[0 for _ in range(50)]
a[0]=1

for i in range(1,n+1):
  for j in range(0,i-2+1):
    a[i]+=a[j]
    
ans=0
for i in range(n+1):
  ans+=a[i]
print(ans)