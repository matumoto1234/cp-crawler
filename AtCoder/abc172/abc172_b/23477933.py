# detail: https://atcoder.jp/contests/abc172/submissions/23477933
s=input()
t=input()
ans=0
for i in range(len(s)):
  if s[i]!=t[i]:
    ans+=1
print(ans)