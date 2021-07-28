# detail: https://atcoder.jp/contests/code-festival-2014-final/submissions/24601250
s=input()
ans=0
for i in range(len(s)):
  v=int(s[i])
  if i%2==0:
    ans+=v
  else:
    ans-=v
    
print(ans)