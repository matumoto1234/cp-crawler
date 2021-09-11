# detail: https://atcoder.jp/contests/abc072/submissions/25794150
n=int(input())
a=list(map(int,input().split()))

cnt=[0 for _ in range(10**6)]

for i in range(n):
  cnt[a[i]]+=1
  cnt[a[i]+1]+=1
  cnt[a[i]-1]+=1
  
ans=0
for i in range(200000):
  if ans<cnt[i]:
    ans=cnt[i]
               
print(ans)