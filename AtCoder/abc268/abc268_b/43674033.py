# detail: https://atcoder.jp/contests/abc268/submissions/43674033
s = input()
t = input()

ans = False
for i in range(len(t)):
  if t[:i+1] == s:
    ans = True
    break
    
print("Yes" if ans else "No")