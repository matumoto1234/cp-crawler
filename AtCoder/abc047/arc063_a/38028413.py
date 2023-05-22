# detail: https://atcoder.jp/contests/abc047/submissions/38028413
s = input()
last = s[0]
diff = 0
for i in range(len(s)):
  if last != s[i]:
    diff+=1
  last = s[i]
  
print(diff)