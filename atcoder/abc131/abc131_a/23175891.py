# detail: https://atcoder.jp/contests/abc131/submissions/23175891
s=input()
ans=True
for i in range(1,4):
  if s[i-1]==s[i]:
    ans=False
    
if ans:
  print("Good")
else:
  print("Bad")