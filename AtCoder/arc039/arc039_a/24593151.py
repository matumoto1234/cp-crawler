# detail: https://atcoder.jp/contests/arc039/submissions/24593151
a,b=input().split()
a=list(a)
b=list(b)
ans=-10**9
for i in range(3):
  tmp="9"
  a[i],tmp=tmp,a[i]
  ans=max(ans,int("".join(a))-int("".join(b)))
  a[i],tmp=tmp,a[i]
  
for i in range(3):
  tmp="0"
  if i==0:
    tmp="1"
  b[i],tmp=tmp,b[i]
  ans=max(ans,int("".join(a))-int("".join(b)))
  b[i],tmp=tmp,b[i]
  
print(ans)