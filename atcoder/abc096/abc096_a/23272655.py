# detail: https://atcoder.jp/contests/abc096/submissions/23272655
a,b=map(int,input().split())
ms=[0 for _ in range(13)]
for i in range(1,12+1):
  if i<=7:
    if i%2:
      ms[i]=31
    elif i==2:
      ms[i]=28
    else:
      ms[i]=30
    continue
  if i%2==0:
    ms[i]=31
  else:
    ms[i]=30

ans=0
for m in range(1,12+1):
  if m>a:
    break
  for d in range(1,ms[m]+1):
    if m==d:
      ans+=1
    if m>=a and d>=b:
      break

print(ans)