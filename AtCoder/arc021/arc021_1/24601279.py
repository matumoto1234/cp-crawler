# detail: https://atcoder.jp/contests/arc021/submissions/24601279
a=[list(map(int,input().split())) for _ in range(4)]
ans=False
dy=[0,1,0,-1]
dx=[1,0,-1,0]
for i in range(4):
  for j in range(4):
    for k in range(4):
      ny=dy[k]+i
      nx=dx[k]+j
      if ny<0 or 4<=ny or nx<0 or 4<=nx:
        continue
      if a[i][j]==a[ny][nx]:
        ans=True

print("CONTINUE" if ans else "GAMEOVER")        