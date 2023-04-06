# detail: https://atcoder.jp/contests/arc017/submissions/23175943
n=int(input())
ans=True
for i in range(2,n):
  if n%i==0:
    ans=False
    break
if ans:
  print("YES")
else:
  print("NO")