# detail: https://atcoder.jp/contests/abc101/submissions/22932882
s = input()
ans = 0
for i in range(len(s)):
  if s[i] == '+':
    ans += 1
  else:
    ans -= 1

print(ans)