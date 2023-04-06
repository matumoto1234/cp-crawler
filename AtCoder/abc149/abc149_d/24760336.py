# detail: https://atcoder.jp/contests/abc149/submissions/24760336
n,k=map(int,input().split())
r,s,p=map(int,input().split())
t=input()

used = ['z' for _ in range(n)]
ans=0

for i in range(n):
  if t[i]=='r':
    if i-k>=0 and used[i-k]=='p':
      continue
    ans+=p
    used[i]='p'
  if t[i]=='s':
    if i-k>=0 and used[i-k]=='r':
      continue
    ans+=r
    used[i]='r'
  if t[i]=='p':
    if i-k>=0 and used[i-k]=='s':
      continue
    ans+=s
    used[i]='s'

#print(used)
print(ans)