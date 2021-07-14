# detail: https://atcoder.jp/contests/abc190/submissions/24212842
a,b,c=map(int,input().split())
ans=''
if c==0:
  if a<=b:
    ans='Aoki'
  else:
    ans='Takahashi'
else:
  if b<=a:
    ans='Takahashi'
  else:
    ans='Aoki'

print(ans)