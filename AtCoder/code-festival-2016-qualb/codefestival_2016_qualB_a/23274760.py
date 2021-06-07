# detail: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/23274760
s=input()
t='CODEFESTIVAL2016'
ans=0
for i in range(len(s)):
  if s[i]!=t[i]:
    ans+=1
    
print(ans)