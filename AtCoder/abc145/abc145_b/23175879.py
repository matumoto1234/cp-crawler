# detail: https://atcoder.jp/contests/abc145/submissions/23175879
n=int(input())
s=input()
ans=True
if n%2==1:
  ans=False

for i in range(n//2):
  if s[i]!=s[i+n//2]:
    ans=False

if ans:
  print("Yes")
else:
  print("No")