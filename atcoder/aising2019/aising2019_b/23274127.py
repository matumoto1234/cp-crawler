# detail: https://atcoder.jp/contests/aising2019/submissions/23274127
n=int(input())
a,b=map(int,input().split())
p=list(map(int,input().split()))
cnt=[0 for _ in range(3)]
for i in range(n):
  if p[i]<=a:
    cnt[0]+=1
    
for i in range(n):
  if a<p[i]<=b:
    cnt[1]+=1
    
for i in range(n):
  if b<p[i]:
    cnt[2]+=1
    
print(min(cnt[0],cnt[1],cnt[2]))