# detail: https://atcoder.jp/contests/arc005/submissions/24601209
n=int(input())
ts=["TAKAHASHIKUN","Takahashikun","takahashikun"]

ss=list(input().split())
ss[-1]=ss[-1][:-1]
ans=0
for i in range(n):
  for t in ts:
    if ss[i]==t:
      ans+=1
      
print(ans)