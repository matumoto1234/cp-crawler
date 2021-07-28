# detail: https://atcoder.jp/contests/abc017/submissions/24591167
s=input()
s=s[::-1]
"hc","o","u","k"
ans=True
for i in range(len(s)):
  if i >= len(s):
    break
  if s[i]=="o" or s[i]=="u" or s[i]=="k":
    continue
  #print(s[i])
  if i+1<len(s) and s[i]=="h" and s[i+1]=="c":
    s=s[:i+1]+s[i+2:]
    continue
    
  ans=False
  
print("YES" if ans else "NO")