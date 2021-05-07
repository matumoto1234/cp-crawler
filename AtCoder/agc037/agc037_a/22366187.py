# detail: https://atcoder.jp/contests/agc037/submissions/22366187
s = input()

pre = ""
now = ""
ans = 0
for i in range(len(s)):
  now += s[i]
  if pre != now:
    ans += 1
    pre = now
    now = ""

print(ans)