# detail: https://atcoder.jp/contests/abc199/submissions/23270322
n,m=map(int,input().split())

G=[[] for _ in range(n)]
used=[False for _ in range(n)]
vs=[]
def dfs1(idx):
  used[idx]=True
  vs.append(idx)
  for to in G[idx]:
    if used[to]:
      continue
    dfs1(to)

cols=[]
def dfs2(idx):
  if idx==len(vs):
    return 1
  res=0
  v=vs[idx]
  for col in range(3):
    valid=True
    for to in G[v]:
      if cols[to]==col:
        valid=False
        break
    if not valid:
      continue
    cols[v]=col
    res+=dfs2(idx+1)
  cols[v]=-1
  return res

for i in range(m):
  a,b=map(int,input().split())
  a-=1
  b-=1
  G[a].append(b)
  G[b].append(a)
  
ans=1
for i in range(n):
  if used[i]:
    continue
  vs=[]
  dfs1(i)
  cols=[-1 for _ in range(n)]
  cols[0]=0
  v=dfs2(1)
  ans*=3*v

print(ans)